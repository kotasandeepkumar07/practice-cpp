#if !defined(AFX_MYDIALOG_H__8D679B6C_81BB_42B4_8166_B51C4A0FF227__INCLUDED_)
#define AFX_MYDIALOG_H__8D679B6C_81BB_42B4_8166_B51C4A0FF227__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog

class CMyDialog : public CDialog
{
// Construction
public:
	CMyDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDialog)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDialog)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDIALOG_H__8D679B6C_81BB_42B4_8166_B51C4A0FF227__INCLUDED_)
