
// list_in_tabsDlg.h : header file
//

#pragma once


// ClistintabsDlg dialog
class ClistintabsDlg : public CDialogEx
{
    // Construction
public:
    ClistintabsDlg(CWnd* pParent = nullptr);	// standard constructor

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_LIST_IN_TABS_DIALOG };
#endif

protected:
    void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support

    void OnOK() override;

    // Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    BOOL OnInitDialog() override;
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};
