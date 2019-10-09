
// ThreadingView.h : interface of the CThreadingView class
//

#pragma once
#include"ThreadingDoc.h"

class CThreadingView : public CView
{
protected: // create from serialization only
	CThreadingView();
	DECLARE_DYNCREATE(CThreadingView)
	CWinThread *pThread;

// Attributes
public:
	CThreadingDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CThreadingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	long m_iCounter;
	afx_msg void OnStartStart();
	afx_msg void OnStartPause();
	afx_msg void OnThreadResume();
};

#ifndef _DEBUG  // debug version in ThreadingView.cpp
inline CThreadingDoc* CThreadingView::GetDocument() const
   { return reinterpret_cast<CThreadingDoc*>(m_pDocument); }
#endif

