#pragma once
#include "afxdialogex.h"


// IconTabsDialog dialog

class IconTabsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(IconTabsDialog)

public:
	IconTabsDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~IconTabsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ICONTABS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
