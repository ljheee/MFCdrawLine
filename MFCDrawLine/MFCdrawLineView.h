
// MFCdrawLineView.h : CMFCdrawLineView ��Ľӿ�
//

#pragma once


class CMFCdrawLineView : public CView
{
protected: // �������л�����
	CMFCdrawLineView();
	DECLARE_DYNCREATE(CMFCdrawLineView)

// ����
public:
	CMFCdrawLineDoc* GetDocument() const;
	CPoint orgPoint;
	CList<CPoint, CPoint> m_list;
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
	virtual ~CMFCdrawLineView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCdrawLineView.cpp �еĵ��԰汾
inline CMFCdrawLineDoc* CMFCdrawLineView::GetDocument() const
   { return reinterpret_cast<CMFCdrawLineDoc*>(m_pDocument); }
#endif

