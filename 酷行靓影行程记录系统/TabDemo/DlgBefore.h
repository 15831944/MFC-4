#pragma once


// CDlgBefore �Ի���

class CDlgBefore : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBefore)

public:
	CDlgBefore(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgBefore();

// �Ի�������
	enum { IDD = IDD_DLGBEFORE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_csID;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditId();
	afx_msg void OnEnChangeEdit1();
};
