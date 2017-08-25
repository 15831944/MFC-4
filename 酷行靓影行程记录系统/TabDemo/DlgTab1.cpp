// DlgTab1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabDemo.h"
#include "DlgTab1.h"
#include "afxdialogex.h"
#include "explorer2.h"
#include <Mshtml.h>
//#include "WebPage.h"
#include "DlgAfter.h"
#include "exif.h"
#include "istream"

CString  pfilename[100];

// CDlgTab1 �Ի���

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTab1::IDD, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST11, m_list);
	//InitListCtrlStyle(); //���÷�����ʼ��ListCtrl����ʽ
	//RefreshListCtrlData(); //ˢ��ListCtrl������

	DDX_Control(pDX, IDC_EXPLORER2, m_mymap);
	DDX_Control(pDX, IDC_TREE_JOURNEY, m_treeJourney);
	HWND hWnd=::FindWindow(NULL,_T("Sphere"));      //�õ��Ի���ľ��
    CDlgTab1* pWnd= (CDlgTab1*)FromHandle(hWnd); //�ɾ���õ��Ի���Ķ���ָ��
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTab1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_OPENMAP2, &CDlgTab1::OnBnClickedButtonOpenmap2)
	
	//ON_BN_CLICKED(IDC_BUTTON_DELETE, &CDlgTab1::OnBnClickedButtonDelete)
	ON_NOTIFY(NM_CLICK, IDC_TREE_JOURNEY, &CDlgTab1::OnNMClickTreeJourney)
	ON_BN_CLICKED(IDC_BUTTON_NEW_ONE, &CDlgTab1::OnBnClickedButtonNewOne)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_JOURNEY, &CDlgTab1::OnNMRClickTreeJourney)
	ON_COMMAND(ID__MENU_DELETE, &CDlgTab1::OnMenuDelete)
	ON_BN_CLICKED(IDC_BUTTON_OPENMAP3, &CDlgTab1::OnBnClickedButtonOpenmap3)
	ON_BN_CLICKED(IDC_BUTTON_WRITEPIC, &CDlgTab1::OnBnClickedButtonWritepic)
	ON_BN_CLICKED(IDC_BUTTON_PICIN, &CDlgTab1::OnBnClickedButtonPicin)
	ON_BN_CLICKED(IDC_BUTTON_TRACK, &CDlgTab1::OnBnClickedButtonTrack)
END_MESSAGE_MAP()




// CDlgTab1 ��Ϣ�������

/*//��ʼ��ListCtrl�ؼ�
int CDlgTab1::InitListCtrlStyle(void)
{
	//���ListCtrl�Ŀ��
	CRect rect;
	m_list.GetClientRect(&rect);
	int nColInterval = rect.Width();

//����ListCtrl����ʽ
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

//�������������������еĶ����ʽ���п�
	m_list.InsertColumn(0, _T("��Ƭ"), LVCFMT_RIGHT, int (nColInterval * 0.2));
	m_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, int (nColInterval * 0.2));
	m_list.InsertColumn(2, _T("��Ƭ��Ϣ"), LVCFMT_LEFT, int (nColInterval * 0.4));
	return 0;

}

*/



