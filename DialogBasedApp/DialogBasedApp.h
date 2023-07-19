// DialogBasedApp.h : main header file for the DIALOGBASEDAPP application
//

#if !defined(AFX_DIALOGBASEDAPP_H__B74A89A8_9883_4B78_8613_D7C4BFE83561__INCLUDED_)
#define AFX_DIALOGBASEDAPP_H__B74A89A8_9883_4B78_8613_D7C4BFE83561__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogBasedAppApp:
// See DialogBasedApp.cpp for the implementation of this class
//

class CDialogBasedAppApp : public CWinApp
{
public:
	CDialogBasedAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogBasedAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogBasedAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBASEDAPP_H__B74A89A8_9883_4B78_8613_D7C4BFE83561__INCLUDED_)
