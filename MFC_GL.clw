; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CContrl_DLG
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mfc_gl.h"
LastPage=0

ClassCount=7
Class1=CMainFrame
Class2=CMFC_GLApp
Class3=CAboutDlg
Class4=CMFC_GLDoc
Class5=CMFC_GLView

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class6=CContrl_DLG
Resource3=IDD_CONTRL_DLG
Class7=CNijie_DLG
Resource4=IDD_NIJIE_DLG

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CMFC_GLApp]
Type=0
BaseClass=CWinApp
HeaderFile=MFC_GL.h
ImplementationFile=MFC_GL.cpp
Filter=N
VirtualFilter=AC
LastObject=IDM_FUSHITU

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MFC_GL.cpp
ImplementationFile=MFC_GL.cpp
LastObject=IDM_INITVIEW

[CLS:CMFC_GLDoc]
Type=0
BaseClass=CDocument
HeaderFile=MFC_GLDoc.h
ImplementationFile=MFC_GLDoc.cpp

[CLS:CMFC_GLView]
Type=0
BaseClass=CView
HeaderFile=MFC_GLView.h
ImplementationFile=MFC_GLView.cpp
Filter=C
VirtualFilter=VWC
LastObject=IDM_FUSHITU

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMFC_GLView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_VIEW_STATUS_BAR
Command11=ID_APP_ABOUT
Command12=IDM_ZHUSHITU
Command13=IDM_ZUOSHITU
Command14=IDM_FUSHITU
Command15=IDM_NICONTRL
Command16=IDM_CONTRL_MODEL
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_CONTRL_DLG]
Type=1
Class=CContrl_DLG
ControlCount=44
Control1=IDC_EDIT_Z,edit,1350631552
Control2=IDC_EDIT_Y,edit,1350631552
Control3=IDC_EDIT_X,edit,1350631552
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CURRENT_COORD,static,1342308608
Control9=IDC_STATIC,button,1342177287
Control10=IDC_TRANSLATE,button,1342242816
Control11=IDC_ALL_LEFT,button,1342242816
Control12=IDC_ALL_RIGHT,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_ALLR_STEP,edit,1350631552
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_ALLB_STEP,edit,1350631552
Control18=IDC_AllB_UP,button,1342242816
Control19=IDC_AllB_DOWN,button,1342242816
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_BEITOUB_STEP,edit,1350631552
Control25=IDC_BEITOUB_UP,button,1342242816
Control26=IDC_BEITOUB_DOWN,button,1342242816
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,static,1342308352
Control29=IDC_SHOUWANB_STEP,edit,1350631552
Control30=IDC_SHOUWANB_UP,button,1342242816
Control31=IDC_SHOUWANB_DOWN,button,1342242816
Control32=IDC_XIAOBIR_LEFT,button,1342242816
Control33=IDC_XIAOBIR_RIGHT,button,1342242816
Control34=IDC_STATIC,static,1342308352
Control35=IDC_XIAOBIR_STEP,edit,1350631552
Control36=IDC_STATIC,button,1342177287
Control37=IDC_STATIC,button,1342177287
Control38=IDC_MD_LEFT,button,1342242816
Control39=IDC_MD_RIGHT,button,1342242816
Control40=IDC_STATIC,static,1342308352
Control41=IDC_MD_STEP,edit,1350631552
Control42=IDC_STATIC,button,1342177287
Control43=IDC_YANSHI,button,1342242816
Control44=IDC_END_YANSHI,button,1342242816

[CLS:CContrl_DLG]
Type=0
HeaderFile=Contrl_DLG.h
ImplementationFile=Contrl_DLG.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SHOUWANB_STEP
VirtualFilter=dWC

[DLG:IDD_NIJIE_DLG]
Type=1
Class=CNijie_DLG
ControlCount=15
Control1=IDC_MD_POS,static,1342308608
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_MD_X,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC__MD_Z,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC__MD_Y,edit,1350631552
Control11=IDC_MD_YD,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:CNijie_DLG]
Type=0
HeaderFile=Nijie_DLG.h
ImplementationFile=Nijie_DLG.cpp
BaseClass=CDialog
Filter=D
LastObject=CNijie_DLG

