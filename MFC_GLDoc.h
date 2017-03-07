// MFC_GLDoc.h : interface of the CMFC_GLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_GLDOC_H__BC76FC90_18D6_47C2_80F2_E53851B36543__INCLUDED_)
#define AFX_MFC_GLDOC_H__BC76FC90_18D6_47C2_80F2_E53851B36543__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_GLDoc : public CDocument
{
protected: // create from serialization only
	CMFC_GLDoc();
	DECLARE_DYNCREATE(CMFC_GLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_GLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_GLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_GLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_GLDOC_H__BC76FC90_18D6_47C2_80F2_E53851B36543__INCLUDED_)
