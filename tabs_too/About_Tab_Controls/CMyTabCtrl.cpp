//
// Created on 2024/07/18
//

#include "pch.h"

#include "CMyTabCtrl.h"

std::ostream& operator<<(std::ostream& ss, CSize const& tp)
{
    ss << "[" << tp.cx << "x" << tp.cy << "]";
    return ss;
}

std::ostream& operator<<(std::ostream& ss, CRect const& tp)
{
    ss << "{" << tp.TopLeft() << ", " << tp.BottomRight() << ", size: " << tp.Size() << "}";
    return ss;
}


IMPLEMENT_DYNAMIC(CMyTabCtrl, CDialog)

BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
    ON_WM_CTLCOLOR()
    ON_WM_DESTROY()
    ON_WM_LBUTTONDOWN()
    ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnTcnSelchange)
//    ON_MESSAGE(WM_BUTTONPRESSED, ButtonPressed)
//    ON_MESSAGE(WM_UPDOWN, UpDownButton)
END_MESSAGE_MAP()

CMyTabCtrl::~CMyTabCtrl()
{
    CONSOLE((void*)this);
}

/// @brief 
/// @param page 
void CMyTabCtrl::AddPage(CPropertyPage* page)
{
    ASSERT(page != NULL);

    int pos = int(m_pages.size());
    this->InsertItem(pos, page->m_pPSP->pszTitle);
    m_pages.push_back(page);

    CRect rc;
    GetClientRect(&rc);
    CONSOLE_EVAL(rc);

    AdjustRect(0, &rc);
    CONSOLE("adjusted rc:" << rc);

    //CRect rc;
    //VERIFY(GetItemRect(pos, &rc));

    page->Create(page->m_pPSP->pszTemplate, this);
    page->MoveWindow(rc);
}

void CMyTabCtrl::OnTcnSelchange(NMHDR* pNMHDR, LRESULT* pResult)
{
    CONSOLE("GetCurFocus: " << GetCurFocus());
    int pos = GetCurFocus();
    ShowTab(pos);
}

void
CMyTabCtrl::ShowTab(int pos)
{
    m_pages[pos]->ShowWindow(SW_SHOW);
}



