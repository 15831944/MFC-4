#pragma once
#include"exif.h"

/*#include "atlimage.h"
#include "istream"*/
static CString s;
// CDlgAfter �Ի���

class CDlgAfter : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAfter)

public:
	CDlgAfter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAfter();

// �Ի�������
	enum { IDD = IDD_DLGAFTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
	EXIFINFO m_exifinfo;
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButton1();
	bool PromptForFileName(CString& fileName, UINT nIDSTitle, DWORD dwFlags, bool bOpenFileDialog, int* pType);
	void ShowInfo(void);
	CStatic m_ShowPicture;

	afx_msg void OnBnClickedButtonAddpic();
};
