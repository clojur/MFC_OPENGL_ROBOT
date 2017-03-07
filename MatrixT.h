// MatrixT.h: interface for the CMatrixT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIXT_H__90EAFAD8_ED6F_4485_A023_B56EB6EBAA8C__INCLUDED_)
#define AFX_MATRIXT_H__90EAFAD8_ED6F_4485_A023_B56EB6EBAA8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMatrixT  
{
public:
	void MultMatrix(GLfloat ResultMatrix[],GLfloat CurrentMatrix[], GLfloat TransformMatrix[],BOOL show);
	void MyTranslatef(float matrix[],float x,float y,float z);
	void MyRotatef(float matrix[],float angle,float x,float y,float z);
	CMatrixT();
	virtual ~CMatrixT();
	double FastCos(double theta_du);
	double FastSin(double theta_du);

private:
	GLfloat SinTable[360];
	GLfloat CosTable[360];
	int InitSinCosTable();

};

#endif // !defined(AFX_MATRIXT_H__90EAFAD8_ED6F_4485_A023_B56EB6EBAA8C__INCLUDED_)
