#pragma once

#include "SourceListPage.h"

class OnlineSourcesDlg : public CMFCPropertySheet
{
    DECLARE_DYNAMIC(OnlineSourcesDlg)

    // Construction
public:
    OnlineSourcesDlg();


    BOOL OnInitDialog() override;

    // Attributes
public:
    SourceListPage m_page1;
    SourceListPage m_page2;

    CImageList m_images;

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

