#include "StdAfx.h"
#include "MyRadioButton.h"

IMPLEMENT_DYNAMIC(CMyRadioButton, CButton)

CMyRadioButton::CMyRadioButton(void)
{
}


CMyRadioButton::~CMyRadioButton(void)
{
}

BEGIN_MESSAGE_MAP(CMyRadioButton, CButton)
	//{{AFX_MSG_MAP(SDCtrlComboboxListctrl)
	ON_WM_LBUTTONUP()	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMyRadioButton::OnLButtonUp( UINT nFlags, CPoint point )
{
	CButton::OnLButtonUp(nFlags, point);//必需调用

	SetCheck(TRUE);//this button always checked

	CWnd *pParent = GetParent();
	if (NULL == pParent)
		return ;

	UINT uThisId = GetDlgCtrlID();
	CWnd *pCtrl = NULL;

	for (std::set<UINT>::iterator it=ms_arrGroupButton.begin();
		it!=ms_arrGroupButton.end(); ++it)
	{
		UINT uId = *it;
		if (uId == uThisId)
			continue;

		pCtrl = pParent->GetDlgItem(uId);
		if (NULL == pCtrl && !pCtrl->IsKindOf(RUNTIME_CLASS(CButton)))
			continue;
		((CButton *)pCtrl)->SetCheck(FALSE);//other buttons always unchecked
	}
}

std::set<UINT> CMyRadioButton::ms_arrGroupButton;
