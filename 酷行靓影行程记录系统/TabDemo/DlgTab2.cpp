// DlgTab2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgTab2.h"
#include "afxdialogex.h"
CString path[100];


// CDlgTab2 �Ի���

IMPLEMENT_DYNAMIC(CDlgTab2, CDialogEx)

CDlgTab2::CDlgTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTab2::IDD, pParent)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST22, m_list);
	//InitListCtrlStyle(); //���÷�����ʼ��ListCtrl����ʽ
	//RefreshListCtrlData(); //ˢ��ListCtrl������
	DDX_Control(pDX, IDC_PICTURE, m_picture);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST22, &CDlgTab2::OnLvnItemchangedList22)
	ON_BN_CLICKED(IDC_BUTTON_LOADPIC, &CDlgTab2::OnBnClickedButtonLoadpic)
	ON_BN_CLICKED(IDC_BIGPIC, &CDlgTab2::OnBnClickedBigpic)
	ON_BN_CLICKED(IDC_BUTTON_READNOTE, &CDlgTab2::OnBnClickedButtonReadnote)
	ON_BN_CLICKED(IDC_BUTTON_SAVENOTE, &CDlgTab2::OnBnClickedButtonSavenote)
	ON_NOTIFY(NM_CLICK, IDC_LIST22, &CDlgTab2::OnNMClickList22)
END_MESSAGE_MAP()


// CDlgTab2 ��Ϣ�������


void CDlgTab2::OnLvnItemchangedList22(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}




void CDlgTab2::OnBnClickedButtonLoadpic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

 m_list.DeleteAllItems();//�ͷ���һ�����еĻ���
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
			path[i]= cstrfilepath ;
			i++;
         }	
		
	    nPIC=i;

		}
     }


CImageList a;
	a.Create(100,100, ILC_COLOR32 |ILC_MASK , 8, 1);//������ʾͼƬ�Ĵ�С
		for(int j=0;j<nPIC;j++)
		{
		HBITMAP hBmp  = (HBITMAP)::LoadImage
			(
			::AfxGetInstanceHandle(), 
			path[j],
			IMAGE_BITMAP,
			100,
			100,
			LR_LOADFROMFILE
			);
		CBitmap* pBmp = CBitmap::FromHandle(hBmp); 		 
		a.Add(pBmp,RGB(0 ,0, 0));	
		m_list.SetImageList(&a,LVSIL_NORMAL);
		CString strTemp;
		strTemp.Format(_T("pic:%d"),j);
	    m_list.InsertItem(j,strTemp, j);
		

		}
	a.Detach();

}



void CDlgTab2::OnBnClickedBigpic()
{
/*CString str; 
 int nId; 
 //���ȵõ������λ�� 
POSITION pos=m_list.GetFirstSelectedItemPosition(); 
 if(pos==NULL) 
 { 
 MessageBox(TEXT("������ѡ��һ��"),NULL,MB_ICONEXCLAMATION); 
 return; 
 } 
 //�õ��кţ�ͨ��POSITIONת�� 
nId=(int)m_list.GetNextSelectedItem(pos); 

CString filename;
filename=path[nId];
CDC *pDC =m_picture.GetWindowDC(); 
		CImage m_image;
		m_image.Load(filename);//�ļ�·��

		CRect rect;
		m_picture.GetClientRect(&rect);

		int Width = rect.right - rect.left;
		int Height = rect.bottom - rect.top;

		pDC->SetStretchBltMode(STRETCH_HALFTONE); //����ʧ��
		m_image.Draw(pDC->m_hDC,0,0,Width,Height);
 //�õ����е����ݣ�0��ʾ��һ�У�ͬ��1,2,3...��ʾ�ڶ���������...�У� 


/*HBITMAP hBitmap;
  hBitmap = ::LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));
     m_Bmp.SetBitmap(hBitmap); 


	 HBITMAP hbitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),
  m_strfile,
 IMAGE_BITMAP,
 r.Width()/2,
 r.Height()/2,
 LR_LOADFROMFILE);  
 m_Bmp.SetBitmap(hbitmap);
*/
}


