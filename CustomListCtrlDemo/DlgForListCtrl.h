#pragma once
#include "afxcmn.h"


// CDlgForListCtrl �Ի���

class CDlgForListCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgForListCtrl)

public:
	CDlgForListCtrl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgForListCtrl();

// �Ի�������
	enum { IDD = IDD_DLG_LIST_CTRL };

public:
	int GetValue();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CSliderCtrl m_ctrlSlider;

protected:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
};
