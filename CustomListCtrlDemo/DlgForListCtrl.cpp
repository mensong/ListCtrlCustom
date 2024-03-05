// DlgForListCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CustomListCtrlDemo.h"
#include "DlgForListCtrl.h"
#include "afxdialogex.h"


// CDlgForListCtrl �Ի���

IMPLEMENT_DYNAMIC(CDlgForListCtrl, CDialogEx)

CDlgForListCtrl::CDlgForListCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgForListCtrl::IDD, pParent)
{

}

CDlgForListCtrl::~CDlgForListCtrl()
{
}

void CDlgForListCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CDlgForListCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgForListCtrl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgForListCtrl::OnBnClickedButton2)
END_MESSAGE_MAP()


BOOL CDlgForListCtrl::OnInitDialog()
{
	BOOL bRet = CDialogEx::OnInitDialog();

	m_ctrlSlider.SetRange(0, 10);

	return bRet;
}

// CDlgForListCtrl ��Ϣ�������


void CDlgForListCtrl::OnBnClickedButton1()
{
	m_ctrlSlider.SetPos(m_ctrlSlider.GetPos()+1);
}


void CDlgForListCtrl::OnBnClickedButton2()
{
	m_ctrlSlider.SetPos(m_ctrlSlider.GetPos()-1);
}

int CDlgForListCtrl::GetValue()
{
	return m_ctrlSlider.GetPos();
}