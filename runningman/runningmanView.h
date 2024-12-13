
// runningmanView.h : interface of the CrunningmanView class
//

#pragma once

#include "Game.h"
#include "runningmanDoc.h"

class CrunningmanView : public CView
{
protected: // create from serialization only
	CrunningmanView() noexcept;
	DECLARE_DYNCREATE(CrunningmanView)

	// Attributes
public:
	CrunningmanDoc* GetDocument() const;

	// Operations
public:
	Game game;
	int kd;
	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// Implementation
public:
	virtual ~CrunningmanView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int batdaugame();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in dinoView.cpp
inline CdinoDoc* CdinoView::GetDocument() const
{
	return reinterpret_cast<CdinoDoc*>(m_pDocument);
}
#endif

