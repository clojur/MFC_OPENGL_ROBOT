// contrl.h: interface for the Ccontrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTRL_H__FB469167_7FAD_4873_B234_EB8CA247DAD3__INCLUDED_)
#define AFX_CONTRL_H__FB469167_7FAD_4873_B234_EB8CA247DAD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Ccontrl  
{
public:
	GLfloat m_tx;
	GLfloat m_ty;
	GLfloat m_tz;
	GLfloat m_rotate_z;
	GLfloat m_rotate_b;
	GLfloat Matrix[16];
	
	Ccontrl();
	virtual ~Ccontrl();
};

#endif // !defined(AFX_CONTRL_H__FB469167_7FAD_4873_B234_EB8CA247DAD3__INCLUDED_)
