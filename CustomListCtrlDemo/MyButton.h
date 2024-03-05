/** 
 * @file   	MyButton.h
 * @brief  	用于添加在ListCtrl上的按钮控件
 * @author 	LMS
 * @date   	24/8/2014
 * ------------------------------------------------------------
 * 版本历史       注释                日期
 * ------------------------------------------------------------
 * @version v1.0  初始版本            24/8/2014
 * ------------------------------------------------------------
 * Note:    
 */
			
#pragma once

class CMyButton
	: public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton(void);
	virtual ~CMyButton(void);

public:
	void SetCurRow(int nRow) { m_nCurRow = nRow; }

private:
	int m_nCurRow;

protected:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

};

