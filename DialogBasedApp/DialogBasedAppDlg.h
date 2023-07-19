// DialogBasedAppDlg.h : header file
//

#if !defined(AFX_DIALOGBASEDAPPDLG_H__E1B49F1D_4E4D_4062_8F91_79AE4C1F975C__INCLUDED_)
#define AFX_DIALOGBASEDAPPDLG_H__E1B49F1D_4E4D_4062_8F91_79AE4C1F975C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogBasedAppDlg dialog

class CDialogBasedAppDlg : public CDialog
{
// Construction
public:
	CDialogBasedAppDlg(CWnd* pParent = NULL);	// standard constructor

		CBitmap Bmp1;
// Dialog Data
	//{{AFX_DATA(CDialogBasedAppDlg)
	enum { IDD = IDD_DIALOGBASEDAPP_DIALOG };
	CStatic	m_cPicture;
	CComboBox	m_cName;
	CEdit	m_cSecNum;
	CEdit	m_cRes;
	CEdit	m_cFirstNum;
	CButton	m_cCal;
	CEdit	m_Name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogBasedAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogBasedAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnUpdateName();
	afx_msg void OnCalculate();
	afx_msg void OnEditchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBASEDAPPDLG_H__E1B49F1D_4E4D_4062_8F91_79AE4C1F975C__INCLUDED_)
