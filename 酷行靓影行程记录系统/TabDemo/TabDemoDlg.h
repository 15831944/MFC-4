
// TabDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "DlgTab1.h"
#include "DlgTab2.h"
#include "DlgTab3.h"



#include "DlgBefore.h"

// CTabDemoDlg �Ի���
class CTabDemoDlg : public CDialogEx
{
// ����
public:
	CTabDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TABDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
private:
	CDC  m_dcMain;
	CBitmap m_bmpMain;
	CDC  m_dcBk;
	CBitmap m_bmpBk;


public:
void LoadDlgBk(int iBmpID);//���ر���ͼƬ

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;

	CDlgTab1 m_tab1;
	CDlgTab2 m_tab2;
	CDlgTab3 m_tab3;
	afx_msg void OnSelchangeTabUser(NMHDR *pNMHDR, LRESULT *pResult);

	CString m_csID;

	CDlgBefore*m_pParent;

	//afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnMenuStyle1();
	afx_msg void OnMenuStyle2();
	
	afx_msg void OnOutmap();
	afx_msg void OnMenuStyle3();
	//afx_msg void OnBnClickedButtonWrite();
	
	
	//afx_msg void OnInpic();
	afx_msg void OnWrite();
	//afx_msg void OnNew();
};
