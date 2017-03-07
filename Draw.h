// Draw.h: interface for the Draw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAW_H__3E8BE14B_FD54_45E9_B37F_6338BBED8E65__INCLUDED_)
#define AFX_DRAW_H__3E8BE14B_FD54_45E9_B37F_6338BBED8E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#include "3DS.H"
#include "allheader.h"
#include "contrl.h"
#include "MatrixT.h"

class Draw  
{
public:		
	Draw();
	virtual ~Draw();
	//{机器人部件函数
	void RobotModel(Ccontrl* m);

	//}
	void Material();
	void Light1();


	void Ground();
	void load3dobj(char* dir,char* cn,int a);
	CLoad3DS* m_3ds;//声明解析3DS模型的对象
private:
	void InitModel();
	void InitMatrix();
	GLuint texture[1];
public:
	void zuobiao_Line();
	void DrawString(const char *str);
	void DrawBiaoZhu();
	void PrintMatrix(GLfloat *matrix);
	UINT list;//显示列表编号
	Ccontrl m_A_c[10];
	GLfloat m_Sx,m_Sy,m_Sz;
	CMatrixT m_cm;
	
};

#endif // !defined(AFX_DRAW_H__3E8BE14B_FD54_45E9_B37F_6338BBED8E65__INCLUDED_)
