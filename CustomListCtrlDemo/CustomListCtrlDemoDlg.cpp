
// CustomListCtrlDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CustomListCtrlDemo.h"
#include "CustomListCtrlDemoDlg.h"
#include "afxdialogex.h"
#include "ListCtrlCustom.h"
#include "MyButton.h"
#include "DlgForListCtrl.h"
#include "MyRadioButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCustomListCtrlDemoDlg �Ի���

CCustomListCtrlDemoDlg::CCustomListCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCustomListCtrlDemoDlg::IDD, pParent)
	//, m_pListCtrl(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCustomListCtrlDemoDlg::~CCustomListCtrlDemoDlg()
{
	//delete m_pListCtrl;
}

void CCustomListCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CCustomListCtrlDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ROW_BUTTON, &CCustomListCtrlDemoDlg::OnBnClickedBtnRowButton)
	ON_BN_CLICKED(IDC_BTN_ROW_COMBOBOX, &CCustomListCtrlDemoDlg::OnBnClickedBtnRowCombobox)
	ON_BN_CLICKED(IDC_BTN_ROW_LISTBOX, &CCustomListCtrlDemoDlg::OnBnClickedBtnRowListbox)
	ON_BN_CLICKED(IDC_BTN_ROW_DLG, &CCustomListCtrlDemoDlg::OnBnClickedBtnRowDlg)
	ON_BN_CLICKED(IDC_BTN_GETTEXT, &CCustomListCtrlDemoDlg::OnBnClickedBtnGettext)
	ON_BN_CLICKED(IDC_BNT_DELETE, &CCustomListCtrlDemoDlg::OnBnClickedBntDelete)
	ON_BN_CLICKED(IDC_BTN_RADIO, &CCustomListCtrlDemoDlg::OnBnClickedBtnRadio)
END_MESSAGE_MAP()


// CCustomListCtrlDemoDlg ��Ϣ�������

BOOL CCustomListCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	__initListCtrl();
	__initCtrls();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCustomListCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCustomListCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCustomListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CALLBACK OnSettingRect(CListCtrlCustom *pListCtrl, CWnd *pCtrl, CRect &inOutRcGrid)
{
#if 0
	//ʹ��Ĭ�ϵĴ���ʽ����������������
	return FALSE;
#else
	if (pCtrl->IsKindOf(RUNTIME_CLASS(CListBox))
		|| pCtrl->IsKindOf(RUNTIME_CLASS(CDlgForListCtrl)))
	{
		//������б�ؼ����ߴ��ڿؼ��������Ĭ�ϵĴ���������
		return FALSE;
	}
	else if (pCtrl->IsKindOf(RUNTIME_CLASS(CComboBox)))
	{
		//�ӿؼ��߶Ȳ��䣬������У���������
		CRect rcCtrl;
		pCtrl->GetWindowRect(&rcCtrl);
		LONG lHeightOffset = (inOutRcGrid.Height()-rcCtrl.Height()) / 2;
		CRect rcCtrlNew = inOutRcGrid;
		rcCtrlNew.top += lHeightOffset;
		rcCtrlNew.bottom = rcCtrlNew.top + rcCtrl.Height();
		pCtrl->MoveWindow(&rcCtrlNew);
	}
	else
	{
		//�ӿؼ��߶ȺͿ�Ȳ��䣬��������ʾ
		CRect rcCtrl;
		pCtrl->GetWindowRect(&rcCtrl);
		LONG lWidthOffset = (inOutRcGrid.Width()-rcCtrl.Width()) / 2;
		LONG lHeightOffset = (inOutRcGrid.Height()-rcCtrl.Height()) / 2;
		CRect rcCtrlNew = inOutRcGrid;
		rcCtrlNew.top += lHeightOffset;
		rcCtrlNew.bottom = rcCtrlNew.top + rcCtrl.Height();
		rcCtrlNew.left += lWidthOffset;
		rcCtrlNew.right = rcCtrlNew.left + rcCtrl.Width();
		pCtrl->MoveWindow(&rcCtrlNew);
	}

	return TRUE;
#endif
}

void CCustomListCtrlDemoDlg::__initListCtrl()
{
	////���ListCtrl��λ��
	//CRect rcListCtrl;
	//CWnd *pRect = GetDlgItem(IDC_STATIC_RECT);
	//if (NULL==pRect)
	//{
	//	return ;
	//}
	//pRect->GetWindowRect(&rcListCtrl);
	//ScreenToClient(&rcListCtrl);

	////����ListCtrl�ؼ�
	//m_pListCtrl = new CListCtrlCustom();
	//m_pListCtrl->Create(WS_VISIBLE | WS_BORDER, rcListCtrl, this, IDC_STATIC_RECT+1);
	////  ��չ��ʽ
	//DWORD dwExStyle = LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;
	//m_pListCtrl->SetExtendedStyle(dwExStyle);
	//m_pListCtrl->RegOnSettingRect(OnSettingRect);
	//m_pListCtrl->SetRowHeight(25);
	//m_pListCtrl->ShowWindow(SW_SHOW);
	//m_pListCtrl->InsertColumn(0, _T("��ͨ�ı�"), LVCFMT_CENTER, 100);
	//m_pListCtrl->InsertColumn(1, _T("�ؼ�"), LVCFMT_CENTER, 200);

	//  ��չ��ʽ
	DWORD dwExStyle = LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;
	m_listCtrl.SetExtendedStyle(dwExStyle);
	m_listCtrl.RegOnSettingRect(OnSettingRect);
	m_listCtrl.SetRowHeight(25);

	m_listCtrl.InsertColumn(0, _T("��ͨ�ı�"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(1, _T("�ؼ�"), LVCFMT_CENTER, 200);
}


void CCustomListCtrlDemoDlg::__initCtrls()
{

}

void CCustomListCtrlDemoDlg::OnBnClickedBtnRowButton()
{
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("��ť"));

	//�½�һ����ť
	//�½��İ�ťһ����new�����ģ�����new�����Ķ�����Զ�ɾ��
	CMyButton *pBtn = new CMyButton();
	pBtn->Create(_T("Click me"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 80, 20), 
		this, m_listCtrl.GetDlgCtrlID()+nCurRow);
	pBtn->SetCurRow(nCurRow);

	m_listCtrl.SetItemEx(nCurRow, 1, pBtn);

	//delete pList;//Error. No need to delete it, I will deal with it
}


void CCustomListCtrlDemoDlg::OnBnClickedBtnRowCombobox()
{
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("��Ͽ�"));

	//�½�һ����������
	//�½��İ�ťһ����new�����ģ�����new�����Ķ�����Զ�ɾ��
	CComboBox *pCombo = new CComboBox();
	pCombo->Create(/*CBS_DROPDOWN*/CBS_DROPDOWNLIST | WS_VSCROLL, CRect(0, 0, 80, 20), &m_listCtrl,
		m_listCtrl.GetDlgCtrlID()+nCurRow);
	CString sText;
	for (int i=0; i<9; ++i)
	{
		sText.Format(_T("%d"), i);
		pCombo->AddString(sText);
	}

	m_listCtrl.SetItemEx(nCurRow, 1, pCombo);

	//delete pList;//Error. No need to delete it, I will deal with it
}


void CCustomListCtrlDemoDlg::OnBnClickedBtnRowListbox()
{
	static bool s_bHasSet = false;
	if (!s_bHasSet)
	{
		m_listCtrl.SetRowHeight(50);
		s_bHasSet = true;
	}

	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("�б�"));

	//�½�һ����������
	//�½��İ�ťһ����new�����ģ�����new�����Ķ�����Զ�ɾ��
	CListBox *pList = new CListBox();
	pList->Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER, CRect(), &m_listCtrl,
		m_listCtrl.GetDlgCtrlID()+nCurRow);

	CString sText;
	for (int i=0; i<9; ++i)
	{
		sText.Format(_T("%d"), i);
		pList->AddString(sText);
	}

	m_listCtrl.SetItemEx(nCurRow, 1, pList);

	//delete pList;//Error. No need to delete it, I will deal with it
}


