// MFC_GL.h : main header file for the MFC_GL application
//

#if !defined(AFX_MFC_GL_H__6187301F_60A5_4ADC_80B4_F2EA9581D975__INCLUDED_)
#define AFX_MFC_GL_H__6187301F_60A5_4ADC_80B4_F2EA9581D975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "OpenGL.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_GLApp:
// See MFC_GL.cpp for the implementation of this class
//

class CMFC_GLApp : public CWinApp
{
public:
	CMFC_GLApp();
	OpenGL m_openGL;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_GLApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_GLApp)
	afx_msg void OnAppAbout();
	afx_msg void OnZhushitu();
	afx_msg void OnZuoshitu();
	afx_msg void OnFushitu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_GL_H__6187301F_60A5_4ADC_80B4_F2EA9581D975__INCLUDED_)
