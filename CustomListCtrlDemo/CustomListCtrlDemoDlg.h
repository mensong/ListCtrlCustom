
// CustomListCtrlDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

class CListCtrlCustom;

// CCustomListCtrlDemoDlg 对话框
class CCustomListCtrlDemoDlg : public CDialogEx
{
// 构造
public:
	CCustomListCtrlDemoDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CCustomListCtrlDemoDlg();

// 对话框数据
	enum { IDD = IDD_CUSTOMLISTCTRLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	//初始化ListCtrl控件
	void __initListCtrl();
	//初始化其它控件
	void __initCtrls();

private:
	//ListCtrlCustom
	CListCtrlCustom *m_pListCtrl;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnBnClickedBtnRowButton();
	afx_msg void OnBnClickedBtnRowCombobox();
	afx_msg void OnBnClickedBtnRowListbox();
	afx_msg void OnBnClickedBtnRowDlg();
	afx_msg void OnBnClickedBtnGettext();

public:
	afx_msg void OnBnClickedBntDelete();
	afx_msg void OnBnClickedBtnRadio();
};
