// Contrl_DLG.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_gl.h"
#include "Contrl_DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContrl_DLG dialog



CContrl_DLG::CContrl_DLG(CWnd* pParent /*=NULL*/)
	: CDialog(CContrl_DLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CContrl_DLG)
	m_model_x = 0.0f;
	m_model_y = 0.0f;
	m_model_z = 0.0f;
	m_AllR_step = 0.0f;
	m_AllB_step = 0.0f;
	m_BeiTouB_step = 0.0f;
	m_ShowWanB_step = 0.0f;
	m_XiaoBiR_step = 0.0f;
	m_MD_step = 0.0f;
	//}}AFX_DATA_INIT
	memset(tmpMatrix,0,sizeof(tmpMatrix));
}


void CContrl_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CContrl_DLG)
	DDX_Text(pDX, IDC_EDIT_X, m_model_x);
	DDX_Text(pDX, IDC_EDIT_Y, m_model_y);
	DDX_Text(pDX, IDC_EDIT_Z, m_model_z);
	DDX_Text(pDX, IDC_ALLR_STEP, m_AllR_step);
	DDV_MinMaxFloat(pDX, m_AllR_step, -360.f, 360.f);
	DDX_Text(pDX, IDC_ALLB_STEP, m_AllB_step);
	DDV_MinMaxFloat(pDX, m_AllB_step, -80.f, 40.f);
	DDX_Text(pDX, IDC_BEITOUB_STEP, m_BeiTouB_step);
	DDV_MinMaxFloat(pDX, m_BeiTouB_step, -50.f, 25.f);
	DDX_Text(pDX, IDC_SHOUWANB_STEP, m_ShowWanB_step);
	DDV_MinMaxFloat(pDX, m_ShowWanB_step, -100.f, 100.f);
	DDX_Text(pDX, IDC_XIAOBIR_STEP, m_XiaoBiR_step);
	DDV_MinMaxFloat(pDX, m_XiaoBiR_step, -360.f, 360.f);
	DDX_Text(pDX, IDC_MD_STEP, m_MD_step);
	DDV_MinMaxFloat(pDX, m_MD_step, -360.f, 360.f);
	//}}AFX_DATA_MAP

	
}


BEGIN_MESSAGE_MAP(CContrl_DLG, CDialog)
	//{{AFX_MSG_MAP(CContrl_DLG)
	ON_BN_CLICKED(IDC_TRANSLATE, OnTranslate)
	ON_BN_CLICKED(IDC_ALL_RIGHT, OnAllRight)
	ON_BN_CLICKED(IDC_ALL_LEFT, OnAllLeft)
	ON_EN_CHANGE(IDC_ALLR_STEP, OnChangeAllrStep)
	ON_EN_CHANGE(IDC_ALLB_STEP, OnChangeAllbStep)
	ON_BN_CLICKED(IDC_AllB_UP, OnAllBUP)
	ON_BN_CLICKED(IDC_AllB_DOWN, OnAllBDOWN)
	ON_EN_CHANGE(IDC_BEITOUB_STEP, OnChangeBeitoubStep)
	ON_BN_CLICKED(IDC_BEITOUB_UP, OnBeitoubUp)
	ON_BN_CLICKED(IDC_BEITOUB_DOWN, OnBeitoubDown)
	ON_EN_CHANGE(IDC_SHOUWANB_STEP, OnChangeShouwanbStep)
	ON_BN_CLICKED(IDC_SHOUWANB_UP, OnShouwanbUp)
	ON_BN_CLICKED(IDC_SHOUWANB_DOWN, OnShouwanbDown)
	ON_EN_CHANGE(IDC_XIAOBIR_STEP, OnChangeXiaobirStep)
	ON_BN_CLICKED(IDC_XIAOBIR_LEFT, OnXiaobirLeft)
	ON_BN_CLICKED(IDC_XIAOBIR_RIGHT, OnXiaobirRight)
	ON_BN_CLICKED(IDC_YANSHI, OnYanshi)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_END_YANSHI, OnEndYanshi)
	ON_EN_CHANGE(IDC_MD_STEP, OnChangeMdStep)
	ON_BN_CLICKED(IDC_MD_LEFT, OnMdLeft)
	ON_BN_CLICKED(IDC_MD_RIGHT, OnMdRight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContrl_DLG message handlers

BOOL CContrl_DLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GLfloat x=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[12];
	GLfloat y=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[13];
	GLfloat z=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[14];
	CString str;
	str.Format("X:%0.3f\nY:%0.3f\nZ:%0.3f",x,y,z);
	SetDlgItemText(IDC_CURRENT_COORD,(LPCTSTR)str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CContrl_DLG::OnTranslate() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
		//模型位置
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[12]=m_model_x;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[13]=m_model_y;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[0].Matrix[14]=m_model_z;

}

void CContrl_DLG::OnAllRight() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z+=m_AllR_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	
}

void CContrl_DLG::OnAllLeft() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z-=m_AllR_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnChangeAllrStep() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	// TODO: Add your control notification handler code here
	
}

void CContrl_DLG::OnChangeAllbStep() 
{

	UpdateData();
	
}

void CContrl_DLG::OnAllBUP() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b+=m_AllB_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[1]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnAllBDOWN() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b-=m_AllB_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[1]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnChangeBeitoubStep() 
{
	UpdateData();
}

void CContrl_DLG::OnBeitoubUp() 
{
	// TODO: Add your control notification handler code here
	if((m_BeiTouB_step)>5.0)
	{
		::MessageBox(NULL,"背头向上步长过大\n将与大臂发生碰撞\n步长范围(0.0~5.0),请重新设置!","警告",MB_OK|MB_ICONERROR);
		return;
	}
	else
	{
		if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b>25.0)
		{
			AfxMessageBox("发生碰撞!");
			return;
		}
		else
		{
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b+=m_BeiTouB_step;
			GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b;
			
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[8]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);	
		}		
	}
		

}

void CContrl_DLG::OnBeitoubDown() 
{
	// TODO: Add your control notification handler code here
	if((m_BeiTouB_step)>5.0)
	{
		::MessageBox(NULL,"背头向上步长过大\n将与大臂发生碰撞\n步长范围(0.0~5.0),请重新设置!","警告",MB_OK|MB_ICONERROR);
		return;
	}
	else
	{
		if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b<-50.0)
		{
			AfxMessageBox("向下已达最大值!");
			return;
		}
		else
		{
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b-=m_BeiTouB_step;
			GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b;
			
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[8]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);	
		}		
	}
}

void CContrl_DLG::OnChangeShouwanbStep() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	// TODO: Add your control notification handler code here
	
}

void CContrl_DLG::OnShouwanbUp() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b+=m_ShowWanB_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b;
			
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[1]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnShouwanbDown() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b-=m_ShowWanB_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b;
			
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[1]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnChangeXiaobirStep() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	// TODO: Add your control notification handler code here
	
}

void CContrl_DLG::OnXiaobirLeft() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z-=m_XiaoBiR_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z;
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[2]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[10]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);	
}


void CContrl_DLG::OnXiaobirRight() 
{
	// TODO: Add your control notification handler code here
 	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z+=m_XiaoBiR_step;
 	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z;
 	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
 	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[2]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
 	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[10]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnChangeMdStep() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	// TODO: Add your control notification handler code here
	
}

void CContrl_DLG::OnMdLeft() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z-=m_MD_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z;
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[1]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[9]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
}

void CContrl_DLG::OnMdRight() 
{
	// TODO: Add your control notification handler code here
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z+=m_MD_step;
	GLfloat tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z;
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[1]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[9]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
	((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);	
}

void CContrl_DLG::OnYanshi() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,100,NULL);
}

void CContrl_DLG::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
if(nIDEvent==1)
{
	float step=0.5;
	//旋转支座
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z!=m_AllR_step)
	{
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z;
		if(m_AllR_step<0.0||m_AllR_step<tmp)
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z-=step;
		else
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z+=step;

		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].m_rotate_z;
		
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[1].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	}
	//大臂
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b!=m_AllB_step)
	{
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b;
			if(m_AllB_step<0.0||m_AllB_step<tmp)
				((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b-=step;
			else
				((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b+=step;

		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].m_rotate_b;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[1]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[2].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	}
	//背头
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b!=m_BeiTouB_step)
	{
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b;
		if(m_BeiTouB_step<0||m_BeiTouB_step<tmp)
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b-=step;
		else
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b+=step;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].m_rotate_b;
			
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[4]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[8]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[3].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);		
	}
	//小臂旋转
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z!=m_XiaoBiR_step)
	{
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z;
		if(m_XiaoBiR_step<0||m_XiaoBiR_step<tmp)
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z-=step;
		else
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z+=step;

		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].m_rotate_z;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[0]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[2]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[8]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[5].Matrix[10]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	}
	//手腕
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b!=m_ShowWanB_step)
	{	
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b;
		if(m_ShowWanB_step<0||m_ShowWanB_step<tmp)
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b-=step;
		else
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b+=step;

		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].m_rotate_b;		
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[1]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[2]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[9]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[7].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	}
	//末端
	if(((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z!=m_MD_step)
	{
		GLfloat tmp;
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z;
		if(m_MD_step<0||m_MD_step<tmp)
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z-=step;
		else
			((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z+=step;
		
		tmp=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].m_rotate_z;
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[5]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[6]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[9]=-((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastSin(tmp);
		((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_A_c[8].Matrix[10]=((CMFC_GLApp*)AfxGetApp())->m_openGL.m_draw->m_cm.FastCos(tmp);
	}

}
	CDialog::OnTimer(nIDEvent);
}

void CContrl_DLG::OnEndYanshi() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
}

