// TestThread.cpp : implementation file
//

#include "stdafx.h"
#include "Threading.h"
#include "TestThread.h"
#include"ThreadingView.h"

// CTestThread

IMPLEMENT_DYNCREATE(CTestThread, CWinThread)

CTestThread::CTestThread()
{
}

CTestThread::~CTestThread()
{
}

BOOL CTestThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTestThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTestThread, CWinThread)
END_MESSAGE_MAP()


// CTestThread message handlers


UINT CTestThread::RunThreadFunciton(LPVOID param)
{
	CThreadingView *pThreadingView =(CThreadingView *) param;
	while (1)
	{
		pThreadingView->m_iCounter++;
		pThreadingView->Invalidate();
		Sleep(500);
	}
}
