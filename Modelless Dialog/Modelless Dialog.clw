; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CModalessDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Modelless Dialog.h"

ClassCount=5
Class1=CModellessDialogApp
Class2=CModellessDialogDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_MODELLESSDIALOG_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG
Class4=CMyDialog
Resource4=IDD_ABOUTBOX
Class5=CModalessDialog
Resource5=IDD_MODALESSDIALOG_DIALOG

[CLS:CModellessDialogApp]
Type=0
HeaderFile=Modelless Dialog.h
ImplementationFile=Modelless Dialog.cpp
Filter=N

[CLS:CModellessDialogDlg]
Type=0
HeaderFile=Modelless DialogDlg.h
ImplementationFile=Modelless DialogDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CModellessDialogDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Modelless DialogDlg.h
ImplementationFile=Modelless DialogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MODELLESSDIALOG_DIALOG]
Type=1
Class=CModellessDialogDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CALL_MY_DIALOG,button,1342242816
Control4=IDC_BUTTON1,button,1342242816

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyDialog
VirtualFilter=dWC

[DLG:IDD_MODALESSDIALOG_DIALOG]
Type=1
Class=CModalessDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EMP_ID,edit,1350631552
Control4=IDC_EMP_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CModalessDialog]
Type=0
HeaderFile=ModalessDialog.h
ImplementationFile=ModalessDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CModalessDialog

