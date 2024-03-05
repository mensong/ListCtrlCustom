
// CustomListCtrlDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

class CListCtrlCustom;

// CCustomListCtrlDemoDlg �Ի���
class CCustomListCtrlDemoDlg : public CDialogEx
{
// ����
public:
	CCustomListCtrlDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CCustomListCtrlDemoDlg();

// �Ի�������
	enum { IDD = IDD_CUSTOMLISTCTRLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	//��ʼ��ListCtrl�ؼ�
	void __initListCtrl();
	//��ʼ�������ؼ�
	void __initCtrls();

private:
	//ListCtrlCustom
	CListCtrlCustom *m_pListCtrl;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
