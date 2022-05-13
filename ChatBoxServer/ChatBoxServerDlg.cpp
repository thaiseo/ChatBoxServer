
// ChatBoxServerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ChatBoxServer.h"
#include "ChatBoxServerDlg.h"
#include "afxdialogex.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatBoxServerDlg dialog



CChatBoxServerDlg::CChatBoxServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHATBOXSERVER_DIALOG, pParent)
	{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatBoxServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_TextBoxIp);
	DDX_Control(pDX, IDC_EDIT2, m_TextBoxPort);
}

BEGIN_MESSAGE_MAP(CChatBoxServerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChatBoxServerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChatBoxServerDlg message handlers

BOOL CChatBoxServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatBoxServerDlg::OnPaint()
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
HCURSOR CChatBoxServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CChatBoxServerDlg::StartServer(CString ip, UINT port) {
	if (AfxSocketInit() == FALSE) {
		MessageBox(L"Failed to Initialize Sockets");
		return FALSE;
	}
	if (m_Socket.Create(port, SOCK_STREAM, ip) == FALSE) {
		MessageBox(L"Socket Create Failed");
		return FALSE;
	}
	if (m_Socket.Listen() == FALSE) {
		MessageBox(L"Socket Listen Failed");
		return FALSE;
	}
	return TRUE;
}
void CChatBoxServerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString ip, strPort;
	UINT port;
	
	m_TextBoxIp.GetWindowTextW(ip);
	m_TextBoxPort.GetWindowTextW(strPort);
	port = _wtoi(strPort);

	StartServer(ip, port);

}
