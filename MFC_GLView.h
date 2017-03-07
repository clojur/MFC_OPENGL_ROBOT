// MFC_GLView.h : interface of the CMFC_GLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_GLVIEW_H__5E4E4133_8A44_41A8_9B31_3882F7160FE4__INCLUDED_)
#define AFX_MFC_GLVIEW_H__5E4E4133_8A44_41A8_9B31_3882F7160FE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_GLView : public CView
{
protected: // create from serialization only
	
	DECLARE_DYNCREATE(CMFC_GLView)

// Attributes
public:
	CMFC_GLDoc* GetDocument();
	
// Operations
public:
	CMFC_GLView();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_GLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_GLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_GLView)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContrlModel();
	afx_msg void OnNicontrl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_GLView.cpp
inline CMFC_GLDoc* CMFC_GLView::GetDocument()
   { return (CMFC_GLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_GLVIEW_H__5E4E4133_8A44_41A8_9B31_3882F7160FE4__INCLUDED_)
