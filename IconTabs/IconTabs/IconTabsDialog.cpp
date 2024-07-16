// IconTabsDialog.cpp : implementation file
//

#include "pch.h"
#include "IconTabs.h"
#include "afxdialogex.h"
#include "IconTabsDialog.h"


// IconTabsDialog dialog

IMPLEMENT_DYNAMIC(IconTabsDialog, CDialogEx)

IconTabsDialog::IconTabsDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ICONTABS_DIALOG, pParent)
{

}

IconTabsDialog::~IconTabsDialog()
{
}

void IconTabsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IconTabsDialog, CDialogEx)
END_MESSAGE_MAP()


// IconTabsDialog message handlers
