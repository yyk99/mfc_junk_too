
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
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAboutTabControlsDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB1, m_ctlSysTabControl32);
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
    // TODO: Add extra initialization 	// Setup and create the tab control
#if 0
    {
	    int nTabs = 3;
	    _TCHAR* pszNames[] = { _T("Wood"), _T("Natural Gas"), _T("Kryptonite") };
	    RECT rc;
	    GetWindowRect(&rc);
	    rc.right -= rc.left;
	    rc.bottom -= rc.top;
	    rc.top = rc.left = 0;
	    m_ctlSysTabControl32.Create(m_hWnd, rc, _T(""), WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | TCS_TABS);
	    TC_ITEM tie;
	    for (int i = 0; i < nTabs; i++)
	    {
	        tie.mask = TCIF_TEXT | TCIF_IMAGE;
	        tie.iImage = -1;
	        tie.pszText = pszNames[i];
	        tie.cchTextMax = (int)(_tcslen(pszNames[i]));
	        if (TabCtrl_InsertItem(m_ctlSysTabControl32.m_hWnd, i, &tie) == -1)
	        {
	            // The insert failed; display an error box.
	            ::MessageBox(NULL, _T("TabCtrl_InsertItem failed!"), NULL, MB_OK);
	            return E_FAIL;
	        }
	    }
	
	    m_Display.Create(m_ctlSysTabControl32.m_hWnd);
	    TabCtrl_SetCurSel(m_ctlSysTabControl32.m_hWnd, m_Display.m_curColor);
	    m_Display.ShowWindow(TRUE);
    }
#else
    //m_ctlSysTabControl32.Create(TCS_TABS, );
#endif
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

