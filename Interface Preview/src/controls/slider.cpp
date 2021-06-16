#include "controls.h"

void CWindowControls::InitializeSlider() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndSlider = CreateWindowExW(0, TRACKBAR_CLASSW, L"Progress Control", WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_ENABLESELRANGE, 288, 192, 256, 24, hWnd, (HMENU)IDM_CTRL_SLIDER, hInstance, 0);

}

void CWindowControls::DestroySlider() {
	DestroyWindow(this->m_hWndSlider);
}

HWND* CWindowControls::GetSliderHandle() {
	return &this->m_hWndSlider;
}