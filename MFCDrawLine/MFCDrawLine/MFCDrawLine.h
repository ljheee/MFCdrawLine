
// MFCDrawLine.h : MFCDrawLine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCDrawLineApp:
// �йش����ʵ�֣������ MFCDrawLine.cpp
//

class CMFCDrawLineApp : public CWinAppEx
{
public:
	CMFCDrawLineApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDrawLineApp theApp;
