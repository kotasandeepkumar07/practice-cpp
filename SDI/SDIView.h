// SDIView.h : interface of the CSDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIVIEW_H__42C85078_03D5_4974_9567_4BA2A077519F__INCLUDED_)
#define AFX_SDIVIEW_H__42C85078_03D5_4974_9567_4BA2A077519F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSDIView : public CView
{
protected: // create from serialization only
	CSDIView();
	DECLARE_DYNCREATE(CSDIView)

// Attributes
public:
	CSDIDoc* GetDocument();
	void add();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDIView)
	afx_msg void OnFileNew();
	afx_msg void OnEditCopy();
	afx_msg void OnDrawRectangle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SDIView.cpp
inline CSDIDoc* CSDIView::GetDocument()
   { return (CSDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIVIEW_H__42C85078_03D5_4974_9567_4BA2A077519F__INCLUDED_)
