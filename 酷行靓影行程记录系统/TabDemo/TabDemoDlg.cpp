
// TabDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "TabDemoDlg.h"
#include "afxdialogex.h"

#include "DlgBefore.h"

#include "DlgMap.h"
#include "DlgBuild.h"
#include "shellapi.h"
#include "windows.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabDemoDlg �Ի���




CTabDemoDlg::CTabDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_csID = _T("");
}

void CTabDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_USER, m_tab);
	DDX_Text(pDX, IDC_EDIT_ID, m_csID);
	DDV_MaxChars(pDX, m_csID, 8);
}

BEGIN_MESSAGE_MAP(CTabDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_USER, &CTabDemoDlg::OnSelchangeTabUser)
	
	ON_BN_CLICKED(IDCANCEL, &CTabDemoDlg::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENU_STYLE1, &CTabDemoDlg::OnMenuStyle1)
	ON_COMMAND(ID_MENU_STYLE2, &CTabDemoDlg::OnMenuStyle2)
	ON_COMMAND(ID_MENU_STYLE3, &CTabDemoDlg::OnMenuStyle3)
	ON_COMMAND(ID_OUTMAP, &CTabDemoDlg::OnOutmap)
	
	
	//ON_BN_CLICKED(IDC_BUTTON3, &CTabDemoDlg::OnBnClickedButton3)
	//ON_COMMAND(ID_INPIC, &CTabDemoDlg::OnInpic)
	ON_COMMAND(ID_WRITE, &CTabDemoDlg::OnWrite)
	//ON_COMMAND(ID_NEW, &CTabDemoDlg::OnNew)
END_MESSAGE_MAP()


// CTabDemoDlg ��Ϣ�������

BOOL CTabDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	
	this->MoveWindow(0,0,1300,750,true);

	LoadDlgBk(IDB_BITMAP1);


	// TODO: �ڴ���Ӷ���ĳ�ʼ������

    /*CDlgBefore m_CDlgBefore;

	m_CDlgBefore.DoModal();

	*/

	CRect tabRect;

	m_tab.InsertItem(0, _T("�ҵ���Ʒ"));//�����һ����ǩ
	m_tab.InsertItem(1, _T("�ҵ���Ƭ"));//����ڶ�����ǩ
	m_tab.InsertItem(2, _T(""));//����ڶ�����ǩ

	m_tab1.Create(IDD_DIALOG_TAB1, &m_tab);//������һ����ǩҳ
	m_tab2.Create(IDD_DIALOG_TAB2, &m_tab);//������һ����ǩҳ
	m_tab3.Create(IDD_DIALOG_TAB3, &m_tab);//������һ����ǩҳ

	m_tab.GetClientRect(&tabRect);//��ȡ��ǩ�ؼ�������

	//����tabRect��ֵ�������ĸ��Ƿ�Χ�ʺ������ǩҳ
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;

	//���ݵ����õ�tabRect������m_tab1��m_tab2��2����ǩҳ�����ѵ�һ����ǩҳ����Ϊ��ʾ���ɵڶ�������Ϊ����
	m_tab1.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	m_tab2.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	m_tab3.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTabDemoDlg::OnPaint()
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
	{//��ȡ�ͻ�����Ĵ�С
		CRect rect;
		GetClientRect(rect);
		CPaintDC dc(this);
		dc.BitBlt(0,0,rect.right,rect.bottom,&m_dcMain,0,0,SRCCOPY);



		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTabDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTabDemoDlg::LoadDlgBk(int iBmpID)
{
	
	//�ͷ���Դ
	m_dcMain.DeleteDC();
	m_dcBk.DeleteDC();
	m_bmpMain.DeleteObject();
	m_bmpBk.DeleteObject();
	//��ȡ�ͻ������С
	CRect   rect;
	GetClientRect(rect);

	//���Ʊ���
	CClientDC  dc(this);
	m_dcMain.CreateCompatibleDC(&dc);
	m_bmpMain.CreateCompatibleBitmap(&dc,rect.right,rect.bottom);
	m_dcMain.SelectObject(&m_bmpMain);

	m_dcBk.CreateCompatibleDC(&m_dcMain);
	m_bmpBk.LoadBitmap(iBmpID);
	m_dcBk.SelectObject(m_bmpBk);


	m_dcMain.SetStretchBltMode(STRETCH_HALFTONE);

	m_dcMain.StretchBlt(0,0,rect.right,rect.bottom,&m_dcBk,0,0,708,623,SRCCOPY);

	Invalidate(FALSE);

}


void CTabDemoDlg::OnSelchangeTabUser(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CRect tabRect;

	m_tab.GetClientRect(&tabRect);//��ȡ��ǩ�ؼ�������

	//����tabRect��ֵ�������ĸ��Ƿ�Χ�ʺ������ǩҳ
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;

	switch(m_tab.GetCurSel())
	{
		//��ʾ��һҳ�����صڶ�ҳ
	case 0:
		m_tab1.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		m_tab2.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_tab3.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		break;

	case 1:
		m_tab1.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_tab2.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		m_tab3.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		break;

    case 2:
		m_tab1.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_tab2.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_tab3.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		//ShellExecute(NULL,_T("open"),_T("d:\\1.txt "),NULL,NULL,SW_SHOWNORMAL);

		break;

	default :
		break;
	}

}


/*void CTabDemoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	/*m_csID = m_pParent->m_csID;

    UpdateData(TRUE);
	

	CDlgAfter m_DlgAfter;

	m_DlgAfter.DoModal();



	CDialogEx::OnOK();
}
*/

void CTabDemoDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CTabDemoDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷ���Դ
	m_dcMain.DeleteDC();
	m_dcBk.DeleteDC();
	m_bmpMain.DeleteObject();
	m_bmpBk.DeleteObject();
}


void CTabDemoDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CTabDemoDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::OnOK();
}


void CTabDemoDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::OnCancel();
}

void CTabDemoDlg::OnMenuStyle1()
{
LoadDlgBk(IDB_BITMAP1);
}

void CTabDemoDlg::OnMenuStyle2()
{
LoadDlgBk(IDB_BITMAP4);
}

void CTabDemoDlg::OnMenuStyle3()
{
LoadDlgBk(IDB_BITMAP3);
}



void CTabDemoDlg::OnOutmap()
{
	// TODO: �ڴ���������������
	CDlgMap m_DlgMap ;

	m_DlgMap.DoModal();
     
}





void CTabDemoDlg::OnWrite()
{
	// TODO: �ڴ���������������
	//ShellExecute(0,(LPCWSTR)L"open",(LPCWSTR)L"NOTEPAD.EXE",(LPCWSTR)L"",(LPCWSTR)L"",SW_SHOWNORMAL);
	ShellExecute(0,"open","NOTEPAD.EXE","","",SW_SHOWNORMAL);
}


