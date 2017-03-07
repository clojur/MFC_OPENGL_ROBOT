#if !defined(AFX_NIJIE_DLG_H__539E20CA_06DE_4DDC_ADD6_D99488F6739E__INCLUDED_)
#define AFX_NIJIE_DLG_H__539E20CA_06DE_4DDC_ADD6_D99488F6739E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Nijie_DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNijie_DLG dialog

class CNijie_DLG : public CDialog
{
// Construction
public:
	CNijie_DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNijie_DLG)
	enum { IDD = IDD_NIJIE_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNijie_DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNijie_DLG)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NIJIE_DLG_H__539E20CA_06DE_4DDC_ADD6_D99488F6739E__INCLUDED_)
