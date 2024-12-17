#include "pch.h"
#include "OnlineSourcesDlg.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(OnlineSourcesDlg, CMFCPropertySheet)

BEGIN_MESSAGE_MAP(OnlineSourcesDlg, CMFCPropertySheet)
END_MESSAGE_MAP()

OnlineSourcesDlg::OnlineSourcesDlg()
    : CMFCPropertySheet()
    , m_page1(IDS_ALL_SRC)
    , m_page2(IDS_CUSTOM_SRC)
{
    SetLook(CMFCPropertySheet::PropSheetLook_Tabs);

    AddPage(&m_page1);
    AddPage(&m_page2);
}

BOOL OnlineSourcesDlg::OnInitDialog()
{
    auto ok = __super::OnInitDialog();

    // load images
    HICON icon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    VERIFY(m_images.Create(256, 256, 0, 0, 0));

    return ok;
}

OnlineSourcesDlg::~OnlineSourcesDlg()
{
}

