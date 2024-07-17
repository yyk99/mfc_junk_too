// SourceListPage.cpp : implementation file
//

#include "pch.h"
#include "list_in_tabs.h"
#include "afxdialogex.h"
#include "SourceListPage.h"

#include "resource.h"		// main symbols

// SourceListPage dialog

IMPLEMENT_DYNAMIC(SourceListPage, CMFCPropertyPage)

SourceListPage::SourceListPage(UINT nIDCaption /* = 0 */)
    : CMFCPropertyPage(IDD_PROP_PAGE, nIDCaption)
{
#ifndef _WIN32_WCE
    EnableActiveAccessibility();
#endif
}

SourceListPage::~SourceListPage()
{
}

void SourceListPage::DoDataExchange(CDataExchange* pDX)
{
    CMFCPropertyPage::DoDataExchange(pDX);
}


BOOL SourceListPage::OnInitDialog()
{
    TRACE(_T("Hello from: %s\n"), m_strCaption.GetString());

    auto ok = __super::OnInitDialog();

    // Compose the list
    if (auto lp = (CListCtrl*)GetDlgItem(IDC_LIST1))
    {
        for (int i = 0; i != 30; ++i)
        {
            CString s; s.Format(_T("%s Item #%d"), m_strCaption.GetString(), i);
            lp->InsertItem(i, s.GetString());
        }
    }
    return ok;
}

BEGIN_MESSAGE_MAP(SourceListPage, CMFCPropertyPage)
END_MESSAGE_MAP()


// SourceListPage message handlers
