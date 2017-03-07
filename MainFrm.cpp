// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MFC_GL.h"

#include "MainFrm.h"
#include "Contrl_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	IDS_POINT,
	IDS_VIEWPOINT,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bAutoMenuEnable=FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//禁用工具栏
	/*if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}*/
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	/*m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.ShowWindow(SW_HIDE);
	/*//设置菜单项图标
	CBitmap *m_bm=new CBitmap();
	m_bm->LoadBitmap(IDB_VIEWPOINT);
	this->GetMenu()->GetSubMenu(3)->SetMenuItemBitmaps(0,MF_BYPOSITION,m_bm,m_bm);*/

	SetWindowLong(m_hWnd,GWL_STYLE,GetWindowLong(m_hWnd,GWL_STYLE)&~WS_MAXIMIZEBOX);//设置无最大化框
	SetClassLong(this->m_hWnd,GCL_HICON,(LONG)LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_JS)));//设置标题图标
	SetTimer(1,200,NULL);//设置视点坐标更新定时器
	return 0;
}
extern CMFC_GLApp theApp;
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.cx=800;
	cs.cy=700;
	cs.style&=~FWS_ADDTOTITLE;
	cs.lpszName="机器人虚拟仿真";
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

		if(::FindWindow(NULL,"正运动控制"))
		{
			CContrl_DLG* m_mainDlg=(CContrl_DLG*)CWnd::FromHandle(::FindWindow(NULL,"正运动控制"));
			GLfloat x=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[12];
			GLfloat y=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[13];
			GLfloat z=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[14];
			CString str;
			str.Format("X:%0.3f\nY:%0.3f\nZ:%0.3f",x,y,z);
			m_mainDlg->SetDlgItemText(IDC_CURRENT_COORD,(LPCTSTR)str);
		}
		if(::FindWindow(NULL,"逆运动控制"))
		{
			CContrl_DLG* m_mainDlg=(CContrl_DLG*)CWnd::FromHandle(::FindWindow(NULL,"逆运动控制"));
			GLfloat matrix[16];
			for(int i=0;i<16;i++)
				matrix[i]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[9].Matrix[i];
			GLfloat x=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_Sx;
			GLfloat y=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_Sy;
			GLfloat z=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_Sz;
			char buf[1024];
			memset(buf,0,sizeof(buf));
			sprintf(buf,"%8.3f%8.3f%8.3f%8.3f\n"  
            "%8.3f%8.3f%8.3f%8.3f\n"  
            "%8.3f%8.2f%8.3f%8.3f\n"  
            "%8.3f%8.3f%8.3f%8.3f\n",  
            matrix[0], matrix[4], matrix[8], matrix[12],  
            matrix[1], matrix[5], matrix[9], matrix[13],  
            matrix[2], matrix[6], matrix[10], matrix[14],  
            matrix[3], matrix[7], matrix[11], matrix[15]);
			m_mainDlg->SetDlgItemText(IDC_MD_POS,(LPCTSTR)buf);
		}
	CFrameWnd::OnTimer(nIDEvent);
}
