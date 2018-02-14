
// DrawImage1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawImage1.h"
#include "DrawImage1Dlg.h"
#include "afxdialogex.h"
#include "Panel.h"
#include   "mmsystem.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HWND h, maxhand;
int maxheight = 0;
CPanel cp;
PAINTSTRUCT ps;
int w, hi;
CRect rt;
HBITMAP hb;
CBitmap bitmap;
HHOOK hhook;
HINSTANCE hinstDLL;
int c = 1;
HDC pDC;
HDC src;
int flag = 0;
char str[100];
char table[100];
char buff[10];
CString str1,str2;
int temp;
HBITMAP htable[10];
int count;
void DrawImg(CString c_path, int itable);
BOOL CALLBACK EnumChildProc(
	HWND hwnd,      // handle to child window
	LPARAM lParam   // application-defined value
	)
{
	TCHAR a[256];
	GetClassName(hwnd, a, 256);
	CRect rct;
	int height;
	if (!lstrcmp(a, L"CvChartWindow"))
	{
		::GetClientRect(hwnd, &rct);
		height = rct.Height();
		if (maxheight < height)
		{
			maxhand = hwnd;
			maxheight = height;
		}
		return true;
	}
	return true;
}
void PASCAL TimeProc(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	sprintf(str, "%s", "res//");
	
	if (c > 5472)
	{
		timeKillEvent(wTimerID);
	}
	if (c / 10 == 0)
		sprintf(buff, "B000%d.BMP", c);
	else if (c / 100 == 0)
		sprintf(buff, "B00%d.BMP", c);
	else if (c / 1000 == 0)
		sprintf(buff, "B0%d.BMP", c);
	else
	{
		sprintf(buff, "B%d.BMP", c);
	}
	str1 = str;
	str1 += buff;
	temp = c%25;
	if (temp == 0)
		count++;
	if (count == 10)count = 0;
	DrawImg(str1,count);
	c++;
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDrawImage1Dlg �Ի���



CDrawImage1Dlg::CDrawImage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDrawImage1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawImage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawImage1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDrawImage1Dlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CDrawImage1Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDrawImage1Dlg ��Ϣ�������

BOOL CDrawImage1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	sprintf(table, "%s", "table//D");
	for (int i = 0; i < 10; i++)
	{
		sprintf(buff, "%d.BMP", i);
		str2 = table;
		str2 += buff;
		htable[i] = (HBITMAP)::LoadImage(NULL, str2, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
	}
	count = 0;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDrawImage1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDrawImage1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDrawImage1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDrawImage1Dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HWND h = ::FindWindow(NULL, L"���������");

	::EnumChildWindows(h, EnumChildProc, 0);

	CPoint point;
	::GetClientRect(maxhand, rt);
	::ClientToScreen(maxhand, &point);

	cp.Create(IDD_DIALOG1);
	cp.ShowWindow(SW_SHOW);

	w = rt.Width();
	hi = rt.Height();
	cp.MoveWindow(point.x + 3, point.y + 1, w - 9, hi - 2);
	pDC = ::GetDC(cp.m_hWnd);
	src = ::CreateCompatibleDC(pDC);
	//SetTimer(1, 32, NULL);
	timeSetEvent(40, 1, TimeProc, NULL, TIME_PERIODIC);
	//CDialogEx::OnOK();
	
	
}


void CDrawImage1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	

	CDialogEx::OnTimer(nIDEvent);
}


void DrawImg(CString c_path,int itable)
{

	//Invalidate();//������һ�ε�ͼ��
	//UpdateWindow(cp.m_hWnd);
	HBITMAP hb1 = (HBITMAP)::LoadImage(NULL, c_path, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
	
	CBitmap bitmap1, bitmap2;
	bitmap1.Attach(hb1);
	bitmap2.Attach(htable[itable]);
	HDC src1 = ::CreateCompatibleDC(pDC);
	HDC src2 = ::CreateCompatibleDC(pDC);
	::SelectObject(src1, bitmap1.m_hObject);
	::SelectObject(src2, bitmap2.m_hObject);
	::StretchBlt(src1, 0, 0, 370, 280, src2, 2, 1, 380, 259, SRCAND);
	::StretchBlt(pDC, 1, 0, w - 11, hi + 1, src1, 0, 0, 370, 280, SRCCOPY);

	bitmap1.Detach();
	bitmap2.Detach();
	DeleteObject(hb1);
	DeleteObject(bitmap1);
	DeleteObject(src1);
	DeleteObject(src2);
	//InvalidateRect(cp.m_hWnd,rt,TRUE);
	

}


void CDrawImage1Dlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
	DeleteObject(src);
	CDialogEx::OnCancel();
	::ReleaseDC(cp.m_hWnd, pDC);
}
