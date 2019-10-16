#pragma once
#define max 100
class oco
{
private:
	int x1,y1,x2,y2;
public:
	void hamtest();
	CPoint point1,point2;
	void setup(int mx1, int my1, int mx2, int my2);
	void draw(CClientDC *pDC);
	void drawX(CClientDC *pDC);
	void drawO(CClientDC *pDC);
	int boxcheck(CPoint p1);
	int checkToWin(int arr[][max], int i, int j);
	int getA();
	int getC();
	oco(void);
	~oco(void);
};

