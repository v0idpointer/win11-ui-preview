#pragma once
#include <Windows.h>

typedef class CWindow {

private:
	const wchar_t* m_lpcwszClassName = L"interface_preview_win11";
	const wchar_t* m_lpcwszWindowName = L"V0idPointer's Window Preview";
	const DWORD m_dwWindowStyle = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);

private:
	HINSTANCE* m_pInstanceHandle = nullptr;
	HWND m_hWnd = nullptr;

	bool m_bWindowShouldClose = false;

	HMENU m_hMenubar = nullptr;
	HMENU m_hMenuSuperbar = nullptr;
	HMENU m_hMenuFile = nullptr;

public:
	CWindow(HINSTANCE*);
	~CWindow(void);

	HINSTANCE* GetInstanceHandle(void);
	HWND* GetWindowHandle(void);

	void HandleMessages(void);
	bool WindowShouldClose(void);

public:
	static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

} WINDOW, * PWINDOW, * LPWINDOW;