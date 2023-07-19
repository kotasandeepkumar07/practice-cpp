#if !defined(AFX_MODALESSDIALOG_H__BCA50BD5_86B6_4E2E_95E7_F0F5F70BFD0D__INCLUDED_)
#define AFX_MODALESSDIALOG_H__BCA50BD5_86B6_4E2E_95E7_F0F5F70BFD0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModalessDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModalessDialog dialog

class CModalessDialog : public CDialog
{
// Construction
public:
	CModalessDialog(CWnd* pParent = NULL);   // standard constructor
	CModalessDialog(CDialog* pPointer = NULL, int a = 0, CString b = 's');   
// Dialog Data
	//{{AFX_DATA(CModalessDialog)
	enum { IDD = IDD_MODALESSDIALOG_DIALOG };
	CEdit	m_cEmpName;
	CEdit	m_cEmpID;
	int nEmpID;
	CString sEmpName ;

	CString senddata();
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModalessDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModalessDialog)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODALESSDIALOG_H__BCA50BD5_86B6_4E2E_95E7_F0F5F70BFD0D__INCLUDED_)
