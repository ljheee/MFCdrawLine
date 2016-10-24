
// MFCDrawLineView.cpp : CMFCDrawLineView ���ʵ��
//

#include "stdafx.h"
#include <atlwin.h>
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCDrawLineView ����/����

CMFCDrawLineView::CMFCDrawLineView()
	: m_ptOrigin(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMFCDrawLineView::~CMFCDrawLineView()
{
}

BOOL CMFCDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCDrawLineView ����

void CMFCDrawLineView::OnDraw(CDC* pDC/*pDC*/)
{
	CMFCDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CMFCDrawLineView ��ӡ

BOOL CMFCDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCDrawLineView ���

#ifdef _DEBUG
void CMFCDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawLineDoc* CMFCDrawLineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawLineDoc)));
	return (CMFCDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawLineView ��Ϣ�������


void CMFCDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin=point;
	m_ltPoint.AddTail(point);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CClientDC dc(this);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