void CDlgTab2::OnBnClickedButtonReadnote()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT_NOTE); 
        pedit->LineScroll(pedit->GetLineCount());
	CString filename;                             // �򿪵��ļ����ַ���
    CFile file;                                         // �ļ�����
    DWORD len;                                    // ���ڱ����ļ�����
    CFileDialog    dlg(TRUE,_T(""),_T("*.*"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("*.*|*.*|"));

    DWORD local_1 = dlg.DoModal ();

    if(IDOK== local_1){
		filename = dlg.GetPathName();
	}
  else if( IDCANCEL == local_1){
      return ;
  }

  // ��ȡ����
   file.Open(filename,CFile::modeReadWrite);
   len = file.GetLength();
   char *pReadData = new char[len+1]; // �����ڴ�
  
    file.Read(pReadData,len);                                       //  ���ﱣ��Ķ�ȡ�ļ�������
	pReadData[len] = 0;

	file.Close();
  
   CEdit* pBoxOne;
   pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT_NOTE);
   ::SetWindowTextA(pBoxOne->m_hWnd, pReadData);
}


void CDlgTab2::OnBnClickedButtonSavenote()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;
	CFile file;
	DWORD len;

	CFileDialog *dlg = new CFileDialog(FALSE, _T("*.*"), _T("*.*"), OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("*.txt||"));
	DWORD local_2 = dlg->DoModal();

	if (IDOK==local_2) {
		filename = dlg->GetPathName();
	}
	else if (IDCANCEL == local_2) {
		return;
	}

	len = ::GetWindowTextLengthA(GetDlgItem(IDC_EDIT_NOTE)->m_hWnd);
	char *pReadData = new char[len+1]; // �����ڴ�
	::GetWindowTextA(GetDlgItem(IDC_EDIT_NOTE)->m_hWnd, pReadData, len);

	file.Open(filename, CFile::modeCreate|CFile::modeWrite);
	file.Write(pReadData, len);
	file.Close();
	delete pReadData;
	delete dlg;
}


void CDlgTab2::OnNMClickList22(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CString str; 
 int nId; 
 //���ȵõ������λ�� 
POSITION pos=m_list.GetFirstSelectedItemPosition(); 
 if(pos==NULL) 
 { 
 MessageBox(TEXT("������ѡ��һ��"),NULL,MB_ICONEXCLAMATION); 
 return; 
 } 
 //�õ��кţ�ͨ��POSITIONת�� 
nId=(int)m_list.GetNextSelectedItem(pos); 

CString filename;
filename=path[nId];
CDC *pDC =m_picture.GetWindowDC(); 
		CImage m_image;
		m_image.Load(filename);//�ļ�·��

		CRect rect;
		m_picture.GetClientRect(&rect);

		int Width = rect.right - rect.left;
		int Height = rect.bottom - rect.top;

		pDC->SetStretchBltMode(STRETCH_HALFTONE); //����ʧ��
		m_image.Draw(pDC->m_hDC,0,0,Width,Height);

		CString strt; 
        int n = filename.ReverseFind('.') ;
        strt = filename.Left(n);
	    CString cc;
	    cc=strt+".txt";
		CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT_NOTE); 
        pedit->LineScroll(pedit->GetLineCount());
		CFile file;                                         // �ļ�����
        DWORD len;   // ���ڱ����ļ�����
		file.Open( cc,CFile::modeReadWrite);
        len = file.GetLength();
        char *pReadData = new char[len+1]; // �����ڴ�
  
        file.Read(pReadData,len);                                       //  ���ﱣ��Ķ�ȡ�ļ�������
	    pReadData[len] = 0;

	    file.Close();
  
       CEdit* pBoxOne;
       pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT_NOTE);
       ::SetWindowTextA(pBoxOne->m_hWnd, pReadData);
}
