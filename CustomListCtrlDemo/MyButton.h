/** 
 * @file   	MyButton.h
 * @brief  	���������ListCtrl�ϵİ�ť�ؼ�
 * @author 	LMS
 * @date   	24/8/2014
 * ------------------------------------------------------------
 * �汾��ʷ       ע��                ����
 * ------------------------------------------------------------
 * @version v1.0  ��ʼ�汾            24/8/2014
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

