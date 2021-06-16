#include "controls.h"

CWindowControls::CWindowControls(CWindow* lpWindow) : m_lpWindow(lpWindow) {
	this->InitializeButtons();
	this->InitializeComboBox();
	this->InitializeTextbox();
	this->InitializeProgressbar();
	this->InitializeSlider();
	this->InitializeInetAddress();
}

CWindowControls::~CWindowControls() {
	this->DestroyButtons();
	this->DestroyComboBox();
	this->DestroyTextbox();
	this->DestroyProgressbar();
	this->DestroySlider();
	this->DestroyInetAddress();
}