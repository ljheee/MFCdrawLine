
// MFCdrawLineView.cpp : CMFCdrawLineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCdrawLine.h"
#endif

#include "MFCdrawLineDoc.h"
#include "MFCdrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCdrawLineView

IMPLEMENT_DYNCREATE(CMFCdrawLineView, CView)

BEGIN_MESSAGE_MAP(CMFCdrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCdrawLineView 构造/析构

CMFCdrawLineView::CMFCdrawLineView()
{
	// TODO:  在此处添加构造代码

}

CMFCdrawLineView::~CMFCdrawLineView()
{
}

BOOL CMFCdrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCdrawLineView 绘制

void CMFCdrawLineView::OnDraw(CDC* /*pDC*/)
{
	CMFCdrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFCdrawLineView 打印

BOOL CMFCdrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCdrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFCdrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFCdrawLineView 诊断

#ifdef _DEBUG
void CMFCdrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCdrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCdrawLineDoc* CMFCdrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCdrawLineDoc)));
	return (CMFCdrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCdrawLineView 消息处理程序
