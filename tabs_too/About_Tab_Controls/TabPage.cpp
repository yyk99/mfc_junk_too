// TabPage.cpp : implementation file
//

#include "pch.h"
#include "CustomTabControls.h"
#include "afxdialogex.h"
#include "TabPage.h"

// TabPage dialog

IMPLEMENT_DYNAMIC(TabPage, CPropertyPage)

TabPage::TabPage(UINT nIDCaption/* = 0*/, DWORD dwSize /*= sizeof(PROPSHEETPAGE)*/)
	: CPropertyPage(IDD_PAGE, nIDCaption, nIDCaption, dwSize)
{
}

TabPage::~TabPage()
{
}

BOOL TabPage::OnInitDialog()
{
    auto ok = __super::OnInitDialog();

    if (auto sp = GetDlgItem(IDC_HELLO_THERE))
    {
        CString s;
        sp->GetWindowText(s);
        sp->SetWindowText((s + _T(" ... from ") + m_strCaption).GetString());
    }

    return ok;
}

void TabPage::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(TabPage, CPropertyPage)
END_MESSAGE_MAP()


// TabPage message handlers