void CCustomListCtrlDemoDlg::OnBnClickedBtnRowDlg()
{
	////////////////////////////////////////////////////////
	////////////////         ע��         //////////////////
	/////////��ӵĴ��ڵ�Style����һ��ҪΪCHILD/////////////
	////////////////////////////////////////////////////////

	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("�Ի���"));

	//�½�һ����������
	//�½��İ�ťһ����new�����ģ�����new�����Ķ�����Զ�ɾ��
	CDlgForListCtrl *pDlg = new CDlgForListCtrl();
	pDlg->Create(CDlgForListCtrl::IDD, &m_listCtrl);

	static bool s_bHasSet = false;
	if (!s_bHasSet)
	{
		CRect rcCtrl;
		pDlg->GetWindowRect(&rcCtrl);
		m_listCtrl.SetRowHeight(rcCtrl.Height());
		s_bHasSet = true;
	}

	m_listCtrl.SetItemEx(nCurRow, 1, pDlg);

	//delete pList;//Error. No need to delete it, I will deal with it
}

void CCustomListCtrlDemoDlg::OnBnClickedBtnRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("��ѡ��ť"));
	
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | BS_NOTIFY | WS_TABSTOP;

	UINT id = m_listCtrl.GetDlgCtrlID() + nCurRow;
	CMyRadioButton::ms_arrGroupButton.insert(id);

	//�½�һ����ť
	//�½��İ�ťһ����new�����ģ�����new�����Ķ�����Զ�ɾ��
	CMyRadioButton *pBtn = new CMyRadioButton();
	pBtn->Create(_T("Click me"),  dwStyle, CRect(0, 0, 80, 20), 
		this, m_listCtrl.GetDlgCtrlID()+nCurRow);
	
	m_listCtrl.SetItemEx(nCurRow, 1, pBtn);

	//delete pList;//Error. No need to delete it, I will deal with it
}

void CCustomListCtrlDemoDlg::OnBnClickedBtnGettext()
{
	CString sText;

	//�����
	int nRow = m_listCtrl.GetSelectionMark();
	if (nRow < 0)
	{
		return ;
	}
	int nCol = 1;//��Ϊ�̶���

	//������ֻ��ֵ
	CWnd *pCtrl = m_listCtrl.GetCtrl(nRow, nCol);
	if (NULL == pCtrl)
	{
		sText = m_listCtrl.GetItemText(nCol, nCol);
	}
	else if (pCtrl->IsKindOf(RUNTIME_CLASS(CListBox)))
	{
		CListBox *pList = (CListBox *)pCtrl;
		pList->GetText(pList->GetCurSel(), sText);
	}
	else if (pCtrl->IsKindOf(RUNTIME_CLASS(CDlgForListCtrl)))
	{
		CDlgForListCtrl *pDlg = (CDlgForListCtrl *)pCtrl;
		sText.Format(_T("%d"), pDlg->GetValue());
	}
	else if (pCtrl->IsKindOf(RUNTIME_CLASS(CMyRadioButton)))
	{
		CMyRadioButton *pRadio = (CMyRadioButton *)pCtrl;
		if (pRadio->GetCheck() == TRUE)
			sText = "TRUE";
		else 
			sText = "FALSE";
	}
	else
	{
		pCtrl->GetWindowText(sText);
	}

	AfxMessageBox(sText);
}


void CCustomListCtrlDemoDlg::OnBnClickedBntDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = m_listCtrl.GetSelectionMark();
	if (nIndex < 0)
		return ;

	//�����
	int nRow = m_listCtrl.GetSelectionMark();
	if (nRow < 0)
	{
		return ;
	}
	int nCol = 1;//��Ϊ�̶���

	CWnd *pCtrl = m_listCtrl.GetCtrl(nRow, nCol);
	if (pCtrl->IsKindOf(RUNTIME_CLASS(CMyRadioButton)))
	{
		std::set<UINT>::iterator itFinder = CMyRadioButton::ms_arrGroupButton.find(pCtrl->GetDlgCtrlID());
		if (itFinder != CMyRadioButton::ms_arrGroupButton.end())
			CMyRadioButton::ms_arrGroupButton.erase(itFinder);
	}

	m_listCtrl.DeleteItem(nIndex);

}


