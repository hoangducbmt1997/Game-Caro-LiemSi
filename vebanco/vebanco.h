
// vebanco.h : main header file for the vebanco application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CvebancoApp:
// See vebanco.cpp for the implementation of this class
//

class CvebancoApp : public CWinApp
{
public:
	CvebancoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CvebancoApp theApp;
