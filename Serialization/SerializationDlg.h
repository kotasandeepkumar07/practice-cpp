// SerializationDlg.h : header file
//

#if !defined(AFX_SERIALIZATIONDLG_H__8004F9A3_B6E2_4D39_BF4A_132CB3683BBF__INCLUDED_)
#define AFX_SERIALIZATIONDLG_H__8004F9A3_B6E2_4D39_BF4A_132CB3683BBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSerializationDlg dialog

class CSerializationDlg : public CDialog
{
// Construction
public:
	CSerializationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSerializationDlg)
	enum { IDD = IDD_SERIALIZATION_DIALOG };
	CEdit	m_cAge;
	CEdit	m_cID;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSerializationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnDeserialize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#pragma once
class CUser : public CObject
{
    DECLARE_SERIAL(CUser);
public:
    CUser();
	void Serialize(CArchive& ar);

	int m_cEmpID;
	int m_cAge;
 };

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALIZATIONDLG_H__8004F9A3_B6E2_4D39_BF4A_132CB3683BBF__INCLUDED_)
