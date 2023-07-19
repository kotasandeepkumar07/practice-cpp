// ModalessDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Modelless Dialog.h"
#include "ModalessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModalessDialog dialog


CModalessDialog::CModalessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CModalessDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModalessDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}




CModalessDialog::CModalessDialog(CDialog* pPointer /*=NULL*/, int a, CString b)
	: CDialog(CModalessDialog::IDD, pPointer)
{
	nEmpID = a;
	sEmpName = b;
}


void CModalessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModalessDialog)
	DDX_Control(pDX, IDC_EMP_NAME, m_cEmpName);
	DDX_Control(pDX, IDC_EMP_ID, m_cEmpID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModalessDialog, CDialog)
	//{{AFX_MSG_MAP(CModalessDialog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CModalessDialog::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModalessDialog message handlers

BOOL CModalessDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

//	AfxMessageBox(sEmpName);
	m_cEmpName.SetWindowText(sEmpName);

	CString sTemp;
	sTemp.Format("%ld", nEmpID);
	m_cEmpID.SetWindowText(sTemp);

	return TRUE;  
}


void CModalessDialog::OnOK() 
{
	
//	CDialog::OnOK();
	senddata();
	int n = DestroyWindow();
	CString sTemp;
	sTemp.Format("%ld", n);
}

void CModalessDialog::OnCancel() 
{
	DestroyWindow();
	//CDialog::OnCancel();
}

void CModalessDialog::PostNcDestroy() 
{	
	CDialog::PostNcDestroy();
	delete this;
}

CString  CModalessDialog::senddata()
{
	CString szTemp;
	m_cEmpID.GetWindowText(szTemp);		

	AfxMessageBox(szTemp);

	GetParent()->SendMessage(UWM_CUSTOM_MESSAGE, (WPARAM)&szTemp, 0);

	return (szTemp);
}

void CModalessDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