/*void CDlgTab1::OnOpenpic()
{
// TODO: �ڴ���������������
unsigned char  pData[100*100*4];
BITMAP BitMap;
BitMap.bmType=0;
BitMap.bmHeight=100;
BitMap.bmWidth=100;
BitMap.bmWidthBytes=100*4;//���ڻ����bmWidth*bmBitsPixel/8���õ�ֵ
BitMap.bmPlanes=1;
BitMap.bmBitsPixel=32;
BitMap.bmBits=pData;
   for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		{
			pData[i*100*4+j*4] = 100+j*3;
			pData[i*100*4+j*4+1] = 130+i;
			pData[i*100*4+j*4+2] = i*2+j+50;

		}
		CBitmap cb;
		cb.CreateBitmapIndirect(&BitMap);		


CImageList a;
	a.Create(100,100, ILC_COLOR32 |ILC_MASK , 8, 1);
		a.Add(&cb,RGB(0,0, 0));
		a.Add(&cb,RGB(255,255, 255));
		a.Add(&cb,RGB(255,255, 255));
		a.Add(&cb,RGB(255,255, 255));
		a.Add(&cb,RGB(255,255, 255));
	m_list.SetImageList(&a,LVSIL_NORMAL);
		CString strTemp;
		for (int n = 0; n < 5; n++)
		{
			strTemp.Format(_T("pic:%d"),n);
			m_list.InsertItem(n,strTemp, n);
		}
		a.Detach();

}

*/


void CDlgTab1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

}

/*int CDlgTab1::InitListCtrlStyle(void)
{
	//���ListCtrl�Ŀ��
	CRect rect;
	m_list.GetClientRect(&rect);
	int nColInterval = rect.Width();

	//����ListCtrl����ʽ
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//�������������������еĶ����ʽ���п�
	m_list.InsertColumn(0, _T("��Ʒ"), LVCFMT_RIGHT, int (nColInterval * 0.2));
	m_list.InsertColumn(1, _T("��·"), LVCFMT_LEFT, int (nColInterval * 0.2));
	m_list.InsertColumn(2, _T("ʱ��"), LVCFMT_LEFT, int (nColInterval * 0.2));
	return 0;
}


int CDlgTab1::RefreshListCtrlData(void)
{//����ʮ��ģ������

	int i;
	for(i = 0; i < 10; i++)
	{
		CString temp, strCardID;
		strCardID.Format(_T("%d"), i);


		//���ListCtrl�ĵ�ǰ��¼���ݵ�����iItemCount
		int iItemCount = m_list.GetItemCount();
		m_list.InsertItem(iItemCount, temp);

		//��iItemCount�����һ�����ݣ������뿨��

		m_list.SetItemText(iItemCount, 0, strCardID);

		//��iItemCount����ڶ������ݣ�����������

		m_list.SetItemText(iItemCount, 1, strCardID);
	}
	return 0;
}
*/
void CDlgTab1::OnBnClickedButtonOpenmap2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*
	 m_mymap.Navigate(_T("file:///C:/Users/K550/Desktop/map.html"),NULL,NULL,NULL,NULL);
    
    CString m_JD="106.562627";
	CString m_WD="29.613458";
	 
	CWebPage web;
    web.SetDocument(m_mymap.get_Document());
	const CString funcName("justmarkfun");
	CComVariant varResult;
	web.CallJScript(funcName,m_JD,m_WD,&varResult);//����m_JD��m_WD����༭��ؼ�������CString���ͱ���,���뾭��γ��ֵ��������ĸ���Ҫ��javascript����justmakefun�����ĸ�����ͬ,����˳��Ҫ����һ��
	 
	// m_mymap.Navigate(_T("icqu.sinaapp.com/Baidu/map.html"),NULL,NULL,NULL,NULL);
	 
	
	CString m_JD="106.562627";
	CString m_WD="29.613458";

	


	 m_mymap.Navigate(_T("file:///C:/Users/K550/Desktop/map.html"),NULL,NULL,NULL,NULL);
	 CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
     CComDispatchDriver spScript;
     spDoc->get_Script(&spScript);
	 CComVariant JD;
	 CComVariant WD;
     CComVariant varRet;
	    JD=m_JD;
	    WD=m_WD;
	spScript.Invoke2(L"justmarkfun", &JD, &WD, &varRet);
	*/
}




BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
 m_mymap.Navigate(_T("file:///C:/Users/K550/Desktop/map4.htm"),NULL,NULL,NULL,NULL);
 CFileFind         tempFind;
 CString path="G:\\MyJourney";
 CString strFileName; 
 int   nCount=0;
 BOOL bIsFinded;

 bIsFinded = (BOOL)tempFind.FindFile( path );
 if(!bIsFinded)
 {
 AfxMessageBox("Ŀ¼������!");
//return;
 }

 path += "\\*.*";
 bIsFinded = (BOOL)tempFind.FindFile( path );

 while( bIsFinded )
 {
 bIsFinded = (BOOL)tempFind.FindNextFile(); 
 if( !tempFind.IsDots() ) 
 {
 nCount++;
 //ÿ�εõ�һ���ļ���
strFileName = tempFind.GetFileName();
HTREEITEM hRootItem = m_treeJourney.InsertItem(strFileName,TVI_ROOT,TVI_LAST); 
 }
 }
 tempFind.Close();
	//HTREEITEM hRootItem = m_treeJourney.InsertItem(_T("ѡ���г�"),TVI_ROOT,TVI_LAST);  //��ʼ��tree�ĸ����ڵ�
	//m_treeJourney.Expand(hRootItem,TVE_EXPAND);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgTab1::OnNMClickTreeJourney(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//*pResult = 0;
	//��ȡ�û����ʱ����λ��
	CPoint point;
	GetCursorPos(&point);

	//���������ת��Ϊ���ؼ��ϵ�����
	CPoint pointInTree = point;
	m_treeJourney.ScreenToClient(&pointInTree);

	//�жϵ�ǰ���û�����һ���ڵ��ϵ�ѡ
	HTREEITEM hCurItem;
	UINT flag = TVHT_ONITEM;
	hCurItem = m_treeJourney.HitTest(pointInTree,&flag);
	CString PATH[100];
	if(hCurItem != NULL)
	{   
		CString csItem = m_treeJourney.GetItemText(hCurItem);
		int length=csItem.GetLength();
		if(length!= 0)
		{
			

			CFileFind Filefinder;
			CString strDir="G:\\MyJourney\\"+csItem;
            strDir=strDir+"\\*.jpg";
            BOOL bWorking=Filefinder.FindFile(strDir);
			//CString PATH[100];
			static int i=0;
			int num;
            while(bWorking)
             {
                bWorking=Filefinder.FindNextFile();
				// if (/*f.IsDirectory() &&*/ !Filefinder.IsDots())
				// {
					 CString aaFilename = "";
	                 aaFilename =Filefinder.GetFilePath();
					 PATH[i]=aaFilename;
					 i++;
					 num=i;
				// }

			}
              Filefinder.Close();
           
	for(int j=0;j<num;j++)
	{
		
		char aFilename[100] ;
	    USES_CONVERSION;
	    LPCWSTR pwcStr=A2CW((LPCSTR)  PATH[j]); 
	   //��ȡfilename�ĳ���
	    int iByteLen = WideCharToMultiByte(CP_ACP,0,pwcStr, PATH[j].GetLength(),NULL,0,NULL,NULL);
       //��CStringת����char*
       WideCharToMultiByte(CP_ACP,0, pwcStr, PATH[j].GetLength(), aFilename, iByteLen,NULL,NULL);
       aFilename[iByteLen] = '\0';

	

	   FILE* hFile= fopen(aFilename,"rb");	
	
	   if (hFile){

		memset(&m_exifinfo,0,sizeof(EXIFINFO));

		Cexif exif(&m_exifinfo);
		exif.DecodeExif(hFile);

		fclose(hFile);

		if (m_exifinfo.IsExif) 
		{
			//ShowInfoo();      //��ȡ��Ƭexif��Ϣ��s��
	  
        CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
        CComDispatchDriver spScript;
        spDoc->get_Script(&spScript);
		/*
	    CComVariant varRet;
	    CComVariant JD;
	    CComVariant WD;
	    JD=m_exifinfo.Longitude;
	    WD=m_exifinfo.Latitude;
        spScript.Invoke2(L"MakePoint", &JD, &WD, &varRet);
		*/
		//CComVariant  var;
	   // spScript.Invoke1(L"drivecar",&var);

		CComVariant varpic;
		CComVariant varmap;
		varpic=PATH[j];
		spScript.Invoke1(L"Picture",&varpic,&varmap); 
		
	   // CComVariant  var;
	   // spScript.Invoke1(L"drivecar",&var);
		//CComVariant  var;
	    //spScript.Invoke1(L"drivecar",&var);

		CString str; 
        int n = PATH[j].ReverseFind('.') ;
        str = PATH[j].Left(n);
	    CString cc;
	    cc=str+".txt";
		CString filenametxt=cc;
		CFile fFile(filenametxt,CFile::modeRead);   
		CStringA strFile ;  
		fFile.Read(strFile.GetBufferSetLength(fFile.GetLength()),fFile.GetLength());  
		fFile.Close(); 
		strFile.ReleaseBuffer();
		CComVariant vartxt=strFile;
		spScript.Invoke1(L"Message",&vartxt,&varmap); 
		
		CComVariant varRet;
	    CComVariant JD;
	    CComVariant WD;
	    JD=m_exifinfo.Longitude;
	    WD=m_exifinfo.Latitude;
        spScript.Invoke2(L"MakePoint", &JD, &WD, &varRet);
		//PATH[j].ReleaseBuffer();
		/*
		CComVariant varmap;
		CComVariant varpic= PATH[j];
		spScript.Invoke1(L"Picture",&varpic,&varmap);//arpic ��ͼƬ�ĵ�ַ 
		*/
		


		}
		else
		{
			return;
		}
	  
	  }
	}  /*
	    CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
        CComDispatchDriver spScript;
        spDoc->get_Script(&spScript);
	    CComVariant  var;
	    spScript.Invoke1(L"drivecar",&var);
		*/
		}//
		else
		{
			return;//m_listShow.DeleteAllItems();
		}
	}
}


