// StatusDlg.cpp: 구현 파일
//

#include "pch.h"
#include "SLDBEditor.h"
#include "StatusDlg.h"
#include "afxdialogex.h"


// StatusDlg 대화 상자

IMPLEMENT_DYNAMIC(StatusDlg, CDialogEx)

StatusDlg::StatusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STATUS_DIALOG, pParent)
{

}

StatusDlg::~StatusDlg()
{
}

void StatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_static_status);
}


BEGIN_MESSAGE_MAP(StatusDlg, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()




BOOL StatusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	DrawBitmapImage(&m_static_status, IDB_BITMAP_LOGO);
	Sleep(1000);

	MoveWindow(1000, 100,460, 480);

	Invalidate();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void StatusDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int margin = 10;
	
	CRect rect_view;
	if (IsWindow(m_static_status.m_hWnd))
	{
		rect_view.left = margin;
		rect_view.top = margin;
		rect_view.right = cx - margin;
		rect_view.bottom = cy - margin;
		m_static_status.MoveWindow(rect_view);
	}
	Invalidate();

}


int StatusDlg::DrawBitmapImage(CStatic* pic_control, int bitmap_id)
{
	// TODO: 여기에 구현 코드 추가.
	CBitmap bmp_tmp;
	bmp_tmp.LoadBitmapW(bitmap_id);
	pic_control->SetBitmap(bmp_tmp);
	bmp_tmp.Detach();

	CRect rect;
	GetClientRect(&rect);
	PostMessage(WM_SIZE, (WPARAM)SIZE_RESTORED, MAKELPARAM(rect.right - rect.left, rect.bottom - rect.top));


	return 0;
}


int StatusDlg::DrawWaiting()
{
	// TODO: 여기에 구현 코드 추가.
	DrawBitmapImage(&m_static_status, IDB_BITMAP_STATUS_WAITING);
	Invalidate();

	return 0;
}


int StatusDlg::DrawRecording()
{
	// TODO: 여기에 구현 코드 추가.
	DrawBitmapImage(&m_static_status, IDB_BITMAP_STATUS_RECORDING);
	Invalidate();

	return 0;
}


int StatusDlg::DrawCountdown()
{
	// TODO: 여기에 구현 코드 추가.
	//DrawBitmapImage(&m_static_status, IDB_BITMAP_STATUS_3);
	//Sleep(1000);
	DrawBitmapImage(&m_static_status, IDB_BITMAP_STATUS_2);
	Sleep(1000);
	DrawBitmapImage(&m_static_status, IDB_BITMAP_STATUS_1);
	Sleep(1000);
	
	Invalidate();

	return 0;
}
