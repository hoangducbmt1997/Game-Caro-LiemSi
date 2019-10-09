
// Threading.h : main header file for the Threading application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CThreadingApp:
// See Threading.cpp for the implementation of this class
//

class CThreadingApp : public CWinApp
{
public:
	CThreadingApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThreadingApp theApp;
