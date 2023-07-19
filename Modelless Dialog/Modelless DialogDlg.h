// Modelless DialogDlg.h : header file
//

#if !defined(AFX_MODELLESSDIALOGDLG_H__9C048FD0_B861_45C7_9E1B_1BC3483BB5EF__INCLUDED_)
#define AFX_MODELLESSDIALOGDLG_H__9C048FD0_B861_45C7_9E1B_1BC3483BB5EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CModellessDialogDlg dialog

class CModellessDialogDlg : public CDialog
{
// Construction
public:
	CModellessDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CModellessDialogDlg)
	enum { IDD = IDD_MODELLESSDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModellessDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support



	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CModellessDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCallMyDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELLESSDIALOGDLG_H__9C048FD0_B861_45C7_9E1B_1BC3483BB5EF__INCLUDED_)
