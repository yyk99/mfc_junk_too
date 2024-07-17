#pragma once

#include "SourceListPage.h"

class OnlineSourcesDlg : public CMFCPropertySheet
{
    DECLARE_DYNAMIC(OnlineSourcesDlg)

    // Construction
public:
    OnlineSourcesDlg();

    // Attributes
public:
    SourceListPage m_Page1;
    SourceListPage m_Page2;

    // Operations
public:

    //// Overrides
    //virtual void OnDrawPageHeader(CDC* pDC, int nPage, CRect rectHeader);

    // Implementation
public:
    virtual ~OnlineSourcesDlg();

protected:
    DECLARE_MESSAGE_MAP()
};

