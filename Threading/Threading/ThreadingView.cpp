
// ThreadingView.cpp : implementation of the CThreadingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Threading.h"
#endif

#include "ThreadingDoc.h"
#include "ThreadingView.h"
#include"TestThread.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThreadingView

IMPLEMENT_DYNCREATE(CThreadingView, CView)

BEGIN_MESSAGE_MAP(CThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_START_PAUSE, &CThreadingView::OnStartStart)
	ON_COMMAND(ID_START_RESUME, &CThreadingView::OnStartPause)
	ON_COMMAND(ID_THREAD_RESUME, &CThreadingView::OnThreadResume)
END_MESSAGE_MAP()

// CThreadingView construction/destruction

CThreadingView::CThreadingView()
	//: m_iCounter(0)
{
	// TODO: add construction code here
	m_iCounter=0;
}

CThreadingView::~CThreadingView()
{
}

BOOL CThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CThreadingView drawing

void CThreadingView::OnDraw(CDC* pDC)
{
	CThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString strCounter;
	strCounter.Format(L"The Counter is %d",m_iCounter);
	pDC->TextOut(200,200,strCounter);
	// TODO: add draw code for native data here
}


// CThreadingView printing

BOOL CThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CThreadingView diagnostics

#ifdef _DEBUG
void CThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThreadingDoc* CThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThreadingDoc)));
	return (CThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CThreadingView message handlers


void CThreadingView::OnStartStart()
{
	// TODO: Add your command handler code here
	pThread=AfxBeginThread(CTestThread::RunThreadFunciton,this);
}


void CThreadingView::OnStartPause()
{
	// TODO: Add your command handler code here
	pThread->SuspendThread();
}


void CThreadingView::OnThreadResume()
{
	// TODO: Add your command handler code here
	pThread->ResumeThread();
}
