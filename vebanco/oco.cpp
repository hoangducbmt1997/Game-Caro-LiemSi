#include "stdafx.h"
#include "oco.h"

void oco::hamtest()
{
	//khong co gi o trong dau ca
}
void oco::setup(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;x2=mx2;y2=my2;
}
void oco::draw(CClientDC *pDC)
{
	pDC->Rectangle(x1,y1,x2,y2);
}
void oco::drawX(CClientDC *pDC)
{
	pDC->MoveTo(x1 + 5, y1 + 5);
	pDC->LineTo(x2 - 5, y2 - 5);
	pDC->MoveTo(x2 - 5, y1 + 5);
	pDC->LineTo(x1 + 5, y2 - 5);
}
void oco::drawO(CClientDC *pDC)
{
	pDC->Ellipse(x1+5, y1+5, x2-5, y2-5);
}
int oco::boxcheck(CPoint p1)
{
	if (p1.x >= x1 && p1.x <= x2 && p1.y >= y1 && p1.y <= y2)
		return 1;
	else
		return 0;
}
int oco::checkToWin(int arr[][max], int I, int J)
{
	int row = 30, column = 30;
	int result = 0;
	int diagonalsum1 = 0, diagonalsum2 = 0, vertical = 0, horizontal = 0;
	int i = 0, j = 0, value = 0;
	i = I;
	j = J;
	value = arr[I][J];

	while (i >=0 && j >= 0 && arr[i][j]==value)
	{
		diagonalsum1++;
		i--;
		j--;
	}
	i = I + 1;
	j = J + 1;
	while (i < row && j < column && value == arr[i][j])
	{
		diagonalsum1++;
		i++;
		j++;
	}
	//ok
	i = I;
	j = J;
	while (i >= 0 && j < column &&  value == arr[i][j])
	{
		diagonalsum2++;
		i--;
		j++;
	}
	i = I + 1;
	j = J - 1;
	while (j >= 0 && i < row && value == arr[i][j])
	{
		diagonalsum2++;
		i++;
		j--;
	}
	//ok

	
	i = I;
	j = J;
	while (i >= 0 && value == arr[i][j])
	{
		vertical++;
		i--;
	}
	i = I + 1;
	j = J;
	while (i < row && arr[i][j] == value)
	{
		vertical++;
		i++;
	}

	//ok
	
	i = I;
	j = J;
	while (j >= 0 && arr[i][j] == value)
	{
		horizontal++;
		j--;
	}
	i = I;
	j = J+1;
	while (j < column && arr[i][j] == value)
	{
		horizontal++;
		j++;
	}
	if (diagonalsum1 == 4 || diagonalsum2 == 4 || vertical == 4 || horizontal == 4)
	{
		result = 1;
	}
	return result;
}
int oco::getA()
{
	return(x2 - x1) / 2;
}
int oco::getC()
{
	return(y2 - y1) / 2;
}
oco::oco(void)
{

}
oco::~oco(void)
{

}
