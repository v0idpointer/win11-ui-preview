#include "controls.h"

void CWindowControls::InitializeInetAddress() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndInetAddress = CreateWindowExW(0, WC_IPADDRESSW, L"", WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE, 16, 224, 256, 24, hWnd, NULL, hInstance, 0);
	SendMessageW(this->m_hWndInetAddress, IPM_SETADDRESS, (WPARAM)0, (LPARAM)(MAKEIPADDRESS(192, 168, 0, 17)));

	this->m_hWndPassword = CreateWindowExW(0, WC_EDITW, L"1234", WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | ES_PASSWORD | ES_AUTOHSCROLL, 16, 256, 256, 24, hWnd, NULL, hInstance, 0);

}

void CWindowControls::DestroyInetAddress() {
	DestroyWindow(this->m_hWndInetAddress);
	DestroyWindow(this->m_hWndPassword);
}