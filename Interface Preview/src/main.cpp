#include <Windows.h>

#include "window/window.h"
#include "controls/controls.h"
#include "shell/shell.h"
#include "superbar/superbar.h"

WINDOW* window = nullptr;
WINDOWCONTROLS* controls = nullptr;
SHELL* shell = nullptr;
SUPERBAR* superbar = nullptr;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR nCmdLine, _In_ int nCmdShow) {

	window = new WINDOW(&hInstance);
	controls = new WINDOWCONTROLS(window);
	shell = new SHELL();
	superbar = new SUPERBAR(window);

	while (!window->WindowShouldClose()) {
		window->HandleMessages();
	}

	delete superbar;
	delete shell;
	delete controls;
	delete window;

	return 0;
}