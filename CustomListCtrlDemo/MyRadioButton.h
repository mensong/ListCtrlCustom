#pragma once
#include <set>

class CMyRadioButton
	: public CButton
{
	DECLARE_DYNAMIC(CMyRadioButton)

public:
	CMyRadioButton(void);
	~CMyRadioButton(void);

	static std::set<UINT> ms_arrGroupButton;

protected:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

