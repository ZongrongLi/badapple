
// DrawImage1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDrawImage1App: 
// �йش����ʵ�֣������ DrawImage1.cpp
//

class CDrawImage1App : public CWinApp
{
public:
	CDrawImage1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDrawImage1App theApp;