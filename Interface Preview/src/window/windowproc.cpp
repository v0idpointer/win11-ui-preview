#include "window.h"
#include "../controls/controls.h"
#include "../shell/shell.h"
#include "../superbar/superbar.h"

extern "C++" WINDOWCONTROLS * controls;
extern "C++" SHELL * shell;
extern "C++" SUPERBAR * superbar;

LRESULT CALLBACK CWindow::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;

	case WM_COMMAND:
	{
		
		switch (LOWORD(wParam)) {

		case IDM_CTRL_CHECKBOX:
		{
			if (HIWORD(wParam) == BN_CLICKED) {
				HWND hCheckbox = (HWND)lParam;
				int c = Button_GetCheck(hCheckbox);
				Button_SetCheck(hCheckbox, (c == 0) ? 1 : 0);
			}
		}
		break;

		case IDM_CTRL_RADIO:
		{
			if (HIWORD(wParam) == BN_CLICKED) {
				HWND hRadioButton = (HWND)lParam;
				int c = Button_GetCheck(hRadioButton);
				Button_SetCheck(hRadioButton, (c == 0) ? 1 : 0);
			}
		}
		break;

		case IDM_CTRL_COOL_BUTTON:
		{
			MessageBoxW(NULL, L"Hello!", L"Cool Button Says...", (MB_ICONINFORMATION | MB_OK));
		}
		break;

		case IDM_CTRL_PROGRESS_SUB:
		{
			int v = SendMessageW(*controls->GetProgressBar(0), PBM_GETPOS, (WPARAM)0, (LPARAM)0);
			v -= 10;
			if (v < 0) v = 0;
			SendMessageW(*controls->GetProgressBar(0), PBM_SETPOS, (WPARAM)v, (LPARAM)0);
		}
		break;

		case IDM_CTRL_PROGRESS_ADD:
		{
			int v = SendMessageW(*controls->GetProgressBar(0), PBM_GETPOS, (WPARAM)0, (LPARAM)0);
			v += 10;
			if (v > 100) v = 100;
			SendMessageW(*controls->GetProgressBar(0), PBM_SETPOS, (WPARAM)v, (LPARAM)0);
		}
		break;

		case IDM_CTRL_PROGRESS_STR:
		{
			SendMessageW(*controls->GetProgressBar(0), PBM_SETPOS, (WPARAM)0, (LPARAM)0);
		}
		break;

		case IDM_CTRL_PROGRESS_FNS:
		{
			SendMessageW(*controls->GetProgressBar(0), PBM_SETPOS, (WPARAM)100, (LPARAM)0);
		}
		break;

		case IDM_SHELL_ABOUT: 
		{
			shell->OpenShellAbout();
		}
		break;

		case IDM_SUPERBAR_RESET:
		{
			superbar->SetNoProgress();
		}
		break;

		case IDM_SUPERBAR_STAGE1:
		{
			superbar->SetProgressBarValue(25, 100);
		}
		break;

		case IDM_SUPERBAR_STAGE2:
		{
			superbar->SetProgressBarValue(50, 100);
		}
		break;

		case IDM_SUPERBAR_STAGE3:
		{
			superbar->SetProgressBarValue(75, 100);
		}
		break;

		case IDM_SUPERBAR_STAGE4:
		{
			superbar->SetProgressBarValue(100, 100);
		}
		break;

		case IDM_SUPERBAR_PAUSED:
		{
			superbar->SetPausedProgress();
		}
		break;

		case IDM_SUPERBAR_ERROR:
		{
			superbar->SetErrorProgress();
		}
		break;


		case IDM_SUPERBAR_LOOP:
		{
			superbar->SetIndeterminableProgress();
		}
		break;

		case IDM_SUPERBAR_NORMAL:
		{
			superbar->SetNormalProgress();
		}
		break;

		case IDM_FILE_EXIT:
		{
			PostQuitMessage(0);
		}
		break;

		}

	}
	break;

	case WM_HSCROLL:
	{
		if ((HWND)lParam == *controls->GetSliderHandle()) {
			int v = SendMessageW((HWND)lParam, TBM_GETPOS, (WPARAM)0, (LPARAM)0);
			SendMessageW(*controls->GetProgressBar(1), PBM_SETPOS, (WPARAM)v, (LPARAM)0);
		}
	}
	break;

	}

	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}