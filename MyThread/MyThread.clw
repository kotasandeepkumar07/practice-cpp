; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyThread
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyThread.h"

ClassCount=5
Class1=CMyThreadApp
Class2=CMyThreadDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CMyThread
Resource3=IDD_MYTHREAD_DIALOG

[CLS:CMyThreadApp]
Type=0
HeaderFile=MyThread.h
ImplementationFile=MyThread.cpp
Filter=N

[CLS:CMyThreadDlg]
Type=0
HeaderFile=MyThreadDlg.h
ImplementationFile=MyThreadDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=MyThreadDlg.h
ImplementationFile=MyThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYTHREAD_DIALOG]
Type=1
Class=CMyThreadDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CMyThread]
Type=0
HeaderFile=MyThread1.h
ImplementationFile=MyThread1.cpp
BaseClass=CWinThread
Filter=N

