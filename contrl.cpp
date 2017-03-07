// contrl.cpp: implementation of the Ccontrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mfc_gl.h"
#include "contrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ccontrl::Ccontrl()
{
	m_rotate_b=0.0f;
	m_rotate_z=0.0f;
	m_tx=0.0f;
	m_ty=0.0f;
	m_tz=0.0f;
	//初始化为单位矩阵
	for(int i=0;i<16;i++)
	{
		if(i%5==0)
			Matrix[i]=1;
		else
			Matrix[i]=0;
	}

}

Ccontrl::~Ccontrl()
{

}

