#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <CommCtrl.h>
#include <VersionHelpers.h>

// honestly, no idea why
#pragma comment (lib, "Comctl32.lib")
#pragma comment (linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "../window/window.h"

constexpr unsigned int IDM_CTRL_CHECKBOX = 0x0001;
constexpr unsigned int IDM_CTRL_RADIO = 0x0002;
constexpr unsigned int IDM_CTRL_COOL_BUTTON = 0x0003;
constexpr unsigned int IDM_CTRL_PROGRESS_SUB = 0x0004;
constexpr unsigned int IDM_CTRL_PROGRESS_ADD = 0x0005;
constexpr unsigned int IDM_CTRL_PROGRESS_STR = 0x0006;
constexpr unsigned int IDM_CTRL_PROGRESS_FNS = 0x0007;
constexpr unsigned int IDM_CTRL_SLIDER = 0x0008;
constexpr unsigned int IDM_SHELL_ABOUT = 0x0009;
constexpr unsigned int IDM_SUPERBAR_RESET = 0x000A;
constexpr unsigned int IDM_SUPERBAR_STAGE1 = 0x000B;
constexpr unsigned int IDM_SUPERBAR_STAGE2 = 0x000C;
constexpr unsigned int IDM_SUPERBAR_STAGE3 = 0x000D;
constexpr unsigned int IDM_SUPERBAR_STAGE4 = 0x000E;
constexpr unsigned int IDM_SUPERBAR_PAUSED = 0x000F;
constexpr unsigned int IDM_SUPERBAR_LOOP = 0x0010;
constexpr unsigned int IDM_SUPERBAR_ERROR = 0x0011;
constexpr unsigned int IDM_SUPERBAR_NORMAL = 0x0012;
constexpr unsigned int IDM_FILE_EXIT = 0x0013;

typedef class CWindowControls {

private:
	CWindow* m_lpWindow = nullptr;

	HWND m_hWndButton = nullptr;
	HWND m_hWndCheckbox1 = nullptr;
	HWND m_hWndCheckbox2 = nullptr;
	HWND m_hWndRadio1 = nullptr;
	HWND m_hWndRadio2 = nullptr;
	HWND m_hWndLinkButton = nullptr;

	HWND m_hWndCombobox = nullptr;

	HWND m_hWndTextbox = nullptr;
	HWND m_hWndTextarea = nullptr;

	HWND m_hWndProgressbar = nullptr;
	HWND m_hWndProgressMinus = nullptr;
	HWND m_hWndProgressPlus = nullptr;
	HWND m_hWndProgressClear = nullptr;
	HWND m_hWndProgressFinish = nullptr;

	HWND m_hWndSecondProgressbar = nullptr;
	HWND m_hWndSlider = nullptr;

	HWND m_hWndInetAddress = nullptr;
	HWND m_hWndPassword = nullptr;

public:
	CWindowControls(CWindow*);
	~CWindowControls(void);

	void InitializeButtons(void);
	void DestroyButtons(void);
	void InitializeComboBox(void);
	void DestroyComboBox(void);
	void InitializeTextbox(void);
	void DestroyTextbox(void);
	void InitializeProgressbar(void);
	void DestroyProgressbar(void);
	void InitializeSlider(void);
	void DestroySlider(void);
	void InitializeInetAddress(void);
	void DestroyInetAddress(void);

	HWND* GetProgressBar(unsigned int);
	HWND* GetSliderHandle(void);

} WINDOWCONTROLS, * PWINDOWCONTROLS, * LPWINDOWCONTROLS;