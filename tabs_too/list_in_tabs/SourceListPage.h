#pragma once
#include "afxpropertypage.h"


// SourceListPage dialog

class SourceListPage : public CMFCPropertyPage
{
    DECLARE_DYNAMIC(SourceListPage)

public:
    SourceListPage(UINT nIDCaption = 0);   // standard constructor
    virtual ~SourceListPage();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PROP_PAGE };
#endif

protected:
    void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
};
