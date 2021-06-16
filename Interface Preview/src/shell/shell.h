#pragma once

#include <Windows.h>
#include <shellapi.h>

#pragma comment(lib, "Shell32.lib")

typedef class CShell {

private:

public:
	void OpenShellAbout(void);

} SHELL, * PSHELL, * LPSHELL;