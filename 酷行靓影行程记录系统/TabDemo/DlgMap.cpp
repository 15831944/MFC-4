// DlgMap.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgMap.h"
#include "afxdialogex.h"
#include "explorer1.h"
//#include <Mshtml.h>
//#include "WebPage.h"
CString mpath[100];
// CDlgMap �Ի���

IMPLEMENT_DYNAMIC(CDlgMap, CDialogEx)
	
CDlgMap::CDlgMap(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMap::IDD, pParent)
{

}

CDlgMap::~CDlgMap()
{
}

void CDlgMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_map);
}


BEGIN_MESSAGE_MAP(CDlgMap, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CDlgMap::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CDlgMap::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_OPENMAP, &CDlgMap::OnBnClickedButtonOpenmap)
	ON_BN_CLICKED(IDC_BUTTON_OPENMAP, &CDlgMap::OnBnClickedButtonOpenmap)
	ON_BN_CLICKED(IDC_BUTTON_PUTIN, &CDlgMap::OnBnClickedButtonPutin)
END_MESSAGE_MAP()


// CDlgMap ��Ϣ�������


void CDlgMap::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	//DestroyWindow();
}


void CDlgMap::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}





void CDlgMap::OnBnClickedButtonOpenmap()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_map.Navigate(_T("file:///C:/Users/K550/Desktop/map3.html"),NULL,NULL,NULL,NULL);
    /*
    CString m_JD="106.562627";
	CString m_WD="29.613458";
	 
	CWebPage web;
    web.SetDocument(m_map.get_Document());
	const CString funcName("justmarkfun");
	CComVariant varResult;
	web.CallJScript(funcName,m_JD,m_WD,&varResult);//����m_JD��m_WD����༭��ؼ�������CString���ͱ���,���뾭��γ��ֵ��������ĸ���Ҫ��javascript����justmakefun�����ĸ�����ͬ,����˳��Ҫ����һ��
	 if( varResult. dblVal == 122.211 ) { // double�Ͷ�ӦdblVal�����ζ�ӦintVal

                   MessageBox(NULL,_T("�����ɹ�"),MB_OK);
	 }
	 else{
	 
		  MessageBox(NULL,_T("����ʧ��"),MB_OK);
	 }
	*/
}


void CDlgMap::OnBnClickedButtonPutin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_map.DeleteAllItems();//�ͷ���һ�����еĻ���
 size_t index;
 CString cstrsucstring;

 CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT |OFN_ALLOWMULTISELECT,_T("image files (*.bmp; *.jpg) |*.bmp; *.jpg | All Files (*.*) |*.*||"), NULL);
   
 TCHAR *pBuffer = new TCHAR[MAX_PATH    * 20];//�������ͬʱ��20���ļ�
 filedlg.m_ofn.lpstrFile = pBuffer;
 filedlg.m_ofn.nMaxFile = MAX_PATH * 20;
 filedlg.m_ofn.lpstrFile[0] = '\0';

 int nPIC=20;
 CString cstrfilepath = _T("");

 if (filedlg.DoModal() == IDOK)
     {
        for(static int i=0;i<nPIC;)
		{
         POSITION pos = filedlg.GetStartPosition();
         while (pos != NULL)
         {

            cstrfilepath = filedlg.GetNextPathName(pos);//ȡ���ļ�·��
			 mpath[i]= cstrfilepath ;
			i++;
         }	
		
	    nPIC=i;

		}
     }

 

	/*
	CWebPage web;
    web.SetDocument(m_map.GetDocument());
	const CString funcName("justmarkfun");
	CComVariant varResult;
	web.CallJScript(funcName,m_JD,m_WD,&varResult);//����m_JD��m_WD����༭��ؼ�������CString���ͱ���,���뾭��γ��ֵ��������ĸ���Ҫ��javascript����justmakefun�����ĸ�����ͬ,����˳��Ҫ����һ��
	*/

}
