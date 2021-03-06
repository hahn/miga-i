// Client RoSoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientRoSo.h"
#include "ClientRoSoDlg.h"
#include "Callibration.h"
#include "ManualCallibration.h"
#include <iostream>
//#include "tinythread.h"
#include "stdafx.h"

using namespace std;
//using namespace tthread;

bool run = true;

/*
bool variable_radio_1 = false ; // home
bool variable_radio_2 = false ; // away
bool variable_radio_3 = false ; // kickoff
bool variable_radio_4 = false ; // penalty
bool variable_radio_5 = false ; // goalie
bool variable_radio_6 = false ; // freeball
bool variable_radio_7 = false ; // strategi 1
bool variable_radio_8 = false ; // strategi 2
*/


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CClientRoSoDlg dialog




CClientRoSoDlg::CClientRoSoDlg(CWnd* pParent /*=NULL*/)
//CClientRoSoDlg::CClientRoSoDlg(void *arg)
	: CDialog(CClientRoSoDlg::IDD, pParent)
	, Timer1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientRoSoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Timer1);
	DDX_Control(pDX, IDC_BUTTON6, m_R1);
	DDX_Control(pDX, IDC_BUTTON7, m_R2);
	DDX_Control(pDX, IDC_BUTTON10, m_R3);
	DDX_Control(pDX, IDC_BUTTON11, m_R4);
	DDX_Control(pDX, IDC_BUTTON12, m_R5);
	DDX_Control(pDX, IDC_BUTTON13, m_A1);
	DDX_Control(pDX, IDC_BUTTON14, m_A2);
	DDX_Control(pDX, IDC_BUTTON15, m_A3);
	DDX_Control(pDX, IDC_BUTTON16, m_A4);
	DDX_Control(pDX, IDC_BUTTON17, m_A5);
	DDX_Control(pDX, IDC_eIPServer, m_IPServer);
	m_IPServer.SetWindowText("167.205.66.75");
	DDX_Control(pDX, IDC_RB1, m_rb1);
	DDX_Control(pDX, IDC_RB2, m_rb2);
	DDX_Control(pDX, IDC_RB3, m_rb3);
	DDX_Control(pDX, IDC_RB4, m_rb4);
	DDX_Control(pDX, IDC_RB5, m_rb5);
	DDX_Control(pDX, IDC_BALL, m_ball);
}

BEGIN_MESSAGE_MAP(CClientRoSoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON4, &CClientRoSoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientRoSoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientRoSoDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON6, &CClientRoSoDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON12, &CClientRoSoDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CClientRoSoDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON7, &CClientRoSoDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_RADIO1, &CClientRoSoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CClientRoSoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CClientRoSoDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CClientRoSoDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CClientRoSoDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CClientRoSoDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CClientRoSoDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CClientRoSoDlg::OnBnClickedRadio8)
//ON_BN_CLICKED(IDC_BUTTON1, &CClientRoSoDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON5, &CClientRoSoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_StartGame, &CClientRoSoDlg::OnBnClickedStartgame)
	ON_BN_CLICKED(IDC_CONNECT, &CClientRoSoDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_StopGame, &CClientRoSoDlg::OnBnClickedStopgame)
END_MESSAGE_MAP()


// CClientRoSoDlg message handlers

BOOL CClientRoSoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Setting Timer
	//SetTimer(1,10,NULL);
	//Start System server client
	StartTheSystem();
	isKoneksi = FALSE;
	m_GameStart = false;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CClientRoSoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientRoSoDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientRoSoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CClientRoSoDlg::OnBnClickedButton2()
{
	// Callibration
	//CCallibration D1;
	//D1.DoModal();
	ManualCallibration Mc;
	Mc.DoModal();
	
	
}

void CClientRoSoDlg::OnBnClickedButton3()
{
	// Start Game
	/*
	while(run){
		cout << "ini dikerjakan dalam thread" << endl;
	}
	*/


}


void CClientRoSoDlg::OnBnClickedButton4()
{
	// Stop Game
}

void CClientRoSoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//ini yang server client(9/7/12)
	UpdateData();
	UpdateClientData();

	// AI
	if(m_GameStart == true)
		GameProccess();

	UpdateData(FALSE);
}



