#include "pch.h"
#include "OnlineSourcesDlg.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(OnlineSourcesDlg, CMFCPropertySheet)

BEGIN_MESSAGE_MAP(OnlineSourcesDlg, CMFCPropertySheet)
END_MESSAGE_MAP()

OnlineSourcesDlg::OnlineSourcesDlg()
    : CMFCPropertySheet()
    , m_Page1(IDS_ALL_SRC)
    , m_Page2(IDS_CUSTOM_SRC)
{
    SetLook(CMFCPropertySheet::PropSheetLook_Tabs);

    AddPage(&m_Page1);
    AddPage(&m_Page2);
}

OnlineSourcesDlg::~OnlineSourcesDlg()
{
}

