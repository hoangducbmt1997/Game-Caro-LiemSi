
// vebancoView.cpp : implementation of the CvebancoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vebanco.h"
#endif

#include "vebancoDoc.h"
#include "vebancoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CvebancoView

IMPLEMENT_DYNCREATE(CvebancoView, CView)

BEGIN_MESSAGE_MAP(CvebancoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CvebancoView construction/destruction

CvebancoView::CvebancoView()
{
	// TODO: add construction code here
	size = 30;
	playercount = 0,condition = 1;
	row = 30;
	column = 30;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = 0;
}

CvebancoView::~CvebancoView()
{
}

BOOL CvebancoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CvebancoView drawing
void valueview(CClientDC *pDC,int arr[][max],int row,int column)
{
	CString text;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			text.Format(_T("%d"), arr[i][j]);
			pDC->TextOutW(1000 + j * 10, 100 + i * 15, text);
		}
	}
}
void CvebancoView::OnDraw(CDC* /*pDC*/)
{
	CvebancoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <column; j++)
		{
			oco[i][j].setup(j*size, i*size, size + j*size, size + i*size);
			oco[i][j].draw(&pDC);
		}
	}
	
	CString strcountplayer,strplayerwin,GameName;
	GameName = " GAME CARO";
	strplayerwin = "Player Win Is : ";
	strcountplayer = "Player :";
	pDC.TextOutW(1000, 70, GameName);
	pDC.TextOutW(1000, 100, strplayerwin);
	pDC.TextOutW(1000, 120, strcountplayer);


	//valueview(&pDC, arr);
	// TODO: add draw code for native data here
}


// CvebancoView printing

BOOL CvebancoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CvebancoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CvebancoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CvebancoView diagnostics

#ifdef _DEBUG
void CvebancoView::AssertValid() const
{
	CView::AssertValid();
}

void CvebancoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvebancoDoc* CvebancoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvebancoDoc)));
	return (CvebancoDoc*)m_pDocument;
}
#endif //_DEBUG


// CvebancoView message handlers


void CvebancoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	int flag=0;
	p1.x = point.x;
	p1.y = point.y;
	CString player,playerwin,funny;
	funny = "Bai lam chi mang tinh chat lay lai liem si cho ban than =))";
	//CString array;
	player.Format(_T("%d"),playercount);
	CClientDC pDC(this);
	CBrush *redbrush = new CBrush(RGB(255, 0, 0));
	CBrush *greenbrush = new CBrush(RGB(0, 255, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (oco[i][j].boxcheck(p1) == 1 && playercount % 2 == 0 && condition == 1 && arr[i][j]==0 && arr[i][j] != 2)
			{
				pDC.SelectObject(redbrush);
				oco[i][j].draw(&pDC);
				oco[i][j].drawX(&pDC);
				pDC.TextOutW(1055, 120, player);
				arr[i][j] = 1;
				playercount++;
				//array.Format(_T("%d"), oco[i][j].checkToWin(arr, i, j));
				
			}
			else if (oco[i][j].boxcheck(p1) == 1 && playercount % 2 != 0 && condition == 1 && arr[i][j] == 0 && arr[i][j] != 1)
			{
				pDC.SelectObject(greenbrush);
				oco[i][j].draw(&pDC);
				oco[i][j].drawO(&pDC);
				pDC.TextOutW(1055, 120, player);
				arr[i][j] = 2;
				playercount++;
				//array.Format(_T("%d"), oco[i][j].checkToWin(arr, i, j));
			}
			
			if (oco[i][j].boxcheck(p1) == 1 && oco[i][j].checkToWin(arr,i,j)==1)
			{
				flag = 1;
				pDC.TextOutW(1100, 100, player);
				pDC.TextOutW(950, 150, funny);
			}
		}
		CString str, text;
	}
	if (flag == 1)
	{
		condition = 0;
	}
	playercount = playercount % 2;
	CView::OnLButtonDown(nFlags, point);
}