/*void CDlgTab1::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//*pResult = 0;
	//��ȡ�û����ʱ����λ��
	CPoint point;
	GetCursorPos(&point);

	//���������ת��Ϊ���ؼ��ϵ�����
	CPoint pointInTree = point;
	m_treeJourney.ScreenToClient(&pointInTree);

	//�жϵ�ǰ���û�����һ���ڵ��ϵ�ѡ
	HTREEITEM hCurItem;
	UINT flag = TVHT_ONITEM;
	hCurItem = m_treeJourney.HitTest(pointInTree,&flag);
	
	if(hCurItem != NULL)
	{
		
		
			m_treeJourney.DeleteItem(hCurItem);
            hCurItem = NULL;
	}
	

}
*/



void CDlgTab1::OnBnClickedButtonNewOne()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit* pBoxOne; 
	pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT_NAMESHOW); 
	//ȡֵ
	CString str;
	pBoxOne-> GetWindowText(str);
     
	int length= str.GetLength();
	if( length==0){
       MessageBox(_T("�������г�����"),_T("ע��"),MB_OK);
	}
	else{
	   //m_treeJourney.InsertItem(str,TVI_ROOT,TVI_LAST);//���һ�����ڵ� 
	   HTREEITEM hRootItem = m_treeJourney.InsertItem(str,TVI_ROOT,TVI_LAST);  //��ʼ��tree�ĸ����ڵ�
	   MessageBox(str,_T("�����ɹ�"),MB_OK);
	   CString Pathstr="G:\\MyJourney\\";
	   CreateDirectory(Pathstr+ str, NULL); 
	   MessageBox(str,_T("�����ɹ�"),MB_OK);
	}

	
	//str.ReleaseBuffer();
}



