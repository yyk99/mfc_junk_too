// TabPage.cpp : implementation file
//

#include "pch.h"
#include "About_Tab_Controls.h"
#include "afxdialogex.h"
#include "TabPage.h"


// TabPage dialog

IMPLEMENT_DYNAMIC(TabPage, CDialogEx)

TabPage::TabPage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE, pParent)
{

}

TabPage::~TabPage()
{
}

void TabPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabPage, CDialogEx)
END_MESSAGE_MAP()


// TabPage message handlers
