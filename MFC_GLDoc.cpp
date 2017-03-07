// MFC_GLDoc.cpp : implementation of the CMFC_GLDoc class
//

#include "stdafx.h"
#include "MFC_GL.h"

#include "MFC_GLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLDoc

IMPLEMENT_DYNCREATE(CMFC_GLDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_GLDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_GLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLDoc construction/destruction

CMFC_GLDoc::CMFC_GLDoc()
{
	// TODO: add one-time construction code here

}

CMFC_GLDoc::~CMFC_GLDoc()
{
}

BOOL CMFC_GLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_GLDoc serialization

void CMFC_GLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLDoc diagnostics

#ifdef _DEBUG
void CMFC_GLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_GLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLDoc commands
