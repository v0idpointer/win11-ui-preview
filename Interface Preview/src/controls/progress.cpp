#include "controls.h"

void CWindowControls::InitializeProgressbar() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndProgressbar = CreateWindowExW(0, PROGRESS_CLASSW, L"", WS_CHILD | WS_VISIBLE, 16, 168, 256, 24, hWnd, NULL, hInstance, 0);
	this->m_hWndProgressMinus = CreateWindowExW(0, WC_BUTTONW, L"-", WS_CHILD | WS_VISIBLE | BS_TEXT, 16, 192, 64, 24, hWnd, (HMENU)IDM_CTRL_PROGRESS_SUB, hInstance, 0);
	this->m_hWndProgressPlus = CreateWindowExW(0, WC_BUTTONW, L"+", WS_CHILD | WS_VISIBLE | BS_TEXT, 80, 192, 64, 24, hWnd, (HMENU)IDM_CTRL_PROGRESS_ADD, hInstance, 0);
	this->m_hWndProgressClear = CreateWindowExW(0, WC_BUTTONW, L"Clear", WS_CHILD | WS_VISIBLE | BS_TEXT, 144, 192, 64, 24, hWnd, (HMENU)IDM_CTRL_PROGRESS_STR, hInstance, 0);
	this->m_hWndProgressFinish = CreateWindowExW(0, WC_BUTTONW, L"Finish", WS_CHILD | WS_VISIBLE | BS_TEXT, 208, 192, 64, 24, hWnd, (HMENU)IDM_CTRL_PROGRESS_FNS, hInstance, 0);

	SendMessageW(this->m_hWndProgressbar, PBM_SETPOS, (WPARAM)20, (LPARAM)0);

	this->m_hWndSecondProgressbar = CreateWindowExW(0, PROGRESS_CLASSW, L"", WS_CHILD | WS_VISIBLE, 288, 168, 256, 24, hWnd, NULL, hInstance, 0);

}

void CWindowControls::DestroyProgressbar() {
	DestroyWindow(this->m_hWndProgressbar);
	DestroyWindow(this->m_hWndProgressMinus);
	DestroyWindow(this->m_hWndProgressPlus);
	DestroyWindow(this->m_hWndProgressClear);
	DestroyWindow(this->m_hWndProgressFinish);
	DestroyWindow(this->m_hWndSecondProgressbar);
}

HWND* CWindowControls::GetProgressBar(unsigned int uiId) {
	if(uiId == 0) return &this->m_hWndProgressbar;
	else return &this->m_hWndSecondProgressbar;
}