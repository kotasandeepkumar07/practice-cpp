// SecondDLL.h : main header file for the SecondDLL DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSecondDLLApp
// See SecondDLL.cpp for the implementation of this class
//

class CSecondDLLApp : public CWinApp
{
public:
	CSecondDLLApp();

// Overrides
public:
	virtual BOOL InitInstance();
	void Myfunction();

	DECLARE_MESSAGE_MAP()
};