void CClientRoSoDlg::OnBnClickedRadio1()
{
	// Home Team
}

void CClientRoSoDlg::OnBnClickedRadio2()
{
	// Away Team
}

void CClientRoSoDlg::OnBnClickedRadio3()
{
	// KickOff
}

void CClientRoSoDlg::OnBnClickedRadio4()
{
	// Penalty
}

void CClientRoSoDlg::OnBnClickedRadio5()
{
	// Goalie
	// m_CGame::Goalie();
}

void CClientRoSoDlg::OnBnClickedRadio6()
{
	// FreeBall
}

void CClientRoSoDlg::OnBnClickedRadio7()
{
	// Strategi 1
}

void CClientRoSoDlg::OnBnClickedRadio8()
{
	// Strategi 2
}

 
// Batas Bawah Source Code yang digunakan
// ==============================================================================================

void CClientRoSoDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
}

void CClientRoSoDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
}

void CClientRoSoDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
}

void CClientRoSoDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
}

void CClientRoSoDlg::OnBnClickedStartgame()
{
	// TODO: menjalankan game
	m_GameStart = true;
	
}

void CClientRoSoDlg::OnBnClickedConnect()
{
	// TODO: koneksi
	CWnd *pTombol;
	m_iPort = 999;
	//IP ditentukan langsung. harusnya bisa diisi sendiri
	m_IPServer.GetWindowText(m_Alamat);
	if(m_Alamat.IsEmpty())
		//m_Alamat = "167.205.66.85";
		m_Alamat = "127.0.0.1";
	if(isKoneksi==FALSE)
	{
		UpdateData(TRUE);
		if(!m_iocp.Connect(m_Alamat, m_iPort))
		{
			MessageBox("Error!\nCannot Connect to Server","Error Connection");
		}
		else
		{
			//bisa koneksi
			isKoneksi = TRUE;
			//UpdateClientData();
			m_cTimer = SetTimer(1,100,0);
			pTombol = GetDlgItem(IDC_CONNECT);
			pTombol->SetWindowText("Disconnect");
		}
	}else
	{
		//sudah koneksi. akan dimatikan
		isKoneksi=FALSE;
		m_iocp.DisconnectAll();
		KillTimer(1);
		pTombol = GetDlgItem(IDC_CONNECT);
		pTombol->SetWindowText("Connect");

	}
}

void CClientRoSoDlg::UpdateClientData()
{
	ClientContext* pContext=NULL;
	//TODO: INI MASIH MANUAL. HARUSNYA BISA OTOMATIS DAPET ID
	int clID=0;
	m_clientID = 348;
	//IOCPS::getClientID(clID);

	m_iocp.m_ContextMapLock.Lock();
	//cari soket dari pContext
	POSITION pos = m_iocp.m_ContextMap.GetStartPosition();
	unsigned int ikey;//entah buat apa
	if(pos!=NULL)
	{
		m_iocp.m_ContextMap.GetNextAssoc(pos,ikey,pContext);
		m_clientID = pContext->m_Socket;
		//OutputDebugString(""+m_clientID);
	}
	//pContext = m_iocp.FindClient(m_clientID);
	if(pContext!=NULL)
	{
	   pContext->m_ContextLock.Lock();
	   m_teks=pContext->m_sReceived;
	   pContext->m_ContextLock.Unlock();
	}
	m_iocp.m_ContextMapLock.Unlock();
	//OutputDebugString(m_sReceivedTxt);
	if(!m_teks.IsEmpty())
		ekstrakData(m_teks);
	UpdateData(FALSE);
}

void CClientRoSoDlg::ekstrakData(CString data)
{
	//TODO: ekstrak data. 
	//diubah tgl 8/8/12
	typedef struct{
		int id;
		int x;
		int y;
		int t;
	} RPos;
	RPos r[6];
	int  Bx, By, count, idA, ax, ay, at, idB, bx, by, bt, idC, cx,cy,ct, idD, dx, dy, dt, idE, ex, ey, et, idF, fx, fy, ft;
	CString hasil ="";
	//sscanf(data,"[%d] ball %d %d | %d %d %d %d",&count, &bx, &by, &idA, &ax, &ay, &at);
	sscanf(data,"[%d] ball %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d",
		&count, &Bx, &By, 
		&r[0].id, &r[0].x, &r[0].y, &r[0].t,
		&r[1].id, &r[1].x, &r[1].y, &r[1].t, 
		&r[2].id, &r[2].x, &r[2].y, &r[2].t, 
		&r[3].id, &r[3].x, &r[3].y, &r[3].t, 
		&r[4].id, &r[4].x, &r[4].y, &r[4].t, 
		&r[5].id, &r[5].x, &r[5].y, &r[5].t); 

		/*&idD, &dx, &dy, &dt,
		&idA, &ax, &ay, &at, 
		&idE, &ex, &ey, &et,
		&idB, &bx, &by, &bt,
		&idC, &cx, &cy, &ct,
		&idF, &fx, &fy, &ft);*/


	//OutputDebugString(data);
	//////////hahn (31/7)
	//m_CGame.setPos(Bx, By);
	m_CGame.Ball.position.X = Bx;
	m_CGame.Ball.position.Y = By;
	for(int i=0;i<5;i++)
	{
		m_CGame.HomeRobot[i].position.X = r[i].x;
		m_CGame.HomeRobot[i].position.Y = r[i].y;
		m_CGame.HomeRobot[i].Angle		= r[i].t;
	}
	//////////hahn (31/7)


	//hasil.Format("count: %d| ball (%d, %d) | Home1(%d, %d, %d)\n",
	//	count, bx, by, ax, ay, at);
	//nambah bisa gerak ga itu si tombol
	//m_R1.MoveWindow(Bx,By,20,20,1);
	//m_R2.MoveWindow(m_CGame.HomeRobot[0].position.X,m_CGame.HomeRobot[0].position.Y,20,20,1);
	/*m_R3.MoveWindow(m_CGame.HomeRobot[1].position.X,m_CGame.HomeRobot[1].position.Y,20,20,1);
	m_R4.MoveWindow(m_CGame.HomeRobot[2].position.X,m_CGame.HomeRobot[2].position.Y,20,20,1);
	m_R5.MoveWindow(m_CGame.HomeRobot[3].position.X,m_CGame.HomeRobot[3].position.Y,20,20,1);
	m_A1.MoveWindow(m_CGame.HomeRobot[4].position.X,m_CGame.HomeRobot[4].position.Y,20,20,1);*/
	//m_A2.MoveWindow(fx,fy,20,20,1);

	//ganti pake gambar
	m_ball.MoveWindow(Bx,By,20,20,1);
	m_rb1.MoveWindow(m_CGame.HomeRobot[0].position.X,m_CGame.HomeRobot[0].position.Y,20,20,1);
	m_rb2.MoveWindow(m_CGame.HomeRobot[1].position.X,m_CGame.HomeRobot[1].position.Y,20,20,1);
	m_rb3.MoveWindow(m_CGame.HomeRobot[2].position.X,m_CGame.HomeRobot[2].position.Y,20,20,1);
	m_rb4.MoveWindow(m_CGame.HomeRobot[3].position.X,m_CGame.HomeRobot[3].position.Y,20,20,1);
	m_rb5.MoveWindow(m_CGame.HomeRobot[4].position.X,m_CGame.HomeRobot[4].position.Y,20,20,1);
	
}

void CClientRoSoDlg::StartTheSystem()
{
	m_iocp.m_StatusLock.Lock();
	m_iocp.m_hWnd=m_hWnd;
	m_iocp.m_StatusLock.Unlock();
	if(!m_iocp.Start(0xffffffff,1201,1,0,100,50,1,1,5))
	{
		MessageBox("StartSystem Ga bisa bro");
		
	}
}
/* proses game di sini(?)
 * (31/7) H
 */
void CClientRoSoDlg::GameProccess()
{
	//jalankan fungsi strategi
	m_CGame.Strategy();

}
void CClientRoSoDlg::OnBnClickedStopgame()
{
	// TODO: Add your control notification handler code here
	m_GameStart = false;
}
