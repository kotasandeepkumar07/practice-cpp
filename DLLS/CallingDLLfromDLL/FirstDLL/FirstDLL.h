// FirstDLL.h : main header file for the FirstDLL DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFirstDLLApp
// See FirstDLL.cpp for the implementation of this class
//

class CFirstDLLApp : public CWinApp
{
public:
	CFirstDLLApp();

// Overrides
public:
	virtual BOOL InitInstance();
	void Test();

	DECLARE_MESSAGE_MAP()
};
