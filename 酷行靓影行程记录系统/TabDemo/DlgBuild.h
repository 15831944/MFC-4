#pragma once
//CString workname;

// CDlgBuild �Ի���

class CDlgBuild : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBuild)

public:
	CDlgBuild(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgBuild();

// �Ի�������
	enum { IDD = IDD_DLGBUILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
