
// soroMfcExRedrawDemo.h : main header file for the soroMfcExRedrawDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CsoroMfcExRedrawDemoApp:
// See soroMfcExRedrawDemo.cpp for the implementation of this class
//

class CsoroMfcExRedrawDemoApp : public CWinApp
{
public:
	CsoroMfcExRedrawDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsoroMfcExRedrawDemoApp theApp;
