#pragma once

#include <Windows.h>
#include <ShObjIdl.h>

#include "../window/window.h"

typedef class CSuperbar {

private:
	CWindow* m_pWindow;
	ITaskbarList3* m_pSuperbar = nullptr;

public:
	CSuperbar(CWindow*);
	~CSuperbar(void);

	void SetProgressBarValue(unsigned long long, unsigned long long);
	void SetNoProgress(void);
	void SetIndeterminableProgress(void);
	void SetNormalProgress(void);
	void SetPausedProgress(void);
	void SetErrorProgress(void);

} SUPERBAR, * PSUPERBAR, * LPSUPERBAR;