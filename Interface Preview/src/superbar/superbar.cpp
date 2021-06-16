#include "superbar.h"

CSuperbar::CSuperbar(CWindow* lpWindow) {
	this->m_pWindow = lpWindow;

	HRESULT hr = CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_ALL, IID_ITaskbarList3, (void**)&this->m_pSuperbar);
	if (FAILED(hr)) {
		MessageBoxW(NULL, L"Failed to initialize Superbar controls! Is running on Vista or older?", L"Fatal Error", MB_ICONERROR | MB_OK);
		exit(0x01);
	}
}

CSuperbar::~CSuperbar() { }

void CSuperbar::SetProgressBarValue(unsigned long long value, unsigned long long max) {
	this->m_pSuperbar->SetProgressValue(*this->m_pWindow->GetWindowHandle(), value, max);
}

void CSuperbar::SetNoProgress() {
	this->m_pSuperbar->SetProgressState(*this->m_pWindow->GetWindowHandle(), TBPF_NOPROGRESS);
}

void CSuperbar::SetIndeterminableProgress() {
	this->m_pSuperbar->SetProgressState(*this->m_pWindow->GetWindowHandle(), TBPF_INDETERMINATE);
}

void CSuperbar::SetNormalProgress() {
	this->m_pSuperbar->SetProgressState(*this->m_pWindow->GetWindowHandle(), TBPF_NORMAL);
}

void CSuperbar::SetPausedProgress() {
	this->m_pSuperbar->SetProgressState(*this->m_pWindow->GetWindowHandle(), TBPF_PAUSED);
}

void CSuperbar::SetErrorProgress() {
	this->m_pSuperbar->SetProgressState(*this->m_pWindow->GetWindowHandle(), TBPF_ERROR);
}