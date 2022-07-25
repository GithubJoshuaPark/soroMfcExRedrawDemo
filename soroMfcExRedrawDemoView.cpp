
// soroMfcExRedrawDemoView.cpp : implementation of the CsoroMfcExRedrawDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "soroMfcExRedrawDemo.h"
#endif

#include "soroMfcExRedrawDemoDoc.h"
#include "soroMfcExRedrawDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsoroMfcExRedrawDemoView

IMPLEMENT_DYNCREATE(CsoroMfcExRedrawDemoView, CView)

BEGIN_MESSAGE_MAP(CsoroMfcExRedrawDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CsoroMfcExRedrawDemoView construction/destruction

CsoroMfcExRedrawDemoView::CsoroMfcExRedrawDemoView() noexcept
{
	// TODO: add construction code here
	m_BtnRect = CRect(500, 100, 700, 300);
	m_bClicked = FALSE;

	m_RectForText = CRect(0, 0, 0, 0);
	m_startPoint = CPoint(0, 0);
	m_endPoint = CPoint(0, 0);
	m_isDragStart = FALSE;
}

CsoroMfcExRedrawDemoView::~CsoroMfcExRedrawDemoView()
{
}

BOOL CsoroMfcExRedrawDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsoroMfcExRedrawDemoView drawing

void CsoroMfcExRedrawDemoView::OnDraw(CDC* /*pDC*/)
{
	CsoroMfcExRedrawDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsoroMfcExRedrawDemoView printing

BOOL CsoroMfcExRedrawDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsoroMfcExRedrawDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsoroMfcExRedrawDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CsoroMfcExRedrawDemoView diagnostics

#ifdef _DEBUG
void CsoroMfcExRedrawDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CsoroMfcExRedrawDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsoroMfcExRedrawDemoDoc* CsoroMfcExRedrawDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsoroMfcExRedrawDemoDoc)));
	return (CsoroMfcExRedrawDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CsoroMfcExRedrawDemoView message handlers


void CsoroMfcExRedrawDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	//CDC* pDC = GetDC();
	//pDC->Rectangle(10, 10, 110, 110);
	//ReleaseDC(pDC);

	if (m_BtnRect.PtInRect(point)) {
		m_bClicked = !m_bClicked;
		RedrawWindow(&m_BtnRect);
	}

	m_isDragStart = TRUE;
	m_startPoint = point;

	CView::OnLButtonDown(nFlags, point);
}


void CsoroMfcExRedrawDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CRect cRect;
	GetClientRect(&cRect);

	// CDC, CBitmap
	CDC MemDC;
	BITMAP bmpInfo;

	MemDC.CreateCompatibleDC(&dc);
	
	CBitmap bmp, *pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP1);
	bmp.GetBitmap(&bmpInfo); // get info of the bmp
	
	pOldBmp = MemDC.SelectObject(&bmp);

	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	MemDC.SelectObject(pOldBmp);

	CFont font, *pOldFont;
	//font.CreatePointFont(400, _T("Tahoma"));   // 타호마 체로 폰트 설정


	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(255, 0, 0);
	DWORD style[] = {6, 3};

	//CPen pen, *pOldPen;
	//pen.CreatePen(PS_USERSTYLE | PS_GEOMETRIC | PS_ENDCAP_FLAT , 10, &lb, 2, style);
	//
	//CBrush brush, * pOldBrush, patternBrush;
	////brush.CreateSolidBrush(RGB(255, 0, 0));
	//brush.CreateHatchBrush(HS_CROSS, RGB(0,192,0));

	//CBitmap bmp;
	//bmp.LoadBitmapW(IDB_BITMAP1);
	//patternBrush.CreatePatternBrush(&bmp);

	//// Set dc with the prev objects
	////pOldBrush = dc.SelectObject(&brush);
	//pOldBrush = dc.SelectObject(&patternBrush);
	//pOldPen = dc.SelectObject(&pen);
	//pOldFont = dc.SelectObject(&font);

	////dc.FillSolidRect(10, 10, 200, 200, RGB(0, 0, 0));
	////dc.SetBkMode(TRANSPARENT);
	////dc.Rectangle(10, 10, 210, 210);  // Draw Rectangle
	//dc.Rectangle(&cRect);  // Draw Rectangle

	//for (int i = 0; i < 10; i++) {
	//	dc.MoveTo(10, 240 + i*20);
	//	dc.LineTo(210, 240 + i*20);
	//}
	//

	//// Reset dc with the prev objects
	//dc.SelectObject(pOldPen); // 사용 후 원래대로 되돌리기 (자원누스 방지)
	//dc.SelectObject(pOldBrush); // 사용 후 원래대로 되돌리기 (자원누스 방지)

	//dc.Rectangle(230, 10, 440, 210); // Draw Rectangle
	//dc.MoveTo(230, 240);
	//dc.LineTo(440, 240);

	//dc.SetBkMode(TRANSPARENT);
	//dc.SetTextColor(RGB(0,0,0));	
	//dc.TextOutW(cRect.Width()/2, cRect.Height()/2, _T("Good Neighborhood"));

	// 삼각형 그리기
	CPen pen, * pOldPen;
	CBrush brush, * pOldBrush;

	pen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT| PS_INSIDEFRAME | PS_JOIN_ROUND, 20, &lb);
	brush.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));

	pOldPen = dc.SelectObject(&pen);
	pOldBrush = (CBrush*) dc.SelectStockObject(NULL_BRUSH); //Polygan 내부에 채우기를 하지 않도록 블러쉬 설정

	// Draw a triangle(ploygan)
	//dc.BeginPath();
	//	dc.MoveTo(190, 40);
	//	dc.LineTo(290, 190);
	//	dc.LineTo(90, 190);
	//	dc.LineTo(190, 40);
	//dc.EndPath();
	//dc.StrokeAndFillPath();

	POINT arPt[3] = { {190, 40},{290, 190},{90, 190} };
	
	dc.Polygon(arPt, 3);

	dc.Ellipse(100, 100, 160, 160);

	dc.SelectObject(pOldPen);
	dc.Rectangle(100, 100, 160, 160);

	dc.SelectObject(pOldBrush);

	// 기본펜으로 삼각형 그리고
	dc.MoveTo(190, 40);
	dc.LineTo(290, 190);
	dc.LineTo(90, 190);
	dc.LineTo(190, 40);


	// 내각이 270인 부채꼴
	CRect pieRect_270(400, 200, 800, 600);
	dc.Pie(&pieRect_270,
		CPoint(pieRect_270.CenterPoint().x, pieRect_270.top),
		CPoint(pieRect_270.right, pieRect_270.CenterPoint().y));

	CRect pieRect_90(800, 200, 1200, 600);
	dc.Pie(&pieRect_90,
		CPoint(pieRect_90.right, pieRect_90.CenterPoint().y),
		CPoint(pieRect_90.CenterPoint().x, pieRect_90.top));
	

	// Btn 처럼 보이게 그리기
	CRect Rect(m_BtnRect);
	Rect += CRect(4, 4, 4, 4);
	//dc.Rectangle(&Rect);
	dc.RoundRect(&Rect, CPoint(20, 20));
	//dc.FillSolidRect(&m_BtnRect, ::GetSysColor(COLOR_BTNFACE));
	pOldBrush = dc.SelectObject(&brush);
	dc.RoundRect(&m_BtnRect, CPoint(20, 20));
	dc.SelectObject(pOldBrush);
	

	if (m_bClicked) {
		dc.Draw3dRect(m_BtnRect,
			::GetSysColor(COLOR_3DSHADOW),  // Left, Top
			::GetSysColor(COLOR_3DLIGHT) // Right, Bottom
		);
	}
	else {
		dc.Draw3dRect(m_BtnRect,		
			::GetSysColor(COLOR_3DLIGHT),
			::GetSysColor(COLOR_3DSHADOW)
		);
	}

	dc.SetBkColor(::GetSysColor(COLOR_BTNFACE));
	dc.SetTextColor(::GetSysColor(COLOR_BTNTEXT));

	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 40;
	lf.lfUnderline = 1;
	lf.lfItalic = 1;
	lf.lfWeight = 1;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));

	font.CreateFontIndirect(&lf);
	pOldFont = dc.SelectObject(&font);

	if (m_bClicked) {
		CRect l_cRect = m_BtnRect;
		l_cRect += CRect(0, 0, 2, 2);

		dc.DrawText(L"Test Button", &l_cRect,
			DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
	else {
		dc.DrawText(L"Test Button", &m_BtnRect,
			DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}

	if (m_isDragStart) {
		dc.Rectangle(&m_RectForText);
	}

	dc.DrawText(L"Good Neighborhood", &m_RectForText,
		DT_CENTER | DT_SINGLELINE | DT_VCENTER);

}


void CsoroMfcExRedrawDemoView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bClicked) {
		m_bClicked = !m_bClicked;

		m_endPoint = point;
		if (abs(m_endPoint.x - m_startPoint.x) > 0) {
			m_RectForText = CRect(min(m_endPoint.x, m_startPoint.x),
								min(m_endPoint.y, m_startPoint.y),
								max(m_endPoint.x, m_startPoint.x),
								max(m_endPoint.y, m_startPoint.y));
		}

		RedrawWindow(&m_BtnRect);
	}

	if (m_isDragStart) {
		m_isDragStart = !m_isDragStart;
		m_endPoint = point;
		if (abs(m_endPoint.x - m_startPoint.x) > 0) {
			m_RectForText = CRect(min(m_endPoint.x, m_startPoint.x),
				min(m_endPoint.y, m_startPoint.y),
				max(m_endPoint.x, m_startPoint.x),
				max(m_endPoint.y, m_startPoint.y));

			RedrawWindow(&m_RectForText);
		}		
	}

	if (m_BtnRect.PtInRect(point)) {
		AfxMessageBox(_T("Clicked Button"));
	}

	CView::OnLButtonUp(nFlags, point);
}


void CsoroMfcExRedrawDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDragStart) {
		m_endPoint = point;
		if (abs(m_endPoint.x - m_startPoint.x) > 0) {
			m_RectForText = CRect(min(m_endPoint.x, m_startPoint.x),
				min(m_endPoint.y, m_startPoint.y),
				max(m_endPoint.x, m_startPoint.x),
				max(m_endPoint.y, m_startPoint.y));
			RedrawWindow();
		}
	}

	CView::OnMouseMove(nFlags, point);
}
