// OpenGL.h: interface for the OpenGL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGL_H__A7718C5E_151B_41EE_A066_B1753339F373__INCLUDED_)
#define AFX_OPENGL_H__A7718C5E_151B_41EE_A066_B1753339F373__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Draw.h"
#include "DisplayScene.h"
class OpenGL  
{
public:

	OpenGL();
	virtual ~OpenGL();
	HDC hDC;
	HGLRC hRC;
	bool SetupPixelFormat(HDC h);
	void ReSize(int width,int height);
	void Render();
	void ClearUp();
	Draw *m_draw;
	CDisplayScene *m_displayscene;
	
private:
};

#endif // !defined(AFX_OPENGL_H__A7718C5E_151B_41EE_A066_B1753339F373__INCLUDED_)
