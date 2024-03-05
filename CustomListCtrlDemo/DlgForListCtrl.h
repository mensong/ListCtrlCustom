#pragma once
#include "afxcmn.h"


// CDlgForListCtrl 对话框

class CDlgForListCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgForListCtrl)

public:
	CDlgForListCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgForListCtrl();

// 对话框数据
	enum { IDD = IDD_DLG_LIST_CTRL };

public:
	int GetValue();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CSliderCtrl m_ctrlSlider;

protected:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
};
