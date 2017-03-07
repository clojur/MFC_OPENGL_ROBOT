// MatrixT.cpp: implementation of the CMatrixT class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mfc_gl.h"
#include "MatrixT.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define PI 3.1415926536

CMatrixT::CMatrixT()
{
	InitSinCosTable();
}

CMatrixT::~CMatrixT()
{

}

int CMatrixT::InitSinCosTable()
{
	for (int ang = 0; ang < 360; ++ang)  
    {  
        double theta = (double)ang * PI / (double)180;  
        CosTable[ang] = cos(theta);  
        SinTable[ang] = sin(theta);  
    }  
    return 1;
}

double CMatrixT::FastCos(double theta_du)
{
	    // 对可能的正负小数取模  
    theta_du = fmod(theta_du, 360);  
  
    // 将负角度转正  
    if (theta_du < 0)  
    {  
        theta_du += 360.0;  
    }  
  
    // 对小数和整数部分分别处理  
    int theta_int = int(theta_du);  
    double theta_frac = theta_du - theta_int;  
  
    // 插值  
    double result = CosTable[theta_int] + theta_frac * (CosTable[theta_int+1] - CosTable[theta_int]);  
    return result; 
}

double CMatrixT::FastSin(double theta_du)
{
	 // 对可能的正负小数取模  
    theta_du = fmod(theta_du, 360);  
  
    // 将负角度转正  
    if (theta_du < 0)  
    {  
        theta_du += 360.0;  
    }  
  
    // 对小数和整数部分分别处理  
    int theta_int = int(theta_du);  
    double theta_frac = theta_du - theta_int;  
  
    // 插值  
    double result = SinTable[theta_int] + theta_frac * (SinTable[theta_int+1] - SinTable[theta_int]);  
    return result;  
}


void CMatrixT::MyRotatef(float matrix[], float angle, float x, float y, float z)
{
	if(matrix==NULL)
	{
		AfxMessageBox("错误，矩阵为空!");
		return;
	}
    // 向量的单位化
    float length = sqrt( x * x + y * y + z * z );
    if(length==0)
	{
		AfxMessageBox("错误，单位向量为0!");
		return;
	}

    x /= length;
    y /= length;
    z /= length;
    float s =FastSin(angle);
    float c =FastCos(angle);
    float t = 1.0f - c;
	
#define MATRIX( row, col ) matrix[row * 4 + col]  
    MATRIX( 0, 0 ) = t * x * x + c;  
    MATRIX( 0, 1 ) = t * x * y + s * z;  
    MATRIX( 0, 2 ) = t * x * z - s * y;  
    MATRIX( 0, 3 ) = 0.0f;  
    MATRIX( 1, 0 ) = t * x * y - s * z;  
    MATRIX( 1, 1 ) = t * y * y + c;  
    MATRIX( 1, 2 ) = t * y * z + s * x;  
    MATRIX( 1, 3 ) = 0.0f;  
    MATRIX( 2, 0 ) = t * x * z + s * y;  
    MATRIX( 2, 1 ) = t * y * z - s * x;  
    MATRIX( 2, 2 ) = t * z * z + c;  
    MATRIX( 2, 3 ) = 0.0f;  
    MATRIX( 3, 0 ) = 0.0f;  
    MATRIX( 3, 1 ) = 0.0f;  
    MATRIX( 3, 2 ) = 0.0f;  
    MATRIX( 3, 3 ) = 1.0f;  
#undef MATRIX 
}

void CMatrixT::MyTranslatef(float matrix[], float x, float y, float z)
{
	for(int i=0;i<16;i++)
	{
		if(i%5==0)
			matrix[i]=1.0;
		else
			matrix[i]=0.0;
	}
	matrix[12]+=x;
	matrix[13]+=y;
	matrix[14]+=z;
}

void CMatrixT::MultMatrix(GLfloat ResultMatrix[],GLfloat CurrentMatrix[], GLfloat TransformMatrix[],BOOL show)
{
#define CURRENT_MATRIX(row,col) CurrentMatrix[row*4+col]
#define TRANSFORM_MATRIX(row,col) TransformMatrix[row*4+col]
#define RESULT_MATRIX(row,col) ResultMatrix[row*4+col]
	
	//初始化结果矩阵
	for(int i1=0;i1<16;i1++)
	{
		ResultMatrix[i1]=0;
	}
	for(int j2=0;j2<4;++j2)
		for(int j1=0;j1<4;++j1)
				for(int j=0;j<4;++j)
				{
					RESULT_MATRIX(j2,j1)+=TRANSFORM_MATRIX(j2,j)*CURRENT_MATRIX(j,j1);
				}
#undef CURRENT_MATRIX
#undef TRANSFORM_MATRIX
#undef RESULT_MATRIX
	if(show)
	{
		glLoadMatrixf(ResultMatrix);
	}
}
