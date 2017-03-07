// MFC_GLView.cpp : implementation of the CMFC_GLView class
//

#include "stdafx.h"
#include "MFC_GL.h"

#include "MFC_GLDoc.h"
#include "MFC_GLView.h"
#include "MainFrm.h"
#include "Contrl_DLG.h"
#include "Nijie_DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView

IMPLEMENT_DYNCREATE(CMFC_GLView, CView)

BEGIN_MESSAGE_MAP(CMFC_GLView, CView)
	//{{AFX_MSG_MAP(CMFC_GLView)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_CONTRL_MODEL, OnContrlModel)
	ON_COMMAND(IDM_NICONTRL, OnNicontrl)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView construction/destruction

CMFC_GLView::CMFC_GLView()
{
	// TODO: add construction code here
}

CMFC_GLView::~CMFC_GLView()
{
}

BOOL CMFC_GLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszClass=AfxRegisterWndClass(0,LoadCursor(NULL,IDC_CROSS));
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView drawing

void CMFC_GLView::OnDraw(CDC* pDC)
{
	CMFC_GLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

}

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView printing

BOOL CMFC_GLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView diagnostics

#ifdef _DEBUG
void CMFC_GLView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_GLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_GLDoc* CMFC_GLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_GLDoc)));
	return (CMFC_GLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLView message handlers

void CMFC_GLView::OnDestroy() 
{
	CView::OnDestroy();
	((CMFC_GLApp*)AfxGetApp())->m_openGL.ClearUp();
	// TODO: Add your message handler code here
}

int CMFC_GLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.SetupPixelFormat(::GetDC(m_hWnd));
	return 0;
}

void CMFC_GLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	int width=cx;
	int height=cy;
	if(height==0)
		height=1;
	((CMFC_GLApp*)AfxGetApp())->m_openGL.ReSize(width,height);
	// TODO: Add your message handler code here
}



void CMFC_GLView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("ЪѓБъзјБъ(%d,%d)",point.x,point.y);
	CClientDC dc(this);
	CSize sz=dc.GetTextExtent(str);
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->m_wndStatusBar.SetPaneInfo(1,IDS_POINT,SBPS_NORMAL,sz.cx);
	((CMainFrame*)GetParent())->m_wndStatusBar.SetPaneText(1,str);


	
	CView::OnMouseMove(nFlags, point);
}


void CMFC_GLView::OnContrlModel() 
{
	// TODO: Add your command handler code here
	CContrl_DLG *m_cdlg=new CContrl_DLG();
	m_cdlg->Create(IDD_CONTRL_DLG);
	m_cdlg->ShowWindow(SW_SHOW);
}

void CMFC_GLView::OnNicontrl() 
{
	// TODO: Add your command handler code here
	CNijie_DLG *m_ndlg=new CNijie_DLG();
	m_ndlg->Create(IDD_NIJIE_DLG);
	m_ndlg->ShowWindow(SW_SHOW);
}
