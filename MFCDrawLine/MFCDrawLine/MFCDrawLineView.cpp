
// MFCDrawLineView.cpp : CMFCDrawLineView 类的实现
//

#include "stdafx.h"
#include <atlwin.h>
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDrawLine.h"
#endif

#include "MFCDrawLineDoc.h"
#include "MFCDrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawLineView

IMPLEMENT_DYNCREATE(CMFCDrawLineView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCDrawLineView 构造/析构

CMFCDrawLineView::CMFCDrawLineView()
	: m_ptOrigin(0)
{
	// TODO: 在此处添加构造代码

}

CMFCDrawLineView::~CMFCDrawLineView()
{
}

BOOL CMFCDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawLineView 绘制

void CMFCDrawLineView::OnDraw(CDC* pDC/*pDC*/)
{
	CMFCDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if(!m_ltPoint.IsEmpty())
	{
		POSITION pos =m_ltPoint.GetHeadPosition();
		pDC->MoveTo(m_ltPoint.GetHead());
		for(;pos;m_ltPoint.GetNext(pos))
		{
			pDC->LineTo(m_ltPoint.GetAt(pos));
			pDC->MoveTo(m_ltPoint.GetAt(pos));
		}
	}
}


// CMFCDrawLineView 打印

BOOL CMFCDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDrawLineView 诊断

#ifdef _DEBUG
void CMFCDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawLineDoc* CMFCDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawLineDoc)));
	return (CMFCDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawLineView 消息处理程序


void CMFCDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin=point;
	m_ltPoint.AddTail(point);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CClientDC dc(this);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWindow myWindow;
	myWindow.Attach(m_hWnd);
	BOOL bRedrawn = myWindow.RedrawWindow();

	if(!m_ltPoint.IsEmpty())
	{
		CClientDC dc(this);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		CView::OnMouseMove(nFlags, point);
	}
}
