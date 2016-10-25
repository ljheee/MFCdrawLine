
// MFCdrawLineView.cpp : CMFCdrawLineView ���ʵ��
//


#include "stdafx.h"
#include <atlwin.h>
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCdrawLineView ����/����

CMFCdrawLineView::CMFCdrawLineView() :orgPoint(0)
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCdrawLineView::~CMFCdrawLineView()
{
}

BOOL CMFCdrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCdrawLineView ����

void CMFCdrawLineView::OnDraw(CDC* pDC)
{
	CMFCdrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	if (!m_list.IsEmpty())
	{
		POSITION pos = m_list.GetHeadPosition();
		pDC->MoveTo(m_list.GetHead());
		for (; pos; m_list.GetNext(pos))
		{
			pDC->LineTo(m_list.GetAt(pos));
			pDC->MoveTo(m_list.GetAt(pos));
		}
	}

}


// CMFCdrawLineView ��ӡ

BOOL CMFCdrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCdrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCdrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFCdrawLineView ���

#ifdef _DEBUG
void CMFCdrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCdrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCdrawLineDoc* CMFCdrawLineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCdrawLineDoc)));
	return (CMFCdrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCdrawLineView ��Ϣ�������


void CMFCdrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	orgPoint = point;
	m_list.AddTail(point);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCdrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC dc(this);
	dc.MoveTo(orgPoint);
	dc.LineTo(point);

	CView::OnLButtonUp(nFlags, point);
}


void CMFCdrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CWindow myWindow;
	myWindow.Attach(m_hWnd);
	BOOL bRedrawn = myWindow.RedrawWindow();

	if (!m_list.IsEmpty())
	{
		CClientDC dc(this);
		dc.MoveTo(orgPoint);
		dc.LineTo(point);
		CView::OnMouseMove(nFlags, point);
	}


	CView::OnMouseMove(nFlags, point);
}
