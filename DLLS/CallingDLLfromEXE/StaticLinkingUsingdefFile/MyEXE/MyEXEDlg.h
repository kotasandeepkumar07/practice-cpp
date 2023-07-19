
// MyEXEDlg.h : header file
//
#include "..\\SHARED_LIB\include\APICalls.h"

#pragma once


// CMyEXEDlg dialog
class CMyEXEDlg : public CDialogEx
{
// Construction
public:
	CMyEXEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYEXE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCallDll();
};
