//
// Created on 2024/07/18
//

#ifndef CMYTABCTRL_H
#define CMYTABCTRL_H

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


#endif // CMYTABCTRL_H
