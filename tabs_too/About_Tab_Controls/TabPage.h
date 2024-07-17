#pragma once
#include "afxdialogex.h"


// TabPage dialog

class TabPage : public CDialogEx
{
    DECLARE_DYNAMIC(TabPage)

public:
    TabPage(CWnd* pParent = nullptr);   // standard constructor
    virtual ~TabPage();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PAGE };
#endif

protected:
    void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
};
