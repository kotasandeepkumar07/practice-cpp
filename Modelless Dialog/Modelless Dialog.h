// Modelless Dialog.h : main header file for the MODELLESS DIALOG application
//

#if !defined(AFX_MODELLESSDIALOG_H__6CE8E541_3C72_46C7_8C90_831499250FA4__INCLUDED_)
#define AFX_MODELLESSDIALOG_H__6CE8E541_3C72_46C7_8C90_831499250FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModellessDialogApp:
// See Modelless Dialog.cpp for the implementation of this class
//

class CModellessDialogApp : public CWinApp
{
public:
	CModellessDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModellessDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CModellessDialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELLESSDIALOG_H__6CE8E541_3C72_46C7_8C90_831499250FA4__INCLUDED_)
