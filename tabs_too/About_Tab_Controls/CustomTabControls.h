
// About_Tab_Controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CustomTabControlsApp:
// See About_Tab_Controls.cpp for the implementation of this class
//

class CustomTabControlsApp : public CWinApp
{
public:
	CustomTabControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CustomTabControlsApp theApp;
