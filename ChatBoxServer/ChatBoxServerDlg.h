
// ChatBoxServerDlg.h : header file
//

#pragma once
#include "ServerSocket.h"

// CChatBoxServerDlg dialog
class CChatBoxServerDlg : public CDialogEx
{
// Construction
public:
	CChatBoxServerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATBOXSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_TextBoxIp;
	CEdit m_TextBoxPort;
	ServerSocket m_Socket;
	BOOL StartServer(CString ip, UINT port);
	BOOL TermaiteServer();
	afx_msg void OnBnClickedButton1();
};
