
// MFCdrawLine.h : MFCdrawLine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCdrawLineApp:
// �йش����ʵ�֣������ MFCdrawLine.cpp
//

class CMFCdrawLineApp : public CWinApp
{
public:
	CMFCdrawLineApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCdrawLineApp theApp;
