//
// list_in_tabs.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#   error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// ClistintabsApp:
// See list_in_tabs.cpp for the implementation of this class
//

class ClistintabsApp : public CWinApp
{
public:
    ClistintabsApp();

    // Overrides
public:
    virtual BOOL InitInstance();

    // Implementation

    DECLARE_MESSAGE_MAP()
};

extern ClistintabsApp theApp;
