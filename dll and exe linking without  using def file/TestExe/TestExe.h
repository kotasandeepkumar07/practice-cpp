// TestExe.h : main header file for the TESTEXE application
//

#if !defined(AFX_TESTEXE_H__6953E117_481E_4935_AE6D_0FF7FB4EF742__INCLUDED_)
#define AFX_TESTEXE_H__6953E117_481E_4935_AE6D_0FF7FB4EF742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestExeApp:
// See TestExe.cpp for the implementation of this class
//

class CTestExeApp : public CWinApp
{
public:
	CTestExeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestExeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestExeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTEXE_H__6953E117_481E_4935_AE6D_0FF7FB4EF742__INCLUDED_)
