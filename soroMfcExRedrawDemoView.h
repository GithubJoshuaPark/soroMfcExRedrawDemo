
// soroMfcExRedrawDemoView.h : interface of the CsoroMfcExRedrawDemoView class
//

#pragma once


class CsoroMfcExRedrawDemoView : public CView
{
protected: // create from serialization only
	CsoroMfcExRedrawDemoView() noexcept;
	DECLARE_DYNCREATE(CsoroMfcExRedrawDemoView)

// Attributes
public:
	CsoroMfcExRedrawDemoDoc* GetDocument() const;

// Operations
public:
	CRect m_BtnRect;
	BOOL m_bClicked;

	CRect m_RectForText;
	CPoint m_startPoint;
	CPoint m_endPoint;
	BOOL m_isDragStart;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CsoroMfcExRedrawDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in soroMfcExRedrawDemoView.cpp
inline CsoroMfcExRedrawDemoDoc* CsoroMfcExRedrawDemoView::GetDocument() const
   { return reinterpret_cast<CsoroMfcExRedrawDemoDoc*>(m_pDocument); }
#endif

