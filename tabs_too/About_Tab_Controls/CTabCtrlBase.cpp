//
// Created on 2024/07/18
//

#include "pch.h"

#include "CTabCtrlBase.h"

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


IMPLEMENT_DYNAMIC(CTabCtrlBase, CDialog)

BEGIN_MESSAGE_MAP(CTabCtrlBase, CTabCtrl)
    ON_WM_CTLCOLOR()
    ON_WM_DESTROY()
    ON_WM_LBUTTONDOWN()
    ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnTcnSelchange)
//    ON_MESSAGE(WM_BUTTONPRESSED, ButtonPressed)
//    ON_MESSAGE(WM_UPDOWN, UpDownButton)
END_MESSAGE_MAP()

CTabCtrlBase::~CTabCtrlBase()
{
    CONSOLE((void*)this);
}

/// @brief 
/// @param page 
void CTabCtrlBase::AddPage(CPropertyPage* page)
{
    ASSERT(page != NULL);

    int pos = int(m_pages.size());
    this->InsertItem(pos, page->m_pPSP->pszTitle);
    m_pages.push_back(page);

    page->Create(page->m_pPSP->pszTemplate, this);
}

void CTabCtrlBase::OnTcnSelchange(NMHDR* pNMHDR, LRESULT* pResult)
{
    CONSOLE("GetCurFocus: " << GetCurFocus());
    int pos = GetCurFocus();
    ShowTab(pos);
}

void
CTabCtrlBase::ShowTab(int pos)
{
    CRect rc;
    GetClientRect(&rc);
    CONSOLE_EVAL(rc);

    AdjustRect(0, &rc);
    CONSOLE("adjusted rc:" << rc);

    for (int i = 0; i != m_pages.size(); ++i)
    {
        if (i == pos) {
            m_pages[i]->MoveWindow(rc);
            m_pages[i]->ShowWindow(SW_SHOW);
        }
        else
            m_pages[i]->ShowWindow(SW_HIDE);
    }
}



