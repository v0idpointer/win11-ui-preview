#include "window.h"
#include "../controls/controls.h"

CWindow::CWindow(HINSTANCE* pInstanceHandle) : m_pInstanceHandle(pInstanceHandle) {

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = *pInstanceHandle;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(240, 240, 240));
	wc.lpszMenuName = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = this->m_lpcwszClassName;
	wc.lpfnWndProc = CWindow::WindowProc;
	wc.style = (CS_OWNDC | CS_VREDRAW | CS_HREDRAW);

	RegisterClassExW(&wc);

	this->m_hWnd = CreateWindowExW(0, this->m_lpcwszClassName, this->m_lpcwszWindowName, this->m_dwWindowStyle, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, *this->m_pInstanceHandle, 0);

	this->m_hMenubar = CreateMenu();
	this->m_hMenuSuperbar = CreateMenu();
	this->m_hMenuFile = CreateMenu();

	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_RESET, L"Reset Superbar");
	AppendMenuW(this->m_hMenuSuperbar, MF_SEPARATOR, (unsigned int)0, L"");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_STAGE1, L"Set 25%");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_STAGE2, L"Set 50%");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_STAGE3, L"Set 75%");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_STAGE4, L"Set 100%");
	AppendMenuW(this->m_hMenuSuperbar, MF_SEPARATOR, (unsigned int)0, L"");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_NORMAL, L"Set Normal");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_PAUSED, L"Set Paused");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_ERROR, L"Set Error");
	AppendMenuW(this->m_hMenuSuperbar, MF_STRING, (unsigned int)IDM_SUPERBAR_LOOP, L"Set Loop");

	AppendMenuW(this->m_hMenuFile, MF_STRING, (unsigned int)IDM_FILE_EXIT, L"Exit");

	AppendMenuW(this->m_hMenubar, MF_POPUP, (unsigned int)this->m_hMenuFile, L"File");
	AppendMenuW(this->m_hMenubar, MF_POPUP, (unsigned int)this->m_hMenuSuperbar, L"Superbar");
	AppendMenuW(this->m_hMenubar, MF_STRING, (unsigned int)0x0009, L"About");
	
	SetMenu(this->m_hWnd, this->m_hMenubar);

}

CWindow::~CWindow() {

	DestroyMenu(this->m_hMenuFile);
	DestroyMenu(this->m_hMenuSuperbar);
	DestroyMenu(this->m_hMenubar);

	DestroyWindow(this->m_hWnd);
	UnregisterClassW(this->m_lpcwszClassName, *this->m_pInstanceHandle);

}

HINSTANCE* CWindow::GetInstanceHandle() {
	return this->m_pInstanceHandle;
}

HWND* CWindow::GetWindowHandle() {
	return &this->m_hWnd;
}

void CWindow::HandleMessages() {
	MSG msg;

	if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	if (msg.message == WM_QUIT) this->m_bWindowShouldClose = true;
}

bool CWindow::WindowShouldClose() {
	return this->m_bWindowShouldClose;
}