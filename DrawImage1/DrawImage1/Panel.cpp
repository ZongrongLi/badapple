// Panel.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawImage1.h"
#include "Panel.h"
#include "afxdialogex.h"


// CPanel 对话框

IMPLEMENT_DYNAMIC(CPanel, CDialogEx)

CPanel::CPanel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPanel::IDD, pParent)
{

}

CPanel::~CPanel()
{
}

void CPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPanel, CDialogEx)
END_MESSAGE_MAP()


// CPanel 消息处理程序