void CDlgTab1::OnNMRClickTreeJourney(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	

	//��ȡ�û��Ҽ�ʱ����λ��
	CPoint point;
	GetCursorPos(&point);

	//���������ת��Ϊ���ؼ��ϵ�����
	CPoint pointInTree = point;
	m_treeJourney.ScreenToClient(&pointInTree);

	//�ж��û�����һ���ڵ��ѡ
	HTREEITEM item;
	UINT flag = TVHT_ONITEM;
	item = m_treeJourney.HitTest(pointInTree,&flag);

	//���ж�Ӧ�Ľڵ�ʱ
	if(item != NULL)
	{
		//����ѡ�иýڵ�
		m_treeJourney.SelectItem(item);
		m_itemCur = item;

		//�����Ҽ��˵���ʾ
		CMenu menu;
		menu.LoadMenu(IDR_MENU2);
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN |
			 TPM_RIGHTBUTTON,point.x,point.y,this,NULL);
	}
}


void CDlgTab1::OnMenuDelete()
{
	// TODO: �ڴ���������������
	if(m_itemCur != NULL)
	{
		m_treeJourney.DeleteItem(m_itemCur);

		m_itemCur = NULL;
	}
}


void CDlgTab1::OnBnClickedButtonOpenmap3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString m_JD="106.562627";
	CString m_WD="29.613458";
     //float m_JD=106.562627;
	 // float m_WD=29.613458;

	 m_mymap.Navigate(_T("file:///C:/Users/K550/Desktop/map4.htm"),NULL,NULL,NULL,NULL);
	 CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
     CComDispatchDriver spScript;
     spDoc->get_Script(&spScript);
	 
     
	 CComVariant JD;
	 CComVariant WD;
	 CComVariant varRet;
	    JD=m_JD;
	    WD=m_WD;
	spScript.Invoke2(L"MakePoint", &JD, &WD, &varRet);
	/*
	 if( varRet. dblVal == 122.211 ) { // double�Ͷ�ӦdblVal�����ζ�ӦintVal

                   MessageBox(NULL,_T("�����ɹ�"),MB_OK);
	 }
	 else{
	 
		  MessageBox(NULL,_T("����ʧ��"),MB_OK);
	 }
	 */
}


void CDlgTab1::OnBnClickedButtonWritepic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlgAfter m_DlgAfter;

	m_DlgAfter.DoModal();
}

