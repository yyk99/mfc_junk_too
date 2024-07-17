
// About_Tab_ControlsDlg.h : header file
//

#pragma once


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
    CTabCtrl m_ctlSysTabControl32;
};
