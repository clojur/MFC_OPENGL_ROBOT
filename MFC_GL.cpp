// MFC_GL.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_GL.h"

#include "MainFrm.h"
#include "MFC_GLDoc.h"
#include "MFC_GLView.h"
#include "Draw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLApp

BEGIN_MESSAGE_MAP(CMFC_GLApp, CWinApp)
	//{{AFX_MSG_MAP(CMFC_GLApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(IDM_ZHUSHITU, OnZhushitu)
	ON_COMMAND(IDM_ZUOSHITU, OnZuoshitu)
	ON_COMMAND(IDM_FUSHITU, OnFushitu)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLApp construction

CMFC_GLApp::CMFC_GLApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_GLApp object

CMFC_GLApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLApp initialization

BOOL CMFC_GLApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMFC_GLDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMFC_GLView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMFC_GLApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLApp message handlers



BOOL CMFC_GLApp::OnIdle(LONG lCount) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (CWinApp::OnIdle(lCount))
      return TRUE; 
	else
	{
		m_openGL.Render();
	}
}


void CMFC_GLApp::OnZhushitu() 
{
	// TODO: Add your command handler code here
	m_openGL.m_displayscene->er_y=90.0f;
	m_openGL.m_displayscene->er_z=0.0f;

}

void CMFC_GLApp::OnZuoshitu() 
{
	// TODO: Add your command handler code here
	m_openGL.m_displayscene->er_y=0.0f;
	m_openGL.m_displayscene->er_z=0.0f;
}

void CMFC_GLApp::OnFushitu() 
{
	// TODO: Add your command handler code here
	if(m_openGL.m_displayscene->er_c==0)
	{
		m_openGL.m_displayscene->er_c=90.0;
		m_openGL.m_displayscene->er_z=90.0;
	}
	else if(m_openGL.m_displayscene->er_c==90.0)
	{
		m_openGL.m_displayscene->er_z=90.0;
	}
	else
	{
		AfxMessageBox("模型转动后将不能进行俯视操作!\n请先初始化视图");
		return;
	}

}
