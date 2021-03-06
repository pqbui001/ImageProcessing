// ImageProcessing.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "MainFrm.h"
#include "Utility.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenGLApplicationApp

BEGIN_MESSAGE_MAP(COpenGLApplicationApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &COpenGLApplicationApp::OnAppAbout)
	ON_COMMAND(ID_FILE_OPEN, &COpenGLApplicationApp::OnFileOpen)
END_MESSAGE_MAP()


// COpenGLApplicationApp construction

COpenGLApplicationApp::COpenGLApplicationApp()
{
}


// The one and only COpenGLApplicationApp object

COpenGLApplicationApp theApp;


// COpenGLApplicationApp initialization

BOOL COpenGLApplicationApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored

	SetRegistryKey(_T("OpenGL Application"));

	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;

	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}


// COpenGLApplicationApp message handlers




// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// App command to run the dialog
void COpenGLApplicationApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// COpenGLApplicationApp message handlers



void COpenGLApplicationApp::OnFileOpen()
{
	// TODO: Add your command handler code here
	CFileDialog dlg(TRUE);

	CString filename;

	if (dlg.DoModal() == IDOK)
	{

		filename = dlg.GetPathName(); // return full path and filename
		
		// Convert a TCHAR string to a LPCSTR
		CT2CA pszConvertedAnsiString(filename);
		// construct a std::string using the LPCSTR input
		std::string filePath(pszConvertedAnsiString);
		//Utility util;
		Utility::SetImagePath(filePath);
		string tmp = Utility::GetImagePath();
	}

}
