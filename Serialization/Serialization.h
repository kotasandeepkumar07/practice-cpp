// Serialization.h : main header file for the SERIALIZATION application
//

#if !defined(AFX_SERIALIZATION_H__7CD8078D_4371_433F_A20D_706AAE1663EE__INCLUDED_)
#define AFX_SERIALIZATION_H__7CD8078D_4371_433F_A20D_706AAE1663EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerializationApp:
// See Serialization.cpp for the implementation of this class
//

class CSerializationApp : public CWinApp
{
public:
	CSerializationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSerializationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

 // !defined(AFX_SERIALIZATION_H__7CD8078D_4371_433F_A20D_706AAE1663EE__INCLUDED_)
;

#endif