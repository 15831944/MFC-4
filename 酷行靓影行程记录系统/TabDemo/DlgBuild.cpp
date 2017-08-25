// DlgBuild.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgBuild.h"
#include "afxdialogex.h"
#include "DlgTab1.h"


// CDlgBuild �Ի���

IMPLEMENT_DYNAMIC(CDlgBuild, CDialogEx)

CDlgBuild::CDlgBuild(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgBuild::IDD, pParent)
{

}

CDlgBuild::~CDlgBuild()
{
}

void CDlgBuild::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBuild, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgBuild::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgBuild::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgBuild ��Ϣ�������


void CDlgBuild::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//m_treeJourney.InsertItem(_T("����"),TVI_ROOT,TVI_LAST);//���һ�����ڵ�
	 //���EDIT 
	CEdit* pBoxOne; 
	pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT_NAME); 
	//ȡֵ
	CString str;
	pBoxOne-> GetWindowText(str); 

    HWND hWnd=::FindWindow(NULL,_T(""));      //�õ��Ի���ľ��
    CDlgTab1* pWnd= (CDlgTab1*)FromHandle(hWnd); //�ɾ���õ��Ի���Ķ���ָ��
    pWnd->m_treeJourney.InsertItem(_T("str"),TVI_ROOT,TVI_LAST);//���һ�����ڵ�                       
	MessageBox(str,_T("�����ɹ�"),MB_OK);
	str.ReleaseBuffer();

	CDialogEx::OnOK();
}


void CDlgBuild::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
