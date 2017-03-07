// DisplayScene.h: interface for the CDisplayScene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISPLAYSCENE_H__3F7DD40D_1BEA_460A_BAE2_5C234805C504__INCLUDED_)
#define AFX_DISPLAYSCENE_H__3F7DD40D_1BEA_460A_BAE2_5C234805C504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDisplayScene  
{
public:
	CDisplayScene();
	virtual ~CDisplayScene();
	void DisplayScene();
	//{(摄像机参数)
//目标点，视点
	GLfloat er_y,er_c,er_z;//全场景沿Y或X转动的角度
//}

	Draw *m_d;


};

#endif // !defined(AFX_DISPLAYSCENE_H__3F7DD40D_1BEA_460A_BAE2_5C234805C504__INCLUDED_)
