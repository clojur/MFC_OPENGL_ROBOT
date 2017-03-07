#if !defined(AFX_CONTRL_DLG_H__950CFB2B_D537_4775_97AC_D35EAC2AF8F3__INCLUDED_)
#define AFX_CONTRL_DLG_H__950CFB2B_D537_4775_97AC_D35EAC2AF8F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Contrl_DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContrl_DLG dialog

class CContrl_DLG : public CDialog
{
// Construction
public:
	CContrl_DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CContrl_DLG)
	enum { IDD = IDD_CONTRL_DLG };
	float	m_model_x;
	float	m_model_y;
	float	m_model_z;
	float	m_AllR_step;
	float	m_AllB_step;
	float	m_BeiTouB_step;
	float	m_ShowWanB_step;
	float	m_XiaoBiR_step;
	float	m_MD_step;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContrl_DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CContrl_DLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnTranslate();
	afx_msg void OnAllRight();
	afx_msg void OnAllLeft();
	afx_msg void OnChangeAllrStep();
	afx_msg void OnChangeAllbStep();
	afx_msg void OnAllBUP();
	afx_msg void OnAllBDOWN();
	afx_msg void OnChangeBeitoubStep();
	afx_msg void OnBeitoubUp();
	afx_msg void OnBeitoubDown();
	afx_msg void OnChangeShouwanbStep();
	afx_msg void OnShouwanbUp();
	afx_msg void OnShouwanbDown();
	afx_msg void OnChangeXiaobirStep();
	afx_msg void OnXiaobirLeft();
	afx_msg void OnXiaobirRight();
	afx_msg void OnYanshi();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEndYanshi();
	afx_msg void OnChangeMdStep();
	afx_msg void OnMdLeft();
	afx_msg void OnMdRight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	GLfloat tmpMatrix[16];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTRL_DLG_H__950CFB2B_D537_4775_97AC_D35EAC2AF8F3__INCLUDED_)
