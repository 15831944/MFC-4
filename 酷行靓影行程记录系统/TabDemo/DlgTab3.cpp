// DlgTab3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgTab3.h"
#include "afxdialogex.h"


// CDlgTab3 �Ի���

IMPLEMENT_DYNAMIC(CDlgTab3, CDialogEx)

CDlgTab3::CDlgTab3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTab3::IDD, pParent)
{

}

CDlgTab3::~CDlgTab3()
{
}

void CDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_listCtrl);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOADNOTE, &CDlgTab3::OnBnClickedButtonLoadnote)
END_MESSAGE_MAP()


// CDlgTab3 ��Ϣ�������


int CDlgTab3::InitListCtrlStyle(void)
{
	
	//���ListCtrl�Ŀ��
	CRect rect;
	m_listCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width();
	return 0;
}


void CDlgTab3::OnBnClickedButtonLoadnote()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ShellExecute(NULL,_T("open"),_T("d:\\1.txt "),NULL,NULL,SW_SHOWNORMAL);
    /*int i=0;
    CString strPath[10];
    CFileFind ff;
    BOOL ret = ff.FindFile(L"d:\\*.txt");//��Lǿ��ת��
    while(ret)
    {
        ret = ff.FindNextFile();
        strPath[i++] = ff.GetFileName();
    }
    ff.Close();
	*/
}
