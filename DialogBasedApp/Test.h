#pragma once
#include "afxwin.h"


// CTest dialog

class CTest : public CDialogEx
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTest();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	void OnUpdateAccountName();
	void OnChangeAccountName();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cedtName;
};
