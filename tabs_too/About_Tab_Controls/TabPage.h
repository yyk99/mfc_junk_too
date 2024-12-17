#pragma once


// TabPage dialog

class TabPage : public CPropertyPage
{
    DECLARE_DYNAMIC(TabPage)

public:
    TabPage(UINT nIDCaption = 0, DWORD dwSize = sizeof(PROPSHEETPAGE));   // standard constructor
    virtual ~TabPage();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PAGE };
#endif


    BOOL OnInitDialog() override;

protected:
    void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
};
