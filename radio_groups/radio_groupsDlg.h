
// radio_groupsDlg.h : header file
//

#pragma once


// CradiogroupsDlg dialog
class CradiogroupsDlg : public CDialogEx
{
    // Construction
public:
    CradiogroupsDlg(CWnd* pParent = nullptr);

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_RADIO_GROUPS_DIALOG };
#endif

protected:
    void DoDataExchange(CDataExchange* pDX) override;


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
    afx_msg void OnBnClickedRadio1();
};
