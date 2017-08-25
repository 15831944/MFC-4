// DlgBefore.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgBefore.h"
#include "afxdialogex.h"

#include "TabDemoDlg.h"

// CDlgBefore �Ի���

IMPLEMENT_DYNAMIC(CDlgBefore, CDialogEx)

CDlgBefore::CDlgBefore(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgBefore::IDD, pParent)
{

	m_csID = _T("");
}

CDlgBefore::~CDlgBefore()
{
}

void CDlgBefore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_csID);
	DDV_MaxChars(pDX, m_csID, 8);
}


BEGIN_MESSAGE_MAP(CDlgBefore, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgBefore::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgBefore::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_ID, &CDlgBefore::OnEnChangeEditId)
END_MESSAGE_MAP()


// CDlgBefore ��Ϣ�������


void CDlgBefore::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	CTabDemoDlg m_TabDemoDlg;

	m_TabDemoDlg.m_pParent = this;
	
	m_TabDemoDlg.DoModal();

	

	CDialogEx::OnOK();
}

void CDlgBefore::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}




void CDlgBefore::OnEnChangeEditId()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
