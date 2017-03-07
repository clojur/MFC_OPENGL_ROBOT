// DisplayScene.cpp: implementation of the CDisplayScene class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mfc_gl.h"
#include "DisplayScene.h"
#include "Draw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDisplayScene::CDisplayScene()
{
	//{{视点位置，观察矩阵位置
	er_y=0.0f;
	er_z=0.0f;
	er_c=0.0f;
	//}}
	m_d=new Draw();
}

CDisplayScene::~CDisplayScene()
{

}

void CDisplayScene::DisplayScene()
{
	GLfloat speed=0.2;
	//glDisable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
	glLoadIdentity();	
	if(KEY_DOWN(0x51))er_y-=speed;//(Q/E)左右旋转
	if(KEY_DOWN(0X45))er_y+=speed;
	if(er_z==0.0)//控制左视图和主视图
	{
		glTranslatef(0.0,-4,-16.0f);
		glRotatef(er_y,0,1,0);
		
	}
	else//控制俯视图
	{
		glTranslatef(0.0,0.0,-20.0f);
		glRotatef(er_c,0.0,1.0,0.0);
		glRotatef(er_z,0.0f,0.0f,1.0f);
	}

}
