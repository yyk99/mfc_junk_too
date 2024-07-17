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


BEGIN_MESSAGE_MAP(SourceListPage, CMFCPropertyPage)
END_MESSAGE_MAP()


// SourceListPage message handlers
