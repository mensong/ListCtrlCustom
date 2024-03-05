
// CustomListCtrlDemoDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCustomListCtrlDemoDlg 对话框

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


// CCustomListCtrlDemoDlg 消息处理程序

BOOL CCustomListCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	__initListCtrl();
	__initCtrls();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCustomListCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCustomListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CALLBACK OnSettingRect(CListCtrlCustom *pListCtrl, CWnd *pCtrl, CRect &inOutRcGrid)
{
#if 0
	//使用默认的处理方式，既填满整个格子
	return FALSE;
#else
	if (pCtrl->IsKindOf(RUNTIME_CLASS(CListBox))
		|| pCtrl->IsKindOf(RUNTIME_CLASS(CDlgForListCtrl)))
	{
		//如果是列表控件或者窗口控件，则采用默认的处理方法即可
		return FALSE;
	}
	else if (pCtrl->IsKindOf(RUNTIME_CLASS(CComboBox)))
	{
		//子控件高度不变，纵向居中，横向填满
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
		//子控件高度和宽度不变，并居中显示
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
	////获得ListCtrl的位置
	//CRect rcListCtrl;
	//CWnd *pRect = GetDlgItem(IDC_STATIC_RECT);
	//if (NULL==pRect)
	//{
	//	return ;
	//}
	//pRect->GetWindowRect(&rcListCtrl);
	//ScreenToClient(&rcListCtrl);

	////生成ListCtrl控件
	//m_pListCtrl = new CListCtrlCustom();
	//m_pListCtrl->Create(WS_VISIBLE | WS_BORDER, rcListCtrl, this, IDC_STATIC_RECT+1);
	////  扩展样式
	//DWORD dwExStyle = LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;
	//m_pListCtrl->SetExtendedStyle(dwExStyle);
	//m_pListCtrl->RegOnSettingRect(OnSettingRect);
	//m_pListCtrl->SetRowHeight(25);
	//m_pListCtrl->ShowWindow(SW_SHOW);
	//m_pListCtrl->InsertColumn(0, _T("普通文本"), LVCFMT_CENTER, 100);
	//m_pListCtrl->InsertColumn(1, _T("控件"), LVCFMT_CENTER, 200);

	//  扩展样式
	DWORD dwExStyle = LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;
	m_listCtrl.SetExtendedStyle(dwExStyle);
	m_listCtrl.RegOnSettingRect(OnSettingRect);
	m_listCtrl.SetRowHeight(25);

	m_listCtrl.InsertColumn(0, _T("普通文本"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(1, _T("控件"), LVCFMT_CENTER, 200);
}


void CCustomListCtrlDemoDlg::__initCtrls()
{

}

void CCustomListCtrlDemoDlg::OnBnClickedBtnRowButton()
{
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("按钮"));

	//新建一个按钮
	//新建的按钮一定是new出来的，并且new出来的对象会自动删除
	CMyButton *pBtn = new CMyButton();
	pBtn->Create(_T("Click me"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 80, 20), 
		this, m_listCtrl.GetDlgCtrlID()+nCurRow);
	pBtn->SetCurRow(nCurRow);

	m_listCtrl.SetItemEx(nCurRow, 1, pBtn);

	//delete pList;//Error. No need to delete it, I will deal with it
}


void CCustomListCtrlDemoDlg::OnBnClickedBtnRowCombobox()
{
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("组合框"));

	//新建一个组合输入框
	//新建的按钮一定是new出来的，并且new出来的对象会自动删除
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

	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("列表"));

	//新建一个组合输入框
	//新建的按钮一定是new出来的，并且new出来的对象会自动删除
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
	////////////////         注意         //////////////////
	/////////添加的窗口的Style属性一定要为CHILD/////////////
	////////////////////////////////////////////////////////

	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("对话框"));

	//新建一个组合输入框
	//新建的按钮一定是new出来的，并且new出来的对象会自动删除
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
	// TODO: 在此添加控件通知处理程序代码
	int nCurRow = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), _T("单选按钮"));
	
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | BS_NOTIFY | WS_TABSTOP;

	UINT id = m_listCtrl.GetDlgCtrlID() + nCurRow;
	CMyRadioButton::ms_arrGroupButton.insert(id);

	//新建一个按钮
	//新建的按钮一定是new出来的，并且new出来的对象会自动删除
	CMyRadioButton *pBtn = new CMyRadioButton();
	pBtn->Create(_T("Click me"),  dwStyle, CRect(0, 0, 80, 20), 
		this, m_listCtrl.GetDlgCtrlID()+nCurRow);
	
	m_listCtrl.SetItemEx(nCurRow, 1, pBtn);

	//delete pList;//Error. No need to delete it, I will deal with it
}

void CCustomListCtrlDemoDlg::OnBnClickedBtnGettext()
{
	CString sText;

	//获得行
	int nRow = m_listCtrl.GetSelectionMark();
	if (nRow < 0)
	{
		return ;
	}
	int nCol = 1;//列为固定的

	//处理各种获得值
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
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_listCtrl.GetSelectionMark();
	if (nIndex < 0)
		return ;

	//获得行
	int nRow = m_listCtrl.GetSelectionMark();
	if (nRow < 0)
	{
		return ;
	}
	int nCol = 1;//列为固定的

	CWnd *pCtrl = m_listCtrl.GetCtrl(nRow, nCol);
	if (pCtrl->IsKindOf(RUNTIME_CLASS(CMyRadioButton)))
	{
		std::set<UINT>::iterator itFinder = CMyRadioButton::ms_arrGroupButton.find(pCtrl->GetDlgCtrlID());
		if (itFinder != CMyRadioButton::ms_arrGroupButton.end())
			CMyRadioButton::ms_arrGroupButton.erase(itFinder);
	}

	m_listCtrl.DeleteItem(nIndex);

}


