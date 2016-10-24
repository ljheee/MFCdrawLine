
// MFCDrawLineView.h : CMFCDrawLineView 类的接口
//

#pragma once
#include "atltypes.h"
#include "afxtempl.h"


class CMFCDrawLineView : public CView
{
protected: // 仅从序列化创建
	CMFCDrawLineView();
	DECLARE_DYNCREATE(CMFCDrawLineView)

// 特性
public:
	CMFCDrawLineDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptOrigin;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CList<CPoint,CPoint> m_ltPoint;
};

#ifndef _DEBUG  // MFCDrawLineView.cpp 中的调试版本
inline CMFCDrawLineDoc* CMFCDrawLineView::GetDocument() const
   { return reinterpret_cast<CMFCDrawLineDoc*>(m_pDocument); }
#endif

