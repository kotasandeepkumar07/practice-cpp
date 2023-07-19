// MyThread.h : main header file for the MYTHREAD application
//

#if !defined(AFX_MYTHREAD_H__0B0FBAEC_CCF2_4CAE_8AB3_CCFED0CBC796__INCLUDED_)
#define AFX_MYTHREAD_H__0B0FBAEC_CCF2_4CAE_8AB3_CCFED0CBC796__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyThreadApp:
// See MyThread.cpp for the implementation of this class
//

class CMyThreadApp : public CWinApp
{
public:
	CMyThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREAD_H__0B0FBAEC_CCF2_4CAE_8AB3_CCFED0CBC796__INCLUDED_)
