#pragma once


// CPanel �Ի���

class CPanel : public CDialogEx
{
	DECLARE_DYNAMIC(CPanel)

public:
	CPanel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPanel();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
