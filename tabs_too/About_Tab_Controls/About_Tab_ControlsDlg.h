
// About_Tab_ControlsDlg.h : header file
//

#pragma once

#include "TabPage.h"

#include <vector>

class CMyTabCtrl : public CTabCtrl
{
    DECLARE_DYNAMIC(CMyTabCtrl)

public:
    virtual ~CMyTabCtrl();

    void AddPage(CPropertyPage *page);

    /// @brief 
    /// @param nTab index of the tab (0..n-1)
    void ShowTab(int nTab);

protected:

    // virtual BOOL PreTranslateMessage(MSG* pMsg);

    DECLARE_MESSAGE_MAP()

protected:
    afx_msg void OnTcnSelchange(NMHDR* pNMHDR, LRESULT* pResult);

    std::vector<CPropertyPage*> m_pages;
};

// CAboutTabControlsDlg dialog
class CAboutTabControlsDlg : public CDialogEx
{
    // Construction
public:
    CAboutTabControlsDlg(CWnd* pParent = nullptr);	// standard constructor

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUT_TAB_CONTROLS_DIALOG };
#endif

protected:
    void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support


    // Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);

    CMyTabCtrl m_ctlSysTabControl32;
    TabPage m_page1;
    TabPage m_page2;
    TabPage m_page3;
};
