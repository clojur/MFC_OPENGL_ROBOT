// OpenGL.cpp: implementation of the OpenGL class.
//
//////////////////////////////////////////////////////////////////////
#include"stdafx.h"
#include "allheader.h"
#include "Draw.h"

#include "OpenGL.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpenGL::OpenGL()
{
	hDC=NULL;
	hRC=NULL;
	m_draw=new Draw();
	m_displayscene=new CDisplayScene();
}

OpenGL::~OpenGL()
{
	ClearUp();
	delete m_draw;
	delete m_displayscene;
}

bool OpenGL::SetupPixelFormat(HDC h)
{
	int nPixelFormat;
	this->hDC=h;
	PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|
		PFD_DOUBLEBUFFER,LPD_TYPE_RGBA,16,
		0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0, PFD_MAIN_PLANE,0,0,0,0
	};
	if(!(nPixelFormat=ChoosePixelFormat(hDC,&pfd)))
	{
		MessageBox(NULL,"没有找到合适的像素格式!","tips",MB_OK);
		return FALSE;
	}
	SetPixelFormat(hDC,nPixelFormat,&pfd);
	this->hRC=wglCreateContext(this->hDC);
	wglMakeCurrent(this->hDC,this->hRC);
	m_draw=new Draw();
	m_draw->Light1();
	m_draw->Material();
	return TRUE;
}

void OpenGL::ReSize(int width,int height)
{
	
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION); //透视投影
	glLoadIdentity();
	gluPerspective(45.0f,width/height,0.1f,3000.0f);//透视投影的属性设置
	glMatrixMode(GL_MODELVIEW);//模型观察矩阵
	glLoadIdentity();
	
}

void OpenGL::Render()
{
	//{初始一些东西
	glClearColor(89.0/255,135.0/255,178.0/255,1.0f);
	glShadeModel (GL_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);	 // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); 
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	glEnable(GL_DEPTH_TEST);  // Enables Depth Testing
	//glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	//}
	//{画参考标注、
	m_draw->DrawBiaoZhu();
	//}	
	

	//{视图变换
	m_displayscene->DisplayScene();
	//}

	//{模型展示	
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	m_draw->RobotModel(m_draw->m_A_c);
	//}
	
	//{绘制地面
	m_draw->Ground();
	//}
	glFlush();
	SwapBuffers(hDC);
}



void OpenGL::ClearUp()
{
	wglMakeCurrent(hDC,NULL);
	wglDeleteContext(hRC);
}

