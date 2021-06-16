#include "controls.h"

void CWindowControls::InitializeTextbox() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndTextbox = CreateWindowExW(0, WC_EDITW, L"Hello World!", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 16, 128, 256, 24, hWnd, NULL, hInstance, 0);
	this->m_hWndTextarea = CreateWindowExW(0, WC_EDITW, L"The quick brown fox jumps over the lazy dog", WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_MULTILINE, 288, 96, 256, 56, hWnd, NULL, hInstance, 0);

}

void CWindowControls::DestroyTextbox() {
	DestroyWindow(this->m_hWndTextbox);
}