#include "StdAfx.h"
#include "MyButton.h"

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton(void)
	: m_nCurRow(-1)
{
}


CMyButton::~CMyButton(void)
{
}

BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(SDCtrlComboboxListctrl)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMyButton::OnLButtonUp( UINT nFlags, CPoint point )
{
	CString sText;
	sText.Format(_T("U clicked %d"), m_nCurRow);
	AfxMessageBox(sText);
}