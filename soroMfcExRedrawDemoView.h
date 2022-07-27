
// soroMfcExRedrawDemoView.h : interface of the CsoroMfcExRedrawDemoView class
//

#pragma once

#define BTN_ID_1 10001
#define BTN_ID_2 10002

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

	CButton m_childWndForCapture;
	CButton m_childWndForSave;
	CImage* m_cImage;

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

	// RGB color -> 흑백으로 바꾸기
	void RGBtoGray(COLORREF& rgb)
	{
		// TODO: Add your implementation code here.
		BYTE byGray = (GetRValue(rgb) * 30
			+ GetGValue(rgb) * 59
			+ GetBValue(rgb) * 11) / 100;
		rgb = RGB(byGray, byGray, byGray);
	}
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
private:
	void GetImageOfDeskTop();
public:
	void SaveImageOfDeskTop();
};

#ifndef _DEBUG  // debug version in soroMfcExRedrawDemoView.cpp
inline CsoroMfcExRedrawDemoDoc* CsoroMfcExRedrawDemoView::GetDocument() const
   { return reinterpret_cast<CsoroMfcExRedrawDemoDoc*>(m_pDocument); }
#endif

