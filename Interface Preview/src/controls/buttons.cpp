#include "controls.h"

void CWindowControls::InitializeButtons() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndButton = CreateWindowExW(0, WC_BUTTONW, L"Button", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | WS_VISIBLE), 16, 16, 80, 32, hWnd, NULL, hInstance, 0);
	this->m_hWndCheckbox1 = CreateWindowExW(0, WC_BUTTONW, L"Checkbox 1", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | BS_CHECKBOX | WS_VISIBLE), 112, 16, 96, 32, hWnd, (HMENU)IDM_CTRL_CHECKBOX, hInstance, 0);
	this->m_hWndCheckbox2 = CreateWindowExW(0, WC_BUTTONW, L"Checkbox 2", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | BS_CHECKBOX | WS_VISIBLE), 112, 48, 96, 32, hWnd, (HMENU)IDM_CTRL_CHECKBOX, hInstance, 0);
	this->m_hWndRadio1 = CreateWindowExW(0, WC_BUTTONW, L"Radio Button 1", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | BS_RADIOBUTTON | WS_VISIBLE), 224, 16, 124, 32, hWnd, (HMENU)IDM_CTRL_RADIO, hInstance, 0);
	this->m_hWndRadio2 = CreateWindowExW(0, WC_BUTTONW, L"Radio Button 2", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | BS_RADIOBUTTON | WS_VISIBLE), 224, 48, 124, 32, hWnd, (HMENU)IDM_CTRL_RADIO, hInstance, 0);
	this->m_hWndLinkButton = CreateWindowExW(0, WC_BUTTONW, L"Command Link", (WS_CHILD | WS_CLIPSIBLINGS | BS_TEXT | BS_COMMANDLINK | WS_VISIBLE), 364, 16, 192, 64, hWnd, (HMENU)IDM_CTRL_COOL_BUTTON, hInstance, 0);

	SendMessageW(this->m_hWndLinkButton, BCM_SETNOTE, 0, (LPARAM)L"a very cool button ( :");

	Button_SetCheck(this->m_hWndCheckbox2, 1);
	Button_SetCheck(this->m_hWndRadio2, 1);

}

void CWindowControls::DestroyButtons() {
	DestroyWindow(this->m_hWndButton);
	DestroyWindow(this->m_hWndCheckbox1);
	DestroyWindow(this->m_hWndCheckbox2);
	DestroyWindow(this->m_hWndRadio1);
	DestroyWindow(this->m_hWndRadio2);
	DestroyWindow(this->m_hWndLinkButton);
}