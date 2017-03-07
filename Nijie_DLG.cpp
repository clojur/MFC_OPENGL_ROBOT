// Nijie_DLG.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_gl.h"
#include "Nijie_DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNijie_DLG dialog


CNijie_DLG::CNijie_DLG(CWnd* pParent /*=NULL*/)
	: CDialog(CNijie_DLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNijie_DLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNijie_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNijie_DLG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNijie_DLG, CDialog)
	//{{AFX_MSG_MAP(CNijie_DLG)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNijie_DLG message handlers