bool CDlgTab1::PromptForFileName(CString& fileName, UINT nIDSTitle, DWORD dwFlags, bool bOpenFileDialog, int* pType)
{
	CFileDialog dlgFile(bOpenFileDialog);
	CString title;
	if (bOpenFileDialog) title = _T("ѡ��ͼƬ"); 
	else title = _T("Save file");

	dlgFile.m_ofn.Flags |= dwFlags;

	int nDocType = (pType != NULL) ? *pType : 0;

	int nIndex = 0;

	dlgFile.m_ofn.nFilterIndex = nIndex +1;
	CString strDefExt = _T("pal");
	dlgFile.m_ofn.lpstrDefExt = strDefExt;

	CString strFilter = _T("*.jpg");
	strFilter += (TCHAR)NULL;
	strFilter += _T("*.jpg");
	strFilter += (TCHAR)NULL;
	strFilter += _T("*.*");
	strFilter += (TCHAR)NULL;
	strFilter += _T("*.*");
	strFilter += (TCHAR)NULL;

	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.lpstrFile = fileName.GetBuffer(_MAX_PATH);

	BOOL bRet = (dlgFile.DoModal() == IDOK) ? TRUE : FALSE;
	fileName.ReleaseBuffer();
	if (bRet){
		if (pType != NULL){
			int nIndex = (int)dlgFile.m_ofn.nFilterIndex - 1;
			ASSERT(nIndex >= 0);
		}
	}
	return bRet;
}
void CDlgTab1::OnBnClickedButtonPicin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//��ȡ��Ƭ�ĵ�ַ
	//m_mymap.DeleteAllItems();
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
			pfilename[i]= cstrfilepath ;
			i++;
         }	
		
	    nPIC=i;

		}
     }
	
    m_mymap.Navigate(_T("file:///C:/Users/K550/Desktop/map4.htm"),NULL,NULL,NULL,NULL);
	
	for(int j=0;j<nPIC;j++)
	{

		char aFilename[100] ;
	    USES_CONVERSION;
	    LPCWSTR pwcStr=A2CW((LPCSTR)  pfilename[j]); 
	   //��ȡfilename�ĳ���
	    int iByteLen = WideCharToMultiByte(CP_ACP,0,pwcStr,  pfilename[j].GetLength(),NULL,0,NULL,NULL);
       //��CStringת����char*
       WideCharToMultiByte(CP_ACP,0, pwcStr, pfilename[j].GetLength(), aFilename, iByteLen,NULL,NULL);
       aFilename[iByteLen] = '\0';

	

	   FILE* hFile= fopen(aFilename,"rb");	
	
	   if (hFile){

		memset(&m_exifinfo,0,sizeof(EXIFINFO));

		Cexif exif(&m_exifinfo);
		exif.DecodeExif(hFile);

		fclose(hFile);

		if (m_exifinfo.IsExif) 
		{
			//ShowInfoo();      //��ȡ��Ƭexif��Ϣ��s��
     CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
     CComDispatchDriver spScript;
     spDoc->get_Script(&spScript);
	 CComVariant varRet;
	    CComVariant JD;
	    CComVariant WD;
	    JD=m_exifinfo.Longitude;
	    WD=m_exifinfo.Latitude;
        spScript.Invoke2(L" MakePoint", &JD, &WD, &varRet);

		CComVariant varmap;
		CComVariant varpic= pfilename[j];
		spScript.Invoke1(L"Picture",&varpic,&varmap);//arpic ��ͼƬ�ĵ�ַ 
		pfilename[j].ReleaseBuffer();


		}
		else
		{
			return;
		}
	
	  }
	}
}

