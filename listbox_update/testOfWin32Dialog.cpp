// testOfWin32Dialog.cpp 
//
#define _WIN32_IE 0X0600

#include <stdio.h>
#include <windows.h>
#include <commctrl.h>
#include "Resource.h"


#define MAX_LOADSTRING 100
#define MAX_LISTITEM 5
#define MAX_LISTSUBITEM 5
#define MAX_TABNUM 2

static HWND hDlg[2] = {NULL, NULL};
MSG msg;
HINSTANCE hInst;								
TCHAR szTitle[MAX_LOADSTRING];					
TCHAR szWindowClass[MAX_LOADSTRING];			

static TCHAR * tabString[MAX_TABNUM] = {"Index", "TBD"};
     static HWND hListbox;

     char helpindex[20][20] = 
     {"heading", "tracking", "port configuration", "position data", "flash", 
     "cell", "strike", "display mode", "range", "bearing",
     "region", "system status", "volume control", "nmi", "latitude",
     "longitude", "ground speed", "baud rate", "level", "tone"};  

HBRUSH g_hbrBackground = NULL;

void InitTabControl(HWND, LPARAM);
void GetItemText(HWND, const int &, TCHAR *);
BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND g_hMainDialog;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
   INITCOMMONCONTROLSEX icc = {sizeof(icc), ICC_TAB_CLASSES};
   InitCommonControlsEx(&icc);
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc);
}



BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch(message)
	{
	case WM_INITDIALOG:

	    InitTabControl(hwnd, lParam);

		break;

	case WM_NOTIFY:
      {
         NMHDR *hdr;
	     hdr = (LPNMHDR)lParam;
	     if (hdr->code == TCN_SELCHANGING || hdr->code == TCN_SELCHANGE) 
         {
		   int index;
		   index = TabCtrl_GetCurSel(hdr->hwndFrom);
		   if (index >= 0 && index <= 4) ShowWindow(hDlg[index], (hdr->code == TCN_SELCHANGE) ? SW_SHOW : SW_HIDE);
	     }
	     break;
      }
               
	case WM_COMMAND:
		if(LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;

    case WM_CLOSE:
        EndDialog(hwnd, 0);
        break;
         
    case WM_DESTROY:
         DeleteObject(g_hbrBackground);
         break;    
    default:
         return FALSE; 
    }

	return TRUE;
}

BOOL WINAPI DlgProc1(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
     int i;

     hListbox = GetDlgItem(hwnd, IDC_LISTBOX);
     switch(msg)
     {
        case WM_INITDIALOG:
             for (i =0;i< 20;i++)
             {
             SendMessage(GetDlgItem(hwnd,IDC_LISTBOX), LB_ADDSTRING, 0, (LPARAM) helpindex[i]);
             }
             break;
             
        case WM_NOTIFY:
             {
              switch(wParam)
              {
                case IDC_LISTBOX:
                     LPNMLISTVIEW pnm = (LPNMLISTVIEW)lParam;
                     
                     if(((LPNMHDR)lParam)->code == NM_DBLCLK)
                     {
                       int selected = SendMessage(hListbox, LVM_GETITEM,-1,LVNI_FOCUSED);
                       char String[10] = "";
                       if (selected == -1)
                       {
                         MessageBox(hwnd, "hey, error", "Error", MB_OK|MB_ICONINFORMATION);
                         break;
                       }
                       else
                       {
                           sprintf(String, "%d",selected);
                           MessageBox(hwnd, String, "Error", MB_OK|MB_ICONINFORMATION);
                       }                                                  
                     }
                break;     
              }    // end of 'switch'
             }
             break;
             
         case WM_COMMAND:
                break;

     }  // end of 'switch(msg)'
       
     
   return (msg == WM_INITDIALOG);
}

BOOL WINAPI DlgProc2(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
     switch(msg)
     {
        case WM_COMMAND:

        break;
     }  // end of 'switch(msg)'
       
     
   return (msg == WM_INITDIALOG);
}

void InitTabControl(HWND hwnd, LPARAM lParam)
{
    TCITEM tabitem;
    HWND hTab;
    
    hTab = GetDlgItem(hwnd, IDC_LISTTAB); 
    memset(&tabitem, 0, sizeof(tabitem));	
    
    tabitem.mask = TCIF_TEXT;
	tabitem.cchTextMax = MAX_TABNUM;      
	
    tabitem.pszText = "Index";
    SendMessage(hTab, TCM_INSERTITEM, 0, (LPARAM)&tabitem);

    tabitem.pszText = "TBD";
    SendMessage(hTab, TCM_INSERTITEM, 1, (LPARAM)&tabitem);
	
	// Get the position that the dialogs should be displayed
	RECT rt;
	GetWindowRect(GetDlgItem(hwnd, IDC_STATIC1), &rt);
    rt.bottom -= rt.top;
    rt.right  -= rt.left;
	ScreenToClient(hTab, (LPPOINT)&rt);
	
	// Create the dialogs modelessly and move them appropriately
    hDlg[0] = CreateDialog((HINSTANCE)lParam, (LPSTR)IDD_PAGE1, hTab, (DLGPROC)DlgProc1);  
    hDlg[1] = CreateDialog((HINSTANCE)lParam, (LPSTR)IDD_PAGE2, hTab, (DLGPROC)DlgProc2); 
    
    MoveWindow(hDlg[0], rt.left, rt.top, rt.right, rt.bottom, 0);
    MoveWindow(hDlg[1], rt.left, rt.top, rt.right, rt.bottom, 0);
    
    // Show the default dialog    
    ShowWindow(hDlg[0], SW_SHOW); 
}







