#pragma once
#include "explorer1.h"


// CDlgMap �Ի���

class CDlgMap : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMap)

public:
	CDlgMap(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMap();

// �Ի�������
	enum { IDD = IDD_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CExplorer1 m_map;
	afx_msg void OnBnClickedButtonOpenmap();
	afx_msg void OnBnClickedButtonPutin();
};
