// Test.cpp : implementation file
//

#include "stdafx.h"
#include "DialogBasedApp.h"
#include "Test.h"
#include "afxdialogex.h"
#include "resource.h"


// CTest dialog

IMPLEMENT_DYNAMIC(CTest, CDialogEx)

CTest::CTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest::IDD, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEST, m_cedtName);
}


BEGIN_MESSAGE_MAP(CTest, CDialogEx)

	ON_EN_UPDATE(IDC_EDIT_TEST,
		&CTest::OnUpdateAccountName)

	ON_EN_CHANGE(IDC_EDIT_TEST,
		&CTest::OnChangeAccountName)

END_MESSAGE_MAP()


// CTest message handlers


void CTest::OnUpdateAccountName()
{
	int i = 10;
}

void CTest::OnChangeAccountName()
{
	int i = 10;
}