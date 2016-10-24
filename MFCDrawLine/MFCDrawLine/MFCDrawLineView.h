
// MFCDrawLineView.h : CMFCDrawLineView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include "afxtempl.h"


class CMFCDrawLineView : public CView
{
protected: // �������л�����
	CMFCDrawLineView();
	DECLARE_DYNCREATE(CMFCDrawLineView)

// ����
public:
	CMFCDrawLineDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptOrigin;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CList<CPoint,CPoint> m_ltPoint;
};

#ifndef _DEBUG  // MFCDrawLineView.cpp �еĵ��԰汾
inline CMFCDrawLineDoc* CMFCDrawLineView::GetDocument() const
   { return reinterpret_cast<CMFCDrawLineDoc*>(m_pDocument); }
#endif

