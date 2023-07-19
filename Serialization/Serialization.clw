; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSerializationDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Serialization.h"

ClassCount=3
Class1=CSerializationApp
Class2=CSerializationDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SERIALIZATION_DIALOG

[CLS:CSerializationApp]
Type=0
HeaderFile=Serialization.h
ImplementationFile=Serialization.cpp
Filter=N

[CLS:CSerializationDlg]
Type=0
HeaderFile=SerializationDlg.h
ImplementationFile=SerializationDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ID

[CLS:CAboutDlg]
Type=0
HeaderFile=SerializationDlg.h
ImplementationFile=SerializationDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERIALIZATION_DIALOG]
Type=1
Class=CSerializationDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_AGE,edit,1350631552
Control7=IDC_DESERIALIZE,button,1342242816