void CDlgTab1::ShowInfoo(void)
	{
	CString t;
	ss="";

	if (m_exifinfo.CameraMake[0]){
		t.Format(_T("�����������  : %s\n"),CString(m_exifinfo.CameraMake)); ss+=t;
		t.Format(_T("������ͺ�     : %s\n"),CString(m_exifinfo.CameraModel)); ss+=t;
	}
	if (m_exifinfo.DateTime[0]){
		t.Format(_T("����ʱ��        : %s\n"),CString(m_exifinfo.DateTime)); ss+=t;
	}
	if (m_exifinfo.Version[0]){
		t.Format(_T("EXIF �汾       : %s\n"),CString(m_exifinfo.Version)); ss+=t;
	}

	t.Format(_T("�ֱ���           : %d x %d\n"),m_exifinfo.Width, m_exifinfo.Height); ss+=t;
	t.Format(_T("���              : %d ����\n"),m_exifinfo.Width); ss+=t;
	t.Format(_T("�߶�              : %d ����\n"),m_exifinfo.Height); ss+=t;

	if ((m_exifinfo.ResolutionUnit!=0)&&(m_exifinfo.Xresolution!=0)){
		t.Format(_T("ˮƽ�ֱ���     : %5.1fdpi\n"),m_exifinfo.Xresolution/m_exifinfo.ResolutionUnit); ss+=t;
	}
	if ((m_exifinfo.ResolutionUnit!=0)&&(m_exifinfo.Yresolution!=0)){
		t.Format(_T("��ֱ�ֱ���     : %5.1fdpi\n"),m_exifinfo.Yresolution/m_exifinfo.ResolutionUnit); ss+=t;
	}

	if (m_exifinfo.Orientation > 1){
		t.Format(_T("Orientation  : %s\n"), m_exifinfo.Orientation); ss+=t;
	}
	if (m_exifinfo.IsColor == 0){
		t.Format(_T("Color/bw     : Black and white\n")); ss+=t;
	}
	if (m_exifinfo.FlashUsed >= 0){
		t.Format(_T("�����ģʽ     : %s\n"),m_exifinfo.FlashUsed ? _T("������") :_T("������")); ss+=t;
	}
	if (m_exifinfo.FocalLength){
		t.Format(_T("����     : %4.1fmm"),(double)m_exifinfo.FocalLength); ss+=t;
		if (m_exifinfo.CCDWidth){
			t.Format(_T("  (35mm equivalent: %dmm)"),
				(int)(m_exifinfo.FocalLength/m_exifinfo.CCDWidth*36 + 0.5)); ss+=t;
		}
		t.Format(_T("\n")); ss+=t;
	}
	if(m_exifinfo.Latitude > 0.0)
	{
		t.Format(_T("γ��     : %4.15f \n"), (double)m_exifinfo.Latitude);
		ss+=t;
	}
	if(m_exifinfo.Longitude > 0.0)
	{
		t.Format(_T("����     : %4.15f \n"), (double)m_exifinfo.Longitude);
		ss+=t;
	}

	if (m_exifinfo.CCDWidth){
		t.Format(_T("CCD width     : %4.2fmm\n"),(double)m_exifinfo.CCDWidth); ss+=t;
	}

	if (m_exifinfo.ExposureTime){
		t.Format(_T("�ع�ʱ��        :%6.3f s "),(double)m_exifinfo.ExposureTime); ss+=t;
		if (m_exifinfo.ExposureTime <= 0.5){
			t.Format(_T(" (1/%d)"),(int)(0.5 + 1/m_exifinfo.ExposureTime)); ss+=t;
		}
		t.Format(_T("\n")); ss+=t;
	}
	if (m_exifinfo.Brightness){
		t.Format(_T("Brightness : %6.3f\n"),m_exifinfo.Brightness); ss+=t;
	}
	if (m_exifinfo.ApertureFNumber){
		t.Format(_T("��Ȧֵ           : f/%3.1f\n"),(double)m_exifinfo.ApertureFNumber); ss+=t;
	}
	if (m_exifinfo.Distance){
		if (m_exifinfo.Distance < 0){
			t.Format(_T("Focus dist.  : Infinite\n")); ss+=t;
		}else{
			t.Format(_T("Focus dist.  : %4.2fm\n"),(double)m_exifinfo.Distance); ss+=t;
		}
	}


	if (m_exifinfo.ISOequivalent){ // 05-jan-2001 vcs
		t.Format(_T("ISO �ٶ�.       : %2d\n"),(int)m_exifinfo.ISOequivalent); ss+=t;
	}
	if (m_exifinfo.ExposureBias){ // 05-jan-2001 vcs
		t.Format(_T("Exposure bias:%4.2f\n"),(double)m_exifinfo.ExposureBias); ss+=t;
	}

	if (m_exifinfo.Whitebalance){ // 05-jan-2001 vcs
		switch(m_exifinfo.Whitebalance) {
		case 1:
			t.Format(_T("Whitebalance : sunny\n")); ss+=t;
			break;
		case 2:
			t.Format(_T("Whitebalance : fluorescent\n")); ss+=t;
			break;
		case 3:
			t.Format(_T("Whitebalance : incandescent\n")); ss+=t;
			break;
		default:
			t.Format(_T("Whitebalance : cloudy\n")); ss+=t;
		}
	}
	if (m_exifinfo.MeteringMode){ // 05-jan-2001 vcs
		switch(m_exifinfo.MeteringMode) {
		case 2:
			t.Format(_T("Metering Mode: center weight\n")); ss+=t;
			break;
		case 3:
			t.Format(_T("Metering Mode: spot\n")); ss+=t;
			break;
		case 5:
			t.Format(_T("Metering Mode: matrix\n")); ss+=t;
			break;
		}
	}
	if (m_exifinfo.ExposureProgram){ // 05-jan-2001 vcs
		switch(m_exifinfo.ExposureProgram) {
		case 2:
			t.Format(_T("Exposure     : program (auto)\n")); ss+=t;
			break;
		case 3:
			t.Format(_T("Exposure     : aperture priority (semi-auto)\n")); ss+=t;
			break;
		case 4:
			t.Format(_T("Exposure     : shutter priority (semi-auto)\n")); ss+=t;
			break;
		}
	}
	if (m_exifinfo.CompressionLevel){ // 05-jan-2001 vcs
		switch(m_exifinfo.CompressionLevel) {
		case 1:
			t.Format(_T("Jpeg Quality : basic\n")); ss+=t;
			break;
		case 2:
			t.Format(_T("Jpeg Quality : normal\n")); ss+=t;
			break;
		case 4:
			t.Format(_T("Jpeg Quality : fine\n")); ss+=t;
			break;
		}
	}

	t.Format(_T("Encoding       : ")); ss+=t;
	switch(m_exifinfo.Process){
	case 0xC0: //M_SOF0
		t.Format(_T("Baseline\n")); ss+=t;
		break;
	case 0xC1: //M_SOF1
		t.Format(_T("Extended sequential\n")); ss+=t;
		break;
	case 0xC2: //M_SOF2
		t.Format(_T("Progressive\n")); ss+=t;
		break;
	case 0xC3: //M_SOF3
		t.Format(_T("Lossless\n")); ss+=t;
		break;
	case 0xC5: //M_SOF5
		t.Format(_T("Differential sequential\n"));ss+=t;
		break;
	case 0xC6: //M_SOF6
		t.Format(_T("Differential progressive\n")); ss+=t;
		break;
	case 0xC7: //M_SOF7
		t.Format(_T("Differential lossless\n")); ss+=t;
		break;
	case 0xC9: //M_SOF9
		t.Format(_T("Extended sequential, arithmetic coding\n")); ss+=t;
		break;
	case 0xCA: //M_SOF10
		t.Format(_T("Progressive, arithmetic coding\n")); ss+=t;
		break;
	case 0xCB: //M_SOF11
		t.Format(_T("Lossless, arithmetic coding\n")); ss+=t;
		break;
	case 0xCD: //M_SOF13
		t.Format(_T("Differential sequential, arithmetic coding\n")); ss+=t;
		break;
	case 0xCE: //M_SOF14
		t.Format(_T("Differential progressive, arithmetic coding\n")); ss+=t;
		break;
	case 0xCF: //M_SOF0
		t.Format(_T("Differential lossless, arithmetic coding\n")); ss+=t;
		break;
	default:
		t.Format(_T("Unknown\n")); ss+=t;
		break;
	}

	// Print the comment. Print 'Comment:' for each new line of comment.
	if (m_exifinfo.Comments[0]){
		int a,c;
		t.Format(_T("Comment      : ")); 
		ss+=t;
		for (a=0;a<MAX_COMMENT;a++){
			c = m_exifinfo.Comments[a];
			if (c == '\0') break;
			if (c == '\n'){
				// Do not start a new line if the string ends with a carriage return.
				if (m_exifinfo.Comments[a+1] != '\0'){
					t.Format(_T("\nComment      : ")); 
					ss+=t;
				}else{
					t.Format(_T("\n")); 
					ss+=t;
				}
			}else{
				ss.Format(_T("%s%d"),ss,c);
				// s+=c;
			}
		}
	}

	t.Format(_T("\n")); ss+=t;

	//MessageBox(s,TEXT("EXIF"),MB_OK|MB_ICONQUESTION);
	
	}


	void CDlgTab1::OnBnClickedButtonTrack()
	{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	    CComQIPtr<IHTMLDocument2> spDoc = m_mymap.get_Document();
        CComDispatchDriver spScript;
        spDoc->get_Script(&spScript);
		CComVariant  var;
	    spScript.Invoke1(L"drivecar",&var);

	}
