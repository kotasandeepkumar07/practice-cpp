// MyThreadDlg.h : header file
//

#if !defined(AFX_MYTHREADDLG_H__F3C0D998_2F49_428B_AF51_309BB028DF53__INCLUDED_)
#define AFX_MYTHREADDLG_H__F3C0D998_2F49_428B_AF51_309BB028DF53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyThreadDlg dialog

class CMyThreadDlg : public CDialog
{
// Construction
public:
	CMyThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyThreadDlg)
	enum { IDD = IDD_MYTHREAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREADDLG_H__F3C0D998_2F49_428B_AF51_309BB028DF53__INCLUDED_)
