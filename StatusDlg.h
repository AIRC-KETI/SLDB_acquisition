#pragma once


// StatusDlg 대화 상자

class StatusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StatusDlg)

public:
	StatusDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~StatusDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STATUS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static_status;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int DrawBitmapImage(CStatic* pic_control, int bitmap_id);
	int DrawWaiting();
	int DrawRecording();
	int DrawCountdown();
};
