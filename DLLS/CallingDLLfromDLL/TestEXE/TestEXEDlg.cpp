
// TestEXEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestEXE.h"
#include "TestEXEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestEXEDlg dialog



CTestEXEDlg::CTestEXEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestEXEDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestEXEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestEXEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALL_DLL, &CTestEXEDlg::OnBnClickedCallDll)
END_MESSAGE_MAP()


// CTestEXEDlg message handlers

BOOL CTestEXEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestEXEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestEXEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestEXEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestEXEDlg::OnBnClickedCallDll()
{

	/*
	typedef void (* FindArtistType)();
	BOOL freeResult, runTimeLinkSuccess = FALSE;
	HINSTANCE dllHandle = NULL;
	FindArtistType FindArtistPtr = NULL;

	//Load the dll and keep the handle to it
	dllHandle = LoadLibrary(_T("E:\\Samples\\DLLS\\CallingDLLfromDLL\\FirstDLL\\Debug\\FirstDLL.dll"));



	// If the handle is valid, try to get the function address. 
	if (NULL != dllHandle)
	{
		//Get pointer to our function using GetProcAddress:
		FindArtistPtr = (FindArtistType)GetProcAddress(dllHandle, "Test");


		// If the function address is valid, call the function. 
		if (FindArtistPtr == NULL)
		{
			
		}
		else
		{
			FindArtistPtr;
		}

		//Free the library:

		freeResult = FreeLibrary(dllHandle);
	}

	//If unable to call the DLL function, use an alternative. 
	if (!runTimeLinkSuccess)
		printf("message via alternative method\n");
	*/

	
	
	/*
	typedef void(CALLBACK* LPFNDLLFUNC1)();

	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer

	hDLL = LoadLibrary(_T("E:\\Samples\\DLLS\\CallingDLLfromDLL\\FirstDLL\\Debug\\FirstDLL.dll"));
	{
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "Test");
		if (!lpfnDllFunc1)
		{
			// handle the error
			FreeLibrary(hDLL);
		}
		else
		{
			 lpfnDllFunc1();
		}
	}

	*/




}
