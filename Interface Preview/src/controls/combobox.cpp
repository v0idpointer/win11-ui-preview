#include "controls.h"

void CWindowControls::InitializeComboBox() {

	HINSTANCE hInstance = *this->m_lpWindow->GetInstanceHandle();
	HWND hWnd = *this->m_lpWindow->GetWindowHandle();

	this->m_hWndCombobox = CreateWindowExW(0, WC_COMBOBOXW, L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 16, 96, 256, 128, hWnd, NULL, hInstance, 0);

	ComboBox_AddString(this->m_hWndCombobox, L"Windows XP");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows Vista");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows 7");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows 8");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows 8.1");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows 10");
	ComboBox_AddString(this->m_hWndCombobox, L"Windows 11");

	ComboBox_SetCurSel(this->m_hWndCombobox, 5);

}

void CWindowControls::DestroyComboBox() {
	DestroyWindow(this->m_hWndCombobox);
}