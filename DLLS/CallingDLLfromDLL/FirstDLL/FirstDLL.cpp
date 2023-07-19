// FirstDLL.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "FirstDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CFirstDLLApp

BEGIN_MESSAGE_MAP(CFirstDLLApp, CWinApp)
END_MESSAGE_MAP()


// CFirstDLLApp construction

CFirstDLLApp::CFirstDLLApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CFirstDLLApp object

CFirstDLLApp theApp;


// CFirstDLLApp initialization

BOOL CFirstDLLApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

void CFirstDLLApp::Test()
{
	AfxMessageBox(_T("Hi Iam First in DLL"));

	typedef void(CALLBACK* LPFNDLLFUNC1)();

	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer

	hDLL = LoadLibrary(_T("E:\\Samples\\DLLS\\CallingDLLfromDLL\\SecondDLL\\Debug\\SecondDLL.dll"));

	if (hDLL)
	{
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "Myfunction");
		DWORD derror = GetLastError();
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
}