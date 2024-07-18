
// About_Tab_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "About_Tab_Controls.h"
#include "About_Tab_ControlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#if _DEBUG
#   include <iostream> // for CONSOLE(...)

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

#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    // Implementation
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAboutTabControlsDlg dialog



CAboutTabControlsDlg::CAboutTabControlsDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_ABOUT_TAB_CONTROLS_DIALOG, pParent)
    , m_ctlSysTabControl32{}
    , m_page1(IDS_PAGE_1)
    , m_page2(IDS_PAGE_2)
    , m_page3(IDS_PAGE_3)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAboutTabControlsDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB1, m_ctlSysTabControl32);
    CONSOLE("here...");
}

BEGIN_MESSAGE_MAP(CAboutTabControlsDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CAboutTabControlsDlg message handlers

BOOL CAboutTabControlsDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Add "About..." menu item to system menu.
#pragma region About
    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon
#pragma endregion

    m_ctlSysTabControl32.AddPage(&m_page1);
    m_ctlSysTabControl32.AddPage(&m_page2);
    m_ctlSysTabControl32.AddPage(&m_page3);

    m_ctlSysTabControl32.ShowTab(0);

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAboutTabControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAboutTabControlsDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAboutTabControlsDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

BOOL CAboutTabControlsDlg::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult)
{
    // TODO: Add your specialized code here and/or call the base class
    switch (message)
    {
    case WM_NOTIFY:
        CONSOLE("message: " << message << ", hex:" << std::hex << message);
        break;
    default:
        break;
    }

    return CDialogEx::OnChildNotify(message, wParam, lParam, pLResult);
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

