
// SLDBEditorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SLDBEditor.h"
#include "SLDBEditorDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSLDBEditorDlg 대화 상자



CSLDBEditorDlg::CSLDBEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SLDBEDITOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSLDBEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAM_VIEW, m_cam_view);
	DDX_Control(pDX, IDC_COMBO_CAM_SELECT, m_combo_cam_select);
	DDX_Control(pDX, IDC_BTN_RECORD, m_btn_record);
	DDX_Control(pDX, IDC_BUTTON_PLAY, m_btn_play);
	DDX_Control(pDX, IDC_BUTTON_PAUSE, m_btn_pause);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_text_status);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_NAME, m_edit_personal_name);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_AGE, m_edit_personal_age);
	DDX_Control(pDX, IDC_COMBO_PERSONAL_SEX, m_combo_personal_sex);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_HOME, m_edit_personal_home);
	DDX_Control(pDX, IDC_COMBO_PERSONAL_HAND_DOMINANCE, m_combo_personal_hand_dominance);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_SCHOOL, m_edit_personal_school);
	DDX_Control(pDX, IDC_COMBO_PERSONAL_FAMILY, m_combo_personal_family);
	DDX_Control(pDX, IDC_STATIC_PERSONAL, m_static_personal);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_NAME, m_static_personal_name);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_AGE, m_static_personal_age);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_SEX, m_static_personal_sex);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_HOME, m_static_personal_home);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_HAND_DOMINANCE, m_static_personal_hand_dominance);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_SCHOOL, m_static_personal_school);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_FAMILY, m_static_personal_family);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_EXPERIENCE, m_edit_personal_experience);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_EXPERIENCE, m_static_personal_experience);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_btn_save);
	DDX_Control(pDX, IDC_STATIC_PERSONAL_ID, m_static_personal_ID);
	DDX_Control(pDX, IDC_EDIT_PERSONAL_ID, m_edit_personal_ID);
	DDX_Control(pDX, IDC_EDIT_ANNOTATION_ID, m_edit_annotation_ID);
	DDX_Control(pDX, IDC_EDIT_ANNOTATION_YEAR, m_edit_annotation_year);
	DDX_Control(pDX, IDC_COMBO_ANNOTATION_TYPE, m_combo_annotation_type);
	DDX_Control(pDX, IDC_EDIT_ANNOTATION_KOREAN, m_edit_annotation_korean);
	DDX_Control(pDX, IDC_LIST_ANNOTATION_GLOSS, m_list_annotation_gloss);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION, m_static_annotation);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION_ID, m_static_annotation_ID);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION_TYPE, m_static_annotation_type);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION_YEAR, m_static_annotation_year);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION_KOREAN, m_static_annotation_korean);
	DDX_Control(pDX, IDC_STATIC_ANNOTATION_GLOSS, m_static_annotation_gloss);
}

BEGIN_MESSAGE_MAP(CSLDBEditorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_CBN_SELENDOK(IDC_COMBO_CAM_SELECT, &CSLDBEditorDlg::OnSelendokComboCamSelect)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_RECORD, &CSLDBEditorDlg::OnBnClickedBtnRecord)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &CSLDBEditorDlg::OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &CSLDBEditorDlg::OnBnClickedButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CSLDBEditorDlg::OnBnClickedButtonSave)
	ON_COMMAND(ID_ACCELERATOR_PLAY, &CSLDBEditorDlg::OnAcceleratorPlay)
	ON_COMMAND(ID_ACCELERATOR_RECORD, &CSLDBEditorDlg::OnAcceleratorRecord)
	ON_COMMAND(ID_ACCELERATOR_SAVE, &CSLDBEditorDlg::OnAcceleratorSave)
	ON_COMMAND(ID_ACCELERATOR_STOP, &CSLDBEditorDlg::OnAcceleratorStop)
END_MESSAGE_MAP()


// CSLDBEditorDlg 메시지 처리기

BOOL CSLDBEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// open status dialog
	m_run = true;
	m_status_dlg = new StatusDlg;
	m_status_dlg->Create(IDD_STATUS_DIALOG, this);
	m_status_dlg->DrawWaiting();
	m_status_dlg->ShowWindow(SW_SHOW);


	// dataset path 
	char tmp_path[256];
	CString current_path;
	::GetCurrentDirectory(256, (LPWSTR)tmp_path);
	current_path.Format(_T("%s"), tmp_path);

	m_dataset_path = current_path + _T("\\Dataset\\");
	m_dataset_video_path = m_dataset_path + _T("video\\");
	m_dataset_annotation_path = m_dataset_path + _T("annotation\\");
	m_dataset_excel_personal_path = m_dataset_path + _T("Personal.xlsx");
	m_dataset_excel_annotation_path = m_dataset_path + _T("Annotation.xlsx");

	::CreateDirectory(m_dataset_path, NULL);
	::CreateDirectory(m_dataset_video_path, NULL);
	::CreateDirectory(m_dataset_annotation_path, NULL);


	// camera view controls
	m_cam_fps = 30.0;
	m_video_fps = 30.0;
	m_cam_resolution.width = 360 * 2;
	m_cam_resolution.height = 240;
	m_cam_aspect_ratio = (float) m_cam_resolution.height / (float)m_cam_resolution.width;
	MoveWindow(100,50, m_cam_resolution.width + 20, m_cam_resolution.height + 450);
	DrawBitmapButton(&m_btn_record, IDB_BITMAP_RECORD);
	DrawBitmapButton(&m_btn_play, IDB_BITMAP_PLAY);
	DrawBitmapButton(&m_btn_pause, IDB_BITMAP_PAUSE);
	DrawBitmapButton(&m_btn_save, IDB_BITMAP_SAVE);
	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);

	// status flags
	m_recording_flag = false;
	m_record_frame_left_flag = false;
	m_record_frame_center_flag = false;
	m_record_frame_right_flag = false;

	m_play_flag = false;

	// cameras opening
	sl::Timestamp ZED_Timestamp[3];
	sl::InitParameters params;
	params.depth_mode = sl::DEPTH_MODE::NONE;
	params.camera_resolution = sl::RESOLUTION::HD720;
	params.camera_fps = 30;
	std::vector<sl::DeviceProperties> devList = sl::Camera::getDeviceList();
	int nb_detected_zed = devList.size();

	m_cam_left = new sl::Camera();
	params.input.setFromCameraID(0);
	sl::ERROR_CODE err_left = m_cam_left->open(params);
	m_cam_calibration_param_left = m_cam_left->getCameraInformation().calibration_parameters;

	m_cam_center = new sl::Camera();
	params.input.setFromCameraID(1);
	sl::ERROR_CODE err_center = m_cam_center->open(params);
	m_cam_calibration_param_center = m_cam_center->getCameraInformation().calibration_parameters;

	m_cam_right = new sl::Camera();
	params.input.setFromCameraID(2);
	sl::ERROR_CODE err_right = m_cam_right->open(params);
	m_cam_calibration_param_right = m_cam_right->getCameraInformation().calibration_parameters;


	if (err_left != sl::ERROR_CODE::SUCCESS || err_center != sl::ERROR_CODE::SUCCESS || err_right != sl::ERROR_CODE::SUCCESS)
	{
		AfxMessageBox(_T("카메라를 초기화할 수 없습니다!\n카메라 연결 상태를 확인해주세요!"));
	}
	else
	{
		m_cam_current = m_cam_center;
		m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
		m_view_flag = true;
	}

	m_combo_cam_select.AddString(_T("Left camera"));
	m_combo_cam_select.AddString(_T("Center camera"));
	m_combo_cam_select.AddString(_T("Right camera"));
	m_combo_cam_select.SetCurSel(1);

	// personal information fields
	m_combo_personal_sex.AddString(_T("남"));
	m_combo_personal_sex.AddString(_T("여"));

	m_combo_personal_hand_dominance.AddString(_T("우"));
	m_combo_personal_hand_dominance.AddString(_T("좌"));

	m_combo_personal_family.AddString(_T("유"));
	m_combo_personal_family.AddString(_T("무"));


	// annotation fields
	FILE* fp;
	int prev_id;
	fopen_s(&fp, "current_file.txt", "rb");
	fscanf_s(fp, "%d", &prev_id);
	fclose(fp);
	CString tmp_string;
	tmp_string.Format(_T("%d"), prev_id);
	m_annotation_ID = prev_id;
	m_annotation_ID_prev = m_annotation_ID;
	
	m_edit_annotation_ID.SetWindowTextW(tmp_string);
	
	//m_edit_annotation_ID.SetWindowTextW(_T("40103"));

	m_combo_annotation_type.AddString(_T("단어"));
	m_combo_annotation_type.AddString(_T("문장"));
	m_combo_annotation_type.AddString(_T("지화"));

	// load excel contents
	LoadExcelIDList();
	LoadExcelContents();


	// for saving avi files
	m_thread_save_avi_left = AfxBeginThread(ThreadProcSave_left, this);
	m_thread_save_avi_center = AfxBeginThread(ThreadProcSave_center, this);
	m_thread_save_avi_right = AfxBeginThread(ThreadProcSave_right, this);
	m_save_avi_switch = true;


	m_Accelerators = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSLDBEditorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSLDBEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT CSLDBEditorDlg::GrabLoop(void)
{
	Mat mat_Image_current;
	int width;
	int height;
	sl::Mat aux;
	sl::RuntimeParameters rt_params;
	sl::ERROR_CODE res;

	while (this->m_view_flag)
	{
		if (this->m_recording_flag)
		{
			res = this->m_cam_left->grab(rt_params);
			res = this->m_cam_center->grab(rt_params);
			res = this->m_cam_right->grab(rt_params);
		}
		else
		{
			res = this->m_cam_current->grab(rt_params);
		}

		if (res == sl::ERROR_CODE::SUCCESS)
		{
			width = this->m_cam_current->getCameraInformation().camera_resolution.width;
			height = this->m_cam_current->getCameraInformation().camera_resolution.height;
			mat_Image_current = Mat(height, width *2, CV_8UC4, 1);
			
			this->m_cam_current->retrieveImage(aux, sl::VIEW::SIDE_BY_SIDE, sl::MEM::CPU);
			cv::Mat(aux.getHeight(), aux.getWidth(), CV_8UC4, aux.getPtr<sl::uchar1>(sl::MEM::CPU)).copyTo(mat_Image_current(cv::Rect(0, 0, width*2, height)));
		}
		if (!mat_Image_current.empty())
		{
			DisplayCamImage(mat_Image_current);
		}
		Sleep(1);
	}
	return 0;
}
UINT ThreadProcGrab(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->GrabLoop();
}

UINT CSLDBEditorDlg::PlayLoop(void)
{
	sl::Resolution image_size = m_video_current.getCameraInformation().camera_configuration.resolution;
	int width = image_size.width;
	int height = image_size.height;
	int width_sbs = image_size.width * 2;
	cv::Size image_size_sbs(width * 2, height);

	sl::RuntimeParameters rt_params;
	sl::ERROR_CODE res;
	cv::Mat mat_Image_current;
	mat_Image_current = Mat(height, width * 2, CV_8UC4, 1);


	m_video_current.setSVOPosition(0);
	int svo_position = 0;
	sl::Mat aux(width * 2, height, sl::MAT_TYPE::U8_C4);
	mat_Image_current = slMat2cvMat(aux);


	while (1)
	{
		if (this->m_play_flag)
		{
			res = m_video_current.grab(rt_params);

			if (m_video_current.getSVOPosition() >= m_video_current.getSVONumberOfFrames())
			{
				DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
				this->m_play_flag = false;
				this->m_view_flag = true;
			}

			m_video_current.retrieveImage(aux, sl::VIEW::SIDE_BY_SIDE, sl::MEM::CPU);
			cv::Mat bar = slMat2cvMat(aux);
			// Convert SVO image from RGBA to RGB
			cv::cvtColor(bar, mat_Image_current, cv::COLOR_RGBA2RGB);


			if (!mat_Image_current.empty())
			{
				DisplayCamImage(mat_Image_current);
			}
			Sleep((DWORD)(1000.0 / m_video_fps));
		}
		else
		{
			m_video_current.close();
			return 0;
		}
	}
	m_video_current.close();
	return 0;
}
UINT ThreadProcPlay(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->PlayLoop();
}

UINT CSLDBEditorDlg::RecordLoop(void)
{
	// TODO: 여기에 구현 코드 추가.
	int width;
	int height;
	sl::RuntimeParameters rt_params_left;
	sl::RuntimeParameters rt_params_center;
	sl::RuntimeParameters rt_params_right;

	Mat mat_Image_left;
	Mat mat_Image_center;
	Mat mat_Image_right;

	while (1)
	{
		if (this->m_recording_flag)
		{
			sl::ERROR_CODE res_left = this->m_cam_left->grab(rt_params_left);
			sl::ERROR_CODE res_center = this->m_cam_center->grab(rt_params_center);
			sl::ERROR_CODE res_right = this->m_cam_right->grab(rt_params_right);

			//m_record_frame_left_flag = true;
			//m_record_frame_center_flag = true;
			//m_record_frame_right_flag = true;

			Sleep(1);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
UINT ThreadProcRecord(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->RecordLoop();
}

UINT CSLDBEditorDlg::RecordLoop_left()
{
	// TODO: 여기에 구현 코드 추가.
	Mat mat_Image_left;
	sl::RuntimeParameters rt_params_left;

	while (1)
	{
		if (this->m_recording_flag)
		{
			if (this->m_cam_left->isOpened() && m_record_frame_left_flag)
			{
				sl::ERROR_CODE res_left = this->m_cam_left->grab(rt_params_left);
				m_record_frame_left_flag = false;
			}
			Sleep(1);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
UINT ThreadProcRecord_left(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->RecordLoop_left();
}

UINT CSLDBEditorDlg::RecordLoop_center()
{
	// TODO: 여기에 구현 코드 추가.
	sl::RuntimeParameters rt_params_center;

	while (1)
	{
		if (this->m_recording_flag)
		{
			if (this->m_cam_center->isOpened() && m_record_frame_center_flag)
			{
				sl::ERROR_CODE res_center = this->m_cam_left->grab(rt_params_center);
				m_record_frame_center_flag = false;
			}
			Sleep(1);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
UINT ThreadProcRecord_center(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->RecordLoop_center();
}

UINT CSLDBEditorDlg::RecordLoop_right()
{
	// TODO: 여기에 구현 코드 추가.
	sl::RuntimeParameters rt_params_right;

	while (1)
	{
		if (this->m_recording_flag)
		{
			if (this->m_cam_right->isOpened() && m_record_frame_right_flag)
			{
				sl::ERROR_CODE res_right = this->m_cam_right->grab(rt_params_right);
				m_record_frame_right_flag = false;
			}
			Sleep(1);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
UINT ThreadProcRecord_right(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->RecordLoop_right();
}


void CSLDBEditorDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int button_size = 54;
	int margin = 10;
	int edit_size = 20;

	// recording and play objects
	CRect rect_view;
	CRect rect_btn_record;
	CRect rect_btn_play;
	CRect rect_btn_pause;
	CRect rect_btn_save;
	CRect rect_text_status;

	// personal information
	CRect rect_static_personal;
	CRect rect_static_personal_ID;
	CRect rect_static_personal_name;
	CRect rect_static_personal_age;
	CRect rect_static_personal_sex;
	CRect rect_static_personal_home;
	CRect rect_static_personal_hand_dominance;
	CRect rect_static_personal_school;
	CRect rect_static_personal_family;
	CRect rect_static_personal_experience;

	CRect rect_edit_personal_ID;
	CRect rect_edit_personal_name;
	CRect rect_edit_personal_age;
	CRect rect_combo_personal_sex;
	CRect rect_edit_personal_home;
	CRect rect_combo_personal_hand_dominance;
	CRect rect_edit_personal_school;
	CRect rect_combo_personal_family;
	CRect rect_edit_personal_experience;

	// annotation fields
	CRect rect_static_annotation;
	CRect rect_static_annotation_ID;
	CRect rect_static_annotation_type;
	CRect rect_static_annotation_year;
	CRect rect_static_annotation_korean;
	CRect rect_static_annotation_gloss;

	CRect rect_edit_annotation_ID;
	CRect rect_combo_annotation_type;
	CRect rect_edit_annotation_year;
	CRect rect_edit_annotation_korean;
	CRect rect_edit_annotation_gloss_insert;
	CRect rect_list_annotation_gloss;
	CRect rect_btn_annotation_gloss_insert;
	CRect rect_btn_annotation_gloss_delete;



	// recording and play objects
	if (IsWindow(m_cam_view.m_hWnd))
	{
		rect_view.left = margin;
		rect_view.top = 40;
		rect_view.right = cx - margin;
		rect_view.bottom = (LONG)((float)(rect_view.right - rect_view.left) * m_cam_aspect_ratio) + rect_view.top;
		m_cam_view.MoveWindow(rect_view);
	}	
	if (m_btn_record.GetSafeHwnd())
	{
		rect_btn_record.left = MAX(rect_view.right - (button_size*4 + margin*3), margin);
		rect_btn_record.top = rect_view.bottom + margin;
		rect_btn_record.right = rect_btn_record.left + button_size;
		rect_btn_record.bottom = rect_btn_record.top + button_size;
		m_btn_record.MoveWindow(rect_btn_record);
	}
	if (m_btn_play.GetSafeHwnd())
	{
		rect_btn_play.left = MAX(rect_btn_record.right + margin, button_size + margin * 2);
		rect_btn_play.top = rect_btn_record.top;
		rect_btn_play.right = rect_btn_play.left + button_size;
		rect_btn_play.bottom = rect_btn_play.top + button_size;
		m_btn_play.MoveWindow(rect_btn_play);
	}
	if (m_btn_pause.GetSafeHwnd())
	{
		rect_btn_pause.left = MAX(rect_btn_play.right + margin, margin * 3 + button_size * 2);
		rect_btn_pause.top = rect_btn_play.top;
		rect_btn_pause.right = rect_btn_pause.left + button_size;
		rect_btn_pause.bottom = rect_btn_pause.top + button_size;
		m_btn_pause.MoveWindow(rect_btn_pause);
	}
	if (m_btn_save.GetSafeHwnd())
	{
		rect_btn_save.left = MAX(rect_btn_pause.right + margin, margin * 4 + button_size * 3);
		rect_btn_save.top = rect_btn_pause.top;
		rect_btn_save.right = rect_btn_save.left + button_size;
		rect_btn_save.bottom = rect_btn_save.top + button_size;
		m_btn_save.MoveWindow(rect_btn_save);
	}
	if (m_text_status.GetSafeHwnd())
	{
		rect_text_status.left = MAX((rect_view.right - rect_view.left) / 2 - 100, 170);
		rect_text_status.top = 12;
		rect_text_status.right = rect_text_status.left + 150;
		rect_text_status.bottom = rect_text_status.top + 22;
		m_text_status.MoveWindow(rect_text_status);
		CString temp_string;
		m_text_status.GetWindowTextW(temp_string);
		DrawStyledText(m_text_status.GetDlgCtrlID(), temp_string, 1000, 20);
	}
	
	// personal information
	if (m_static_personal.GetSafeHwnd())
	{
		rect_static_personal.left = margin;
		rect_static_personal.top = rect_btn_record.bottom + margin;
		rect_static_personal.right = rect_static_personal.left + 240;
		rect_static_personal.bottom = rect_static_personal.top + 290;
		m_static_personal.MoveWindow(rect_static_personal);
	}
	if (m_static_personal_ID.GetSafeHwnd() && m_edit_personal_ID.GetSafeHwnd())
	{
		rect_static_personal_ID.left = rect_static_personal.left + margin;
		rect_static_personal_ID.top = rect_static_personal.top + 2 * margin;
		rect_static_personal_ID.right = rect_static_personal_ID.left + 70;
		rect_static_personal_ID.bottom = rect_static_personal_ID.top + edit_size;
		m_static_personal_ID.MoveWindow(rect_static_personal_ID);

		rect_edit_personal_ID.left = rect_static_personal.left + 80;
		rect_edit_personal_ID.top = rect_static_personal.top + 2 * margin;
		rect_edit_personal_ID.right = rect_static_personal.right - margin;
		rect_edit_personal_ID.bottom = rect_edit_personal_ID.top + edit_size;
		m_edit_personal_ID.MoveWindow(rect_edit_personal_ID);
	}
	if (m_static_personal_name.GetSafeHwnd() && m_edit_personal_name.GetSafeHwnd())
	{
		rect_static_personal_name.left = rect_static_personal.left + margin;
		rect_static_personal_name.top = rect_static_personal_ID.bottom + margin;
		rect_static_personal_name.right = rect_static_personal_name.left + 70;
		rect_static_personal_name.bottom = rect_static_personal_name.top + edit_size;
		m_static_personal_name.MoveWindow(rect_static_personal_name);

		rect_edit_personal_name.left = rect_static_personal.left + 80;
		rect_edit_personal_name.top = rect_static_personal_ID.bottom + margin;
		rect_edit_personal_name.right = rect_static_personal.right - margin;
		rect_edit_personal_name.bottom = rect_edit_personal_name.top + edit_size;
		m_edit_personal_name.MoveWindow(rect_edit_personal_name);
	}
	if (m_static_personal_age.GetSafeHwnd() && m_edit_personal_age.GetSafeHwnd())
	{
		rect_static_personal_age.left = rect_static_personal.left + margin;
		rect_static_personal_age.top = rect_static_personal_name.bottom + margin;
		rect_static_personal_age.right = rect_static_personal_age.left + 70;
		rect_static_personal_age.bottom = rect_static_personal_age.top + edit_size;
		m_static_personal_age.MoveWindow(rect_static_personal_age);

		rect_edit_personal_age.left = rect_static_personal.left + 80;
		rect_edit_personal_age.top = rect_static_personal_name.bottom + margin;
		rect_edit_personal_age.right = rect_static_personal.right - margin;
		rect_edit_personal_age.bottom = rect_edit_personal_age.top + edit_size;
		m_edit_personal_age.MoveWindow(rect_edit_personal_age);
	}
	if (m_static_personal_sex.GetSafeHwnd() && m_combo_personal_sex.GetSafeHwnd())
	{
		rect_static_personal_sex.left = rect_static_personal.left + margin;
		rect_static_personal_sex.top = rect_edit_personal_age.bottom + margin;
		rect_static_personal_sex.right = rect_static_personal_sex.left + 70;
		rect_static_personal_sex.bottom = rect_static_personal_sex.top + edit_size;
		m_static_personal_sex.MoveWindow(rect_static_personal_sex);

		rect_combo_personal_sex.left = rect_static_personal.left + 80;
		rect_combo_personal_sex.top = rect_edit_personal_age.bottom + margin;
		rect_combo_personal_sex.right = rect_static_personal.right - margin;
		rect_combo_personal_sex.bottom = rect_combo_personal_sex.top + edit_size;
		m_combo_personal_sex.MoveWindow(rect_combo_personal_sex);
	}
	if (m_static_personal_home.GetSafeHwnd() && m_edit_personal_home.GetSafeHwnd())
	{
		rect_static_personal_home.left = rect_static_personal.left + margin;
		rect_static_personal_home.top = rect_combo_personal_sex.bottom + margin;
		rect_static_personal_home.right = rect_static_personal_home.left + 70;
		rect_static_personal_home.bottom = rect_static_personal_home.top + edit_size;
		m_static_personal_home.MoveWindow(rect_static_personal_home);

		rect_edit_personal_home.left = rect_static_personal.left + 80;
		rect_edit_personal_home.top = rect_combo_personal_sex.bottom + margin;
		rect_edit_personal_home.right = rect_static_personal.right - margin;
		rect_edit_personal_home.bottom = rect_edit_personal_home.top + edit_size;
		m_edit_personal_home.MoveWindow(rect_edit_personal_home);
	}
	if (m_static_personal_hand_dominance.GetSafeHwnd() && m_combo_personal_hand_dominance.GetSafeHwnd())
	{
		rect_static_personal_hand_dominance.left = rect_static_personal.left + margin;
		rect_static_personal_hand_dominance.top = rect_edit_personal_home.bottom + margin;
		rect_static_personal_hand_dominance.right = rect_static_personal_hand_dominance.left + 70;
		rect_static_personal_hand_dominance.bottom = rect_static_personal_hand_dominance.top + edit_size;
		m_static_personal_hand_dominance.MoveWindow(rect_static_personal_hand_dominance);

		rect_combo_personal_hand_dominance.left = rect_static_personal.left + 80;
		rect_combo_personal_hand_dominance.top = rect_edit_personal_home.bottom + margin;
		rect_combo_personal_hand_dominance.right = rect_static_personal.right - margin;
		rect_combo_personal_hand_dominance.bottom = rect_combo_personal_hand_dominance.top + edit_size;
		m_combo_personal_hand_dominance.MoveWindow(rect_combo_personal_hand_dominance);
	}
	if (m_static_personal_school.GetSafeHwnd() && m_edit_personal_school.GetSafeHwnd())
	{
		rect_static_personal_school.left = rect_static_personal.left + margin;
		rect_static_personal_school.top = rect_static_personal_hand_dominance.bottom + margin;
		rect_static_personal_school.right = rect_static_personal_school.left + 70;
		rect_static_personal_school.bottom = rect_static_personal_school.top + edit_size;
		m_static_personal_school.MoveWindow(rect_static_personal_school);

		rect_edit_personal_school.left = rect_static_personal.left + 80;
		rect_edit_personal_school.top = rect_combo_personal_hand_dominance.bottom + margin;
		rect_edit_personal_school.right = rect_static_personal.right - margin;
		rect_edit_personal_school.bottom = rect_edit_personal_school.top + edit_size;
		m_edit_personal_school.MoveWindow(rect_edit_personal_school);
	}
	if (m_static_personal_family.GetSafeHwnd() && m_combo_personal_family.GetSafeHwnd())
	{
		rect_static_personal_family.left = rect_static_personal.left + margin;
		rect_static_personal_family.top = rect_static_personal_school.bottom + margin;
		rect_static_personal_family.right = rect_static_personal_family.left + 70;
		rect_static_personal_family.bottom = rect_static_personal_family.top + edit_size;
		m_static_personal_family.MoveWindow(rect_static_personal_family);

		rect_combo_personal_family.left = rect_static_personal.left + 80;
		rect_combo_personal_family.top = rect_edit_personal_school.bottom + margin;
		rect_combo_personal_family.right = rect_static_personal.right - margin;
		rect_combo_personal_family.bottom = rect_combo_personal_family.top + edit_size;
		m_combo_personal_family.MoveWindow(rect_combo_personal_family);
	}
	if (m_static_personal_experience.GetSafeHwnd() && m_edit_personal_experience.GetSafeHwnd())
	{
		rect_static_personal_experience.left = rect_static_personal.left + margin;
		rect_static_personal_experience.top = rect_static_personal_family.bottom + margin;
		rect_static_personal_experience.right = rect_static_personal_experience.left + 70;
		rect_static_personal_experience.bottom = rect_static_personal_experience.top + edit_size;
		m_static_personal_experience.MoveWindow(rect_static_personal_experience);

		rect_edit_personal_experience.left = rect_static_personal.left + 80;
		rect_edit_personal_experience.top = rect_combo_personal_family.bottom + margin;
		rect_edit_personal_experience.right = rect_static_personal.right - margin;
		rect_edit_personal_experience.bottom = rect_edit_personal_experience.top + edit_size;
		m_edit_personal_experience.MoveWindow(rect_edit_personal_experience);
	}


	// annotation fields
	if (m_static_annotation.GetSafeHwnd())
	{
		rect_static_annotation.left = rect_static_personal.right + margin;
		rect_static_annotation.top = rect_btn_record.bottom + margin;
		rect_static_annotation.right = rect_static_annotation.left + 450;
		rect_static_annotation.bottom = rect_static_annotation.top + 290;
		m_static_annotation.MoveWindow(rect_static_annotation);
	}
	if (m_static_annotation_ID.GetSafeHwnd() && m_edit_annotation_ID.GetSafeHwnd())
	{
		rect_static_annotation_ID.left = rect_static_annotation.left + margin;
		rect_static_annotation_ID.top = rect_static_annotation.top + 2 * margin;
		rect_static_annotation_ID.right = rect_static_annotation_ID.left + 60;
		rect_static_annotation_ID.bottom = rect_static_annotation_ID.top + edit_size;
		m_static_annotation_ID.MoveWindow(rect_static_annotation_ID);

		rect_edit_annotation_ID.left = rect_static_annotation_ID.right + margin;
		rect_edit_annotation_ID.top = rect_static_annotation.top + 2 * margin;
		rect_edit_annotation_ID.right = rect_static_annotation_ID.right + 180;
		rect_edit_annotation_ID.bottom = rect_edit_annotation_ID.top + edit_size;
		m_edit_annotation_ID.MoveWindow(rect_edit_annotation_ID);
	}
	if (m_static_annotation_year.GetSafeHwnd() && m_edit_annotation_year.GetSafeHwnd())
	{
		rect_static_annotation_year.left = rect_static_annotation.left + margin;
		rect_static_annotation_year.top = rect_static_annotation_ID.bottom + margin;
		rect_static_annotation_year.right = rect_static_annotation_year.left + 60;
		rect_static_annotation_year.bottom = rect_static_annotation_year.top + edit_size;
		m_static_annotation_year.MoveWindow(rect_static_annotation_year);

		rect_edit_annotation_year.left = rect_static_annotation_year.right + margin;
		rect_edit_annotation_year.top = rect_static_annotation_ID.bottom + margin;
		rect_edit_annotation_year.right = rect_edit_annotation_year.left + 170;
		rect_edit_annotation_year.bottom = rect_edit_annotation_year.top + edit_size;
		m_edit_annotation_year.MoveWindow(rect_edit_annotation_year);
	}
	if (m_static_annotation_type.GetSafeHwnd() && m_combo_annotation_type.GetSafeHwnd())
	{
		rect_static_annotation_type.left = rect_edit_annotation_ID.right + margin;
		rect_static_annotation_type.top = rect_static_annotation_ID.bottom + margin;
		rect_static_annotation_type.right = rect_static_annotation_type.left + 80;
		rect_static_annotation_type.bottom = rect_static_annotation_type.top + edit_size;
		m_static_annotation_type.MoveWindow(rect_static_annotation_type);

		rect_combo_annotation_type.left = rect_static_annotation_type.right + margin;
		rect_combo_annotation_type.top = rect_static_annotation_ID.bottom + margin;
		rect_combo_annotation_type.right = rect_static_annotation_type.right + 100;
		rect_combo_annotation_type.bottom = rect_combo_annotation_type.top + edit_size;
		m_combo_annotation_type.MoveWindow(rect_combo_annotation_type);
	}
	if (m_static_annotation_korean.GetSafeHwnd() && m_edit_annotation_korean.GetSafeHwnd())
	{
		rect_static_annotation_korean.left = rect_static_annotation.left + margin;
		rect_static_annotation_korean.top = rect_static_annotation_year.bottom + margin;
		rect_static_annotation_korean.right = rect_static_annotation_korean.left + 60;
		rect_static_annotation_korean.bottom = rect_static_annotation_korean.top + edit_size;
		m_static_annotation_korean.MoveWindow(rect_static_annotation_korean);

		rect_edit_annotation_korean.left = rect_static_annotation_korean.right + margin;
		rect_edit_annotation_korean.top = rect_static_annotation_year.bottom + margin;
		rect_edit_annotation_korean.right = rect_static_annotation.right - margin;
		rect_edit_annotation_korean.bottom = rect_edit_annotation_korean.top + edit_size;
		m_edit_annotation_korean.MoveWindow(rect_edit_annotation_korean);
	}
	if (m_static_annotation_gloss.GetSafeHwnd() && m_list_annotation_gloss.GetSafeHwnd())
	{
		rect_static_annotation_gloss.left = rect_static_annotation.left + margin;
		rect_static_annotation_gloss.top = rect_edit_annotation_korean.bottom + margin;
		rect_static_annotation_gloss.right = rect_static_annotation_gloss.left + 60;
		rect_static_annotation_gloss.bottom = rect_static_annotation_gloss.top + edit_size;
		m_static_annotation_gloss.MoveWindow(rect_static_annotation_gloss);

		rect_list_annotation_gloss.left = rect_static_annotation_gloss.right + margin;
		rect_list_annotation_gloss.top = rect_static_annotation_korean.bottom + margin;
		rect_list_annotation_gloss.right = rect_static_annotation.right - margin;
		rect_list_annotation_gloss.bottom = rect_list_annotation_gloss.top + edit_size * 8;
		m_list_annotation_gloss.MoveWindow(rect_list_annotation_gloss);
	}

	Invalidate();

}


void CSLDBEditorDlg::OnSelendokComboCamSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_combo_cam_select.GetCurSel() == 0) m_cam_current = m_cam_left;
	else if (m_combo_cam_select.GetCurSel() == 1) m_cam_current = m_cam_center;
	else if (m_combo_cam_select.GetCurSel() == 2) m_cam_current = m_cam_right;
	if (m_play_flag)
	{
		m_play_flag = false;
		Sleep(1000.0);
		OnBnClickedButtonPlay();
	}

}


void CSLDBEditorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_run = false;
	if (m_thread_grab_image != NULL)
	{
		m_view_flag = false;
		m_thread_grab_image = NULL;
		m_cam_left->close();
		m_cam_center->close();
		m_cam_right->close();
		delete m_cam_left;
		delete m_cam_center;
		delete m_cam_right;
	}
	if (m_thread_record_image != NULL)
	{
		m_recording_flag = false;
		m_thread_record_image = NULL;

		if (m_thread_record_image_left != NULL ||
			m_thread_record_image_center != NULL ||
			m_thread_record_image_right != NULL)
		{
			m_thread_record_image_left = NULL;
			m_thread_record_image_center = NULL;
			m_thread_record_image_right = NULL;
		}
	}
	if (m_thread_save_avi_left != NULL ||
		m_thread_save_avi_center != NULL ||
		m_thread_save_avi_right != NULL)
	{
		m_save_avi_left_flag = false;
		m_save_avi_center_flag = false;
		m_save_avi_right_flag = false;

		m_thread_save_avi_left = NULL;
		m_thread_save_avi_center = NULL;
		m_thread_save_avi_right = NULL;
	}
}


int CSLDBEditorDlg::DisplayCamImage(Mat mat_image)
{
	// TODO: 여기에 구현 코드 추가.
	CDC* pDC;
	CRect rect;

	pDC = this->m_cam_view.GetDC();
	this->m_cam_view.GetClientRect(&rect);

	Size winSize(rect.right, rect.bottom);

	CImage cimage_mfc;
	cimage_mfc.Create(winSize.width, winSize.height, 24);
	CDC* pDC_img = CDC::FromHandle(cimage_mfc.GetDC());


	BITMAPINFO* bitInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
	int bpp = (int)(8 * mat_image.elemSize());
	assert((bpp == 8 || bpp == 24 || bpp == 32));
	int padding = 0;
	//32 bit image is always DWORD aligned because each pixel requires 4 bytes
	if (bpp < 32)
		padding = 4 - (mat_image.cols % 4);

	if (padding == 4)
		padding = 0;

	int border = 0;
	//32 bit image is always DWORD aligned because each pixel requires 4 bytes
	if (bpp < 32)
	{
		border = 4 - (mat_image.cols % 4);
	}


	Mat mat_temp;
	if (border > 0 || mat_image.isContinuous() == false)
	{
		// Adding needed columns on the right (max 3 px)
		cv::copyMakeBorder(mat_image, mat_temp, 0, 0, 0, border, cv::BORDER_CONSTANT, 0);
	}
	else
	{
		mat_temp = mat_image;
	}

	bitInfo->bmiHeader.biBitCount = bpp;
	bitInfo->bmiHeader.biWidth = mat_temp.cols;
	bitInfo->bmiHeader.biHeight = -mat_temp.rows;
	bitInfo->bmiHeader.biPlanes = 1;
	bitInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitInfo->bmiHeader.biCompression = BI_RGB;
	bitInfo->bmiHeader.biClrImportant = 0;
	bitInfo->bmiHeader.biClrUsed = 0;
	bitInfo->bmiHeader.biSizeImage = 0;
	bitInfo->bmiHeader.biXPelsPerMeter = 0;
	bitInfo->bmiHeader.biYPelsPerMeter = 0;
	if (bpp == 8)
	{
		RGBQUAD* palette = bitInfo->bmiColors;
		for (int i = 0; i < 256; i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
	SetStretchBltMode(*pDC_img, COLORONCOLOR);
	if (mat_temp.cols == winSize.width && mat_temp.rows == winSize.height)
	{
		// source and destination have same size
		// transfer memory block
		// NOTE: the padding border will be shown here. Anyway it will be max 3px width

		SetDIBitsToDevice(*pDC_img,
			//destination rectangle
			0, 0, winSize.width, winSize.height,
			0, 0, 0, mat_temp.rows,
			mat_temp.data, bitInfo, DIB_RGB_COLORS);
	}
	else
	{
		// rectangle defined on source bitmap
		// using imgWidth instead of mat_temp.cols will ignore the padding border
		int imgx = 0, imgy = 0;
		int imgWidth = mat_temp.cols - border;
		int imgHeight = mat_temp.rows;
		float fAspectRgn = (float)winSize.height / (float)winSize.width;
		float fAspectImg = m_cam_aspect_ratio;

		// destination rectangle
		int destx = 0, desty = 0;
		int destw;
		int desth;

		if (fAspectRgn < fAspectImg)
		{
			destw = (int)(winSize.height / fAspectImg);
			desth = winSize.height;
		}
		else
		{
			destw = winSize.width;
			desth = (int)(winSize.width * fAspectImg);
		}
		StretchDIBits(*pDC_img,
			destx, desty, destw, desth,
			imgx, imgy, imgWidth, imgHeight,
			mat_temp.data, bitInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	HDC dc = ::GetDC(m_cam_view.m_hWnd);
	cimage_mfc.BitBlt(dc, 0, 0);


	::ReleaseDC(m_cam_view.m_hWnd, dc);
	cimage_mfc.ReleaseDC();
	cimage_mfc.Destroy();

	return 0;
}


void CSLDBEditorDlg::OnBnClickedBtnRecord()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cam_left->isOpened() && m_cam_center->isOpened() && m_cam_right->isOpened())
	{
		if (!m_recording_flag)
		{
			m_play_flag = false;
			m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
			m_view_flag = true;

			Size image_size = Size((int)m_cam_center->getCameraInformation().camera_resolution.width, (int)m_cam_center->getCameraInformation().camera_resolution.height);

			CString tmp_string_left;
			CString tmp_string_center;
			CString tmp_string_right;
			CString tmp_string;
			m_edit_annotation_ID.GetWindowTextW(tmp_string);
			m_annotation_ID = _ttoi(tmp_string);

			sl::RecordingParameters record_parameter_left;
			record_parameter_left.compression_mode = sl::SVO_COMPRESSION_MODE::LOSSLESS;
			record_parameter_left.video_filename = "output_left.svo";
			m_cam_left->enableRecording(record_parameter_left);

			sl::RecordingParameters record_parameter_center;
			record_parameter_center.compression_mode = sl::SVO_COMPRESSION_MODE::LOSSLESS;
			record_parameter_center.video_filename = "output_center.svo";
			m_cam_center->enableRecording(record_parameter_center);

			sl::RecordingParameters record_parameter_right;
			record_parameter_right.compression_mode = sl::SVO_COMPRESSION_MODE::LOSSLESS;
			record_parameter_right.video_filename = "output_right.svo";
			m_cam_right->enableRecording(record_parameter_right);



			DrawBitmapButton(&m_btn_record, IDB_BITMAP_STOP);
			DrawStyledText(m_text_status.GetDlgCtrlID(), _T("녹화중..."), 1000, 20);


			Invalidate();
			m_recording_flag = true;
			if (m_status_dlg != NULL && m_status_dlg->IsWindowVisible() == TRUE)
			{
				m_status_dlg->DrawCountdown();
				m_status_dlg->DrawRecording();
			}
			else
			{
				m_status_dlg = new StatusDlg;
				m_status_dlg->Create(IDD_STATUS_DIALOG, this);
				m_status_dlg->ShowWindow(SW_SHOW);
				m_status_dlg->DrawCountdown();
				m_status_dlg->DrawRecording();
			}
		}
		else
		{
			DrawStyledText(m_text_status.GetDlgCtrlID(), _T("저장중..."), 1000, 20);
			if (m_status_dlg != NULL && m_status_dlg->IsWindowVisible() == TRUE)
			{
				m_status_dlg->DrawWaiting();
			}
			else
			{
				m_status_dlg = new StatusDlg;
				m_status_dlg->Create(IDD_STATUS_DIALOG, this);
				m_status_dlg->ShowWindow(SW_SHOW);
				m_status_dlg->DrawWaiting();
			}

			m_cam_left->disableRecording();
			m_cam_center->disableRecording();
			m_cam_right->disableRecording();

			DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);

			DrawBitmapButton(&m_btn_record, IDB_BITMAP_RECORD);

			Invalidate();
			m_recording_flag = false;

			OnBnClickedButtonSave();
		}
	}
}


int CSLDBEditorDlg::DrawBitmapButton(CButton *button, int bitmap_id)
{
	// TODO: 여기에 구현 코드 추가.
	CBitmap bmp_tmp;
	bmp_tmp.LoadBitmapW(bitmap_id);
	button->SetBitmap(bmp_tmp);
	bmp_tmp.Detach();

	return 0;
}


void CSLDBEditorDlg::OnBnClickedButtonPlay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다. 

	if (!m_recording_flag && !m_play_flag)
	{
		DrawStyledText(m_text_status.GetDlgCtrlID(), _T("재생중..."), 1000, 20);
		if (m_status_dlg != NULL && m_status_dlg->IsWindowVisible() == TRUE)
		{
			m_status_dlg->DrawWaiting();
		}
		else
		{
			m_status_dlg = new StatusDlg;
			m_status_dlg->Create(IDD_STATUS_DIALOG, this);
			m_status_dlg->ShowWindow(SW_SHOW);
			m_status_dlg->DrawWaiting();
		}

		m_view_flag = false;

		CString tmp_string;
		
		m_edit_annotation_ID.GetWindowTextW(tmp_string);
		m_annotation_ID = _ttoi(tmp_string);

		//if (m_combo_cam_select.GetCurSel() == 0) 
		//	tmp_string.Format(_T("%sKETI_SL_%010d_left.mp4"), m_dataset_video_path, annotation_ID);
		//else if (m_combo_cam_select.GetCurSel() == 1) 
		//	tmp_string.Format(_T("%sKETI_SL_%010d_center.mp4"), m_dataset_video_path, annotation_ID);
		//else if (m_combo_cam_select.GetCurSel() == 2) 
		//	tmp_string.Format(_T("%sKETI_SL_%010d_right.mp4"), m_dataset_video_path, annotation_ID);
		//if (m_combo_cam_select.GetCurSel() == 0)
		//	m_video_current.open("output_left.mp4");
		//else if (m_combo_cam_select.GetCurSel() == 1)
		//	m_video_current.open("output_center.mp4");
		//else if (m_combo_cam_select.GetCurSel() == 2)
		//	m_video_current.open("output_right.mp4");

		sl::InitParameters init_parameters;

		if (m_combo_cam_select.GetCurSel() == 0)
			init_parameters.input.setFromSVOFile("output_left.svo");
		else if (m_combo_cam_select.GetCurSel() == 1)
			init_parameters.input.setFromSVOFile("output_center.svo");
		else if (m_combo_cam_select.GetCurSel() == 2)
			init_parameters.input.setFromSVOFile("output_right.svo");

		if (m_video_current.open(init_parameters) != sl::ERROR_CODE::SUCCESS)
		{
			AfxMessageBox(_T("비디오 파일이 없습니다!"));
			DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
			m_play_flag = false;
			m_view_flag = false;
			m_thread_grab_image = NULL;
			m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
			m_view_flag = true;
		}
		else
		{
			m_play_flag = true;
			m_thread_play_video = AfxBeginThread(ThreadProcPlay, this);
		}


		//m_video_current.open((const char*)CT2CA(tmp_string));
		//m_video_fps = m_video_current.get(CAP_PROP_FPS);
		//m_video_fps = 60.0;
		
		//if (m_video_current.isOpened())
		//{
		//	m_play_flag = true;
		//	m_thread_play_video = AfxBeginThread(ThreadProcPlay, this);
		//}
		//else
		//{
		//	AfxMessageBox(_T("비디오 파일이 없습니다!"));
		//	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
		//	m_play_flag = false;
		//	m_view_flag = false;
		//	m_thread_grab_image = NULL;
		//	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
		//	m_view_flag = true;
		//}		
	}


}


void CSLDBEditorDlg::OnBnClickedButtonPause()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_play_flag = false;
	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
	if (m_status_dlg != NULL && m_status_dlg->IsWindowVisible() == TRUE)
	{
		m_status_dlg->DrawWaiting();
	}
	else
	{
		m_status_dlg = new StatusDlg;
		m_status_dlg->Create(IDD_STATUS_DIALOG, this);
		m_status_dlg->ShowWindow(SW_SHOW);
		m_status_dlg->DrawWaiting();
	}
	Invalidate();
	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
	m_view_flag = true;
}


int CSLDBEditorDlg::DrawStyledText(int text_ID, CString contents, int weight, int height)
{
	// TODO: 여기에 구현 코드 추가.
	CFont font;
	LOGFONT log_font;
	GetDlgItem(text_ID)->GetFont()->GetLogFont(&log_font);
	log_font.lfWeight = weight;
	log_font.lfHeight = height;
	log_font.lfWidth = 0;
	log_font.lfItalic = false;
	log_font.lfUnderline = false;
	log_font.lfStrikeOut = false;
	log_font.lfEscapement = 0;
	log_font.lfOrientation = 0;
	font.CreateFontIndirectW(&log_font);

	GetDlgItem(text_ID)->SetWindowTextW(contents);
	GetDlgItem(text_ID)->SetFont(&font);

	return 0;
}


UINT CSLDBEditorDlg::SaveAVI_left()
{
	// TODO: 여기에 구현 코드 추가.
	CString tmp_string;
	while (this->m_run)
	{
		if (this->m_save_avi_left_flag)
		{
			tmp_string.Format(_T("%sKETI_SL_%010d_left.mp4"), m_dataset_video_path, m_annotation_ID_prev);
			ConvertSVOtoAVI(CString(_T("output_left.svo")), tmp_string);
			m_save_avi_left_flag = false;
		}
		Sleep(1);
	}
	return 0;
}
UINT ThreadProcSave_left(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->SaveAVI_left();
}

UINT CSLDBEditorDlg::SaveAVI_center()
{
	// TODO: 여기에 구현 코드 추가.
	CString tmp_string;
	while (this->m_run)
	{
		if (this->m_save_avi_center_flag)
		{
			tmp_string.Format(_T("%sKETI_SL_%010d_center.mp4"), m_dataset_video_path, m_annotation_ID_prev);
			ConvertSVOtoAVI(CString(_T("output_center.svo")), tmp_string);
			m_save_avi_center_flag = false;
		}
		Sleep(1);
	}
	return 0;
}
UINT ThreadProcSave_center(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->SaveAVI_center();
}

UINT CSLDBEditorDlg::SaveAVI_right()
{
	// TODO: 여기에 구현 코드 추가.
	CString tmp_string;
	while (this->m_run)
	{
		if (this->m_save_avi_right_flag)
		{
			tmp_string.Format(_T("%sKETI_SL_%010d_right.mp4"), m_dataset_video_path, m_annotation_ID_prev);
			ConvertSVOtoAVI(CString(_T("output_right.svo")), tmp_string);
			m_save_avi_right_flag = false;
		}
		Sleep(1);
	}
	return 0;
}
UINT ThreadProcSave_right(LPVOID IParam)
{
	return ((CSLDBEditorDlg*)IParam)->SaveAVI_right();
}


void CSLDBEditorDlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_view_flag = false;
	m_play_flag = false;
	m_recording_flag = false;

	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("저장중..."), 1000, 20);
	if (m_status_dlg != NULL && m_status_dlg->IsWindowVisible() == TRUE)
	{
		m_status_dlg->DrawWaiting();
	}
	else
	{
		m_status_dlg = new StatusDlg;
		m_status_dlg->Create(IDD_STATUS_DIALOG, this);
		m_status_dlg->ShowWindow(SW_SHOW);
		m_status_dlg->DrawWaiting();
	}


	// video save
	CString tmp_string_left;
	CString tmp_string_center;
	CString tmp_string_right;
	CString tmp_string;

	m_edit_annotation_ID.GetWindowTextW(tmp_string);
	m_annotation_ID = _ttoi(tmp_string);
	m_annotation_ID_prev = m_annotation_ID;

	m_save_avi_left_flag = true;
	m_save_avi_center_flag = true;
	m_save_avi_right_flag = true;

	tmp_string_left.Format(_T("%sKETI_SL_%010d_left.mp4"), m_dataset_video_path, m_annotation_ID);
	tmp_string_center.Format(_T("%sKETI_SL_%010d_center.mp4"), m_dataset_video_path, m_annotation_ID);
	tmp_string_right.Format(_T("%sKETI_SL_%010d_right.mp4"), m_dataset_video_path, m_annotation_ID);
	//::CopyFile(_T("output_left.mp4"), tmp_string_left, FALSE);
	//::CopyFile(_T("output_center.mp4"), tmp_string_center, FALSE);
	//::CopyFile(_T("output_right.mp4"), tmp_string_right, FALSE);


	//if (ConvertSVOtoAVI(CString(_T("output_left.svo")), tmp_string_left) < 0)
	//{
	//	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
	//	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
	//	m_view_flag = true;
	//	return;
	//}
	//if (ConvertSVOtoAVI(CString(_T("output_center.svo")), tmp_string_center) < 0)
	//{
	//	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
	//	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
	//	m_view_flag = true;
	//	return;
	//}
	//if (ConvertSVOtoAVI(CString(_T("output_right.svo")), tmp_string_right) < 0)
	//{
	//	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
	//	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
	//	m_view_flag = true;
	//	return;
	//}


	Document doc;
	doc.SetObject();


	StringBuffer s;
	PrettyWriter<StringBuffer> writer(s);
	writer.StartObject();

	// annotation ID
	m_edit_annotation_ID.GetWindowTextW(tmp_string);
	writer.Key("ID");
	writer.String((const char*)CT2CA(tmp_string));

	// Korean (text)
	m_edit_annotation_korean.GetWindowTextW(tmp_string);
	writer.Key("Korean");
	writer.String((const char*)CT2CA(tmp_string));
	
	// Korean sign language (GLOSS, text)
	writer.Key("GLOSS");
	writer.StartArray();
	int num_items = m_list_annotation_gloss.GetItemCount();
	for (int i = 0; i < num_items; i++)
	{
		tmp_string = m_list_annotation_gloss.GetItemText(i, 0);
		writer.String((const char*)CT2CA(tmp_string));
	}
	writer.EndArray();

	// acquisition year
	m_edit_annotation_year.GetWindowTextW(tmp_string);
	writer.Key("Year");
	writer.String((const char*)CT2CA(tmp_string));

	// sign language type
	m_combo_annotation_type.GetLBText(m_combo_annotation_type.GetCurSel(), tmp_string);
	writer.Key("Type");
	writer.String((const char*)CT2CA(tmp_string));

	// camera parameters - left stereo camera
	writer.Key("CamParam_Left_FocalLength_Left");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.fx);
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.fy);
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Left_FocalLength_Right");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.fx);
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.fy);
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Left_PrinciplePoints_Left");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.cx);
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.cy);
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Left_PrinciplePoints_Right");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.cx);
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.cy);
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Left_LensDistortion_Left");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.disto[0]); // k1
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.disto[1]); // k2
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.disto[2]); // k3
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.disto[3]); // p1
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.disto[4]); // p2
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Left_LensDistortion_Right");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.disto[0]); // k1
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.disto[1]); // k2
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.disto[2]); // k3
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.disto[3]); // p1
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.disto[4]); // p2
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();


	writer.Key("CamParam_Left_FoV_Left");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.h_fov); // horizontal fov
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.v_fov); // vertical fov
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.d_fov); // diagonal fov
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Left_FoV_Right");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.h_fov); // horizontal fov
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.v_fov); // vertical fov
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.d_fov); // diagonal fov
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Left_Transform");
	writer.StartArray();
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r00); // r00
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r01); // r01
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r02); // r02
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.tx);  // tx
		writer.String((const char*)CT2CA(tmp_string));

		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r10); // r10
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r11); // r11
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r12); // r12
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.ty);  // ty
		writer.String((const char*)CT2CA(tmp_string));

		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r20); // r20
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r21); // r21
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.r22); // r22
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.tz);  // tz
		writer.String((const char*)CT2CA(tmp_string));

		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.m30); // m30
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.m31); // m31
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.m32); // m32
		writer.String((const char*)CT2CA(tmp_string));
		tmp_string.Format(_T("%f"), m_cam_calibration_param_left.stereo_transform.m33); // m33
		writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Left_Baseline");
	tmp_string.Format(_T("%f"), m_cam_calibration_param_left.getCameraBaseline()); // baseline
	writer.String((const char*)CT2CA(tmp_string));

	writer.Key("CamParam_Left_Resolution_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_left.left_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Left_Resolution_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_left.right_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();


	// camera parameters - Center stereo camera
	writer.Key("CamParam_Center_FocalLength_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.fx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.fy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Center_FocalLength_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.fx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.fy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Center_PrinciplePoints_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.cx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.cy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Center_PrinciplePoints_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.cx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.cy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Center_LensDistortion_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.disto[0]); // k1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.disto[1]); // k2
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.disto[2]); // k3
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.disto[3]); // p1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.disto[4]); // p2
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Center_LensDistortion_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.disto[0]); // k1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.disto[1]); // k2
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.disto[2]); // k3
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.disto[3]); // p1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.disto[4]); // p2
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Center_FoV_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.h_fov); // horizontal fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.v_fov); // vertical fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.d_fov); // diagonal fov
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Center_FoV_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.h_fov); // horizontal fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.v_fov); // vertical fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.d_fov); // diagonal fov
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Center_Transform");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r00); // r00
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r01); // r01
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r02); // r02
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.tx);  // tx
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r10); // r10
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r11); // r11
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r12); // r12
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.ty);  // ty
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r20); // r20
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r21); // r21
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.r22); // r22
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.tz);  // tz
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.m30); // m30
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.m31); // m31
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.m32); // m32
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.stereo_transform.m33); // m33
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Center_Baseline");
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.getCameraBaseline()); // baseline
	writer.String((const char*)CT2CA(tmp_string));

	writer.Key("CamParam_Center_Resolution_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.left_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Center_Resolution_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_center.right_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	

	// camera parameters - Right stereo camera
	writer.Key("CamParam_Right_FocalLength_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.fx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.fy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Right_FocalLength_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.fx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.fy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Right_PrinciplePoints_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.cx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.cy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Right_PrinciplePoints_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.cx);
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.cy);
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Right_LensDistortion_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.disto[0]); // k1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.disto[1]); // k2
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.disto[2]); // k3
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.disto[3]); // p1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.disto[4]); // p2
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Right_LensDistortion_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.disto[0]); // k1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.disto[1]); // k2
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.disto[2]); // k3
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.disto[3]); // p1
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.disto[4]); // p2
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Right_FoV_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.h_fov); // horizontal fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.v_fov); // vertical fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.d_fov); // diagonal fov
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Right_FoV_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.h_fov); // horizontal fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.v_fov); // vertical fov
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.d_fov); // diagonal fov
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Right_Transform");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r00); // r00
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r01); // r01
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r02); // r02
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.tx);  // tx
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r10); // r10
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r11); // r11
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r12); // r12
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.ty);  // ty
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r20); // r20
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r21); // r21
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.r22); // r22
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.tz);  // tz
	writer.String((const char*)CT2CA(tmp_string));

	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.m30); // m30
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.m31); // m31
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.m32); // m32
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.stereo_transform.m33); // m33
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();

	writer.Key("CamParam_Right_Baseline");
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.getCameraBaseline()); // baseline
	writer.String((const char*)CT2CA(tmp_string));

	writer.Key("CamParam_Right_Resolution_Left");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.left_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();
	writer.Key("CamParam_Right_Resolution_Right");
	writer.StartArray();
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.image_size.width); // width
	writer.String((const char*)CT2CA(tmp_string));
	tmp_string.Format(_T("%f"), m_cam_calibration_param_right.right_cam.image_size.height); // height
	writer.String((const char*)CT2CA(tmp_string));
	writer.EndArray();


	writer.EndObject();

	tmp_string.Format(_T("%sKETI_SL_%010d.json"), m_dataset_annotation_path, m_annotation_ID);
	std::ofstream of(tmp_string);
	of << s.GetString();


	FILE* fp;
	int prev_id;
	fopen_s(&fp, "current_file.txt", "wb");
	fprintf_s(fp, "%d", m_annotation_ID);
	fclose(fp);


	m_view_flag = false;
	m_thread_grab_image = NULL;
	//Sleep(2000.0);

	while (!IsFileWritable(tmp_string_left) || !IsFileWritable(tmp_string_center) || !IsFileWritable(tmp_string_right))
	{
		Sleep(10);
	}

	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);
	m_thread_grab_image = AfxBeginThread(ThreadProcGrab, this);
	m_view_flag = true;
	AfxMessageBox(_T("저장 완료!"));
}

BOOL CSLDBEditorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (::TranslateAccelerator(this->m_hWnd, m_Accelerators, pMsg)) return TRUE;

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			if (GetFocus()->GetDlgCtrlID() == m_edit_annotation_ID.GetDlgCtrlID())
			{
				m_play_flag = false;
				LoadExcelContents();
				pMsg->wParam = VK_TAB;
			}
			else
			{
				GotoDlgCtrl(GetDlgItem(m_edit_annotation_ID.GetDlgCtrlID()));
				pMsg->wParam = VK_TAB;
			}
		}
		else if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
		else if (pMsg->wParam == VK_F2)
		{
			m_combo_cam_select.SetCurSel(0);
			OnSelendokComboCamSelect();
		}
		else if (pMsg->wParam == VK_F3)
		{
			m_combo_cam_select.SetCurSel(1);
			OnSelendokComboCamSelect();
		}
		else if (pMsg->wParam == VK_F4)
		{
			m_combo_cam_select.SetCurSel(2);
			OnSelendokComboCamSelect();
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

int CSLDBEditorDlg::LoadExcelContents()
{
	// TODO: 여기에 구현 코드 추가.
	m_play_flag = false;
	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("로드중..."), 1000, 20);
	CString tmp_string;
	m_edit_annotation_ID.GetWindowTextW(tmp_string);
	m_annotation_ID = _ttoi(tmp_string);
	int personal_ID = 0;
	int tmp_cursor;
	int row_idx_annotation;
	int row_idx_personal;

	CXLEzAutomation XL(FALSE);
	XL.OpenExcelFile(m_dataset_excel_annotation_path);

	if (m_annotation_ID < sizeof(m_excel_ID_list_annotation))
	{
		row_idx_annotation = m_excel_ID_list_annotation[m_annotation_ID];
	}
	else 
	{
		row_idx_annotation = 0;
	}
	
	
	// annotation loading
	if (row_idx_annotation != 0)
	{
		// 취득연도
		tmp_string.Format(_T("%d"), _ttoi(XL.GetCellValue(3, row_idx_annotation)));
		m_edit_annotation_year.SetWindowTextW(tmp_string);
		
		// 타입(단어/문장)
		tmp_string = XL.GetCellValue(4, row_idx_annotation);
		if (!tmp_string.CompareNoCase(_T("단어"))) m_combo_annotation_type.SetCurSel(0);
		else if (!tmp_string.CompareNoCase(_T("문장"))) m_combo_annotation_type.SetCurSel(1);
		else if (!tmp_string.CompareNoCase(_T("지화"))) m_combo_annotation_type.SetCurSel(2);

		// 한국어 문장
		tmp_string = XL.GetCellValue(5, row_idx_annotation);
		m_edit_annotation_korean.SetWindowTextW(tmp_string);

		// 수어 형태소
		m_list_annotation_gloss.DeleteAllItems();
		m_list_annotation_gloss.InsertColumn(0, _T(""), LVCFMT_CENTER, 300);
		tmp_string = XL.GetCellValue(6, row_idx_annotation);
		for (int i=0;;i++)
		{
			tmp_cursor = tmp_string.Find(',');
			if (tmp_cursor < 0)
			{
				m_list_annotation_gloss.InsertItem(i, tmp_string);
				break;
			}
			else
			{
				m_list_annotation_gloss.InsertItem(i, tmp_string.Left(tmp_cursor));
			}			
			tmp_string = tmp_string.Mid(tmp_cursor + 1);
		}

		// personal information loading
		// 언어제공자 ID
		if (_ttoi(XL.GetCellValue(2, row_idx_annotation)) < sizeof(m_excel_ID_list_personal))
		{
			row_idx_personal = m_excel_ID_list_personal[_ttoi(XL.GetCellValue(2, row_idx_annotation))];
		}
		else
		{
			row_idx_personal = 0;
		}
		//row_idx_personal = m_excel_ID_list_personal[_ttoi(XL.GetCellValue(2, row_idx_annotation))];

		XL.OpenExcelFile(m_dataset_excel_personal_path);
		if (row_idx_personal != 0)
		{
			// ID
			tmp_string.Format(_T("%d"), _ttoi(XL.GetCellValue(1, row_idx_personal)));
			m_edit_personal_ID.SetWindowTextW(tmp_string);

			// 이름
			tmp_string = XL.GetCellValue(3, row_idx_personal);
			m_edit_personal_name.SetWindowTextW(tmp_string);

			// 나이
			tmp_string.Format(_T("%d"), _ttoi(XL.GetCellValue(4, row_idx_personal)));
			m_edit_personal_age.SetWindowTextW(tmp_string);

			// 성별
			tmp_string = XL.GetCellValue(5, row_idx_personal);
			if (!tmp_string.CompareNoCase(_T("남"))) m_combo_personal_sex.SetCurSel(0);
			else if (!tmp_string.CompareNoCase(_T("여"))) m_combo_personal_sex.SetCurSel(1);

			// 거주지
			tmp_string = XL.GetCellValue(6, row_idx_personal);
			m_edit_personal_home.SetWindowTextW(tmp_string);

			// 성별
			tmp_string = XL.GetCellValue(7, row_idx_personal);
			if (!tmp_string.CompareNoCase(_T("우"))) m_combo_personal_hand_dominance.SetCurSel(0);
			else if (!tmp_string.CompareNoCase(_T("좌"))) m_combo_personal_hand_dominance.SetCurSel(1);

			// 출신학교
			tmp_string = XL.GetCellValue(8, row_idx_personal);
			m_edit_personal_school.SetWindowTextW(tmp_string);

			// 농가족유무
			tmp_string = XL.GetCellValue(9, row_idx_personal);
			if (!tmp_string.CompareNoCase(_T("유"))) m_combo_personal_family.SetCurSel(0);
			else if (!tmp_string.CompareNoCase(_T("무"))) m_combo_personal_family.SetCurSel(1);

			// 참여 횟수
			tmp_string.Format(_T("%d"), _ttoi(XL.GetCellValue(10, row_idx_personal)));
			m_edit_personal_experience.SetWindowTextW(tmp_string);
		}
		else
		{
			AfxMessageBox(_T("언어제공자 정보가 존재하지 않습니다!\nExcel 파일을 확인해주세요!"));
		}
	}
	else
	{
		m_edit_annotation_ID.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("영상 데이터 ID가 존재하지 않습니다!\nExcel 파일을 확인해주세요!"));
	}
	XL.ReleaseExcel();

	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);

	return 0;
}

int CSLDBEditorDlg::FindItemRowInExcel(CString path, CString item, int colmun_idx)
{
	// TODO: 여기에 구현 코드 추가.
	CXLEzAutomation XL(FALSE);
	int row_idx = 2;
	CString tmp_string;
	double tmp_value;
	XL.OpenExcelFile(path);
	while (1)
	{
		tmp_string = XL.GetCellValue(colmun_idx, row_idx);
		if (tmp_string.IsEmpty())
		{
			break;
		}			
		else 
		{
			tmp_value = _ttoi(tmp_string);
			if (tmp_value)
			{
				if (_ttoi(item) == tmp_value)
					return row_idx;
			}
			else
			{
				if (!tmp_string.CompareNoCase(item))
					return row_idx;
			}				
		}
		row_idx++;
	}
	XL.ReleaseExcel();
	return 0;
}

int CSLDBEditorDlg::LoadExcelIDList()
{
	// TODO: 여기에 구현 코드 추가.
	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("로드중..."), 1000, 20);

	CXLEzAutomation XL(FALSE);
	CString tmp_string;
	int tmp_value;
	int row_idx;
	int colmun_idx = 1;

	XL.OpenExcelFile(m_dataset_excel_annotation_path);
	row_idx = 2;
	while (1)
	{
		tmp_string = XL.GetCellValue(colmun_idx, row_idx);
		if (tmp_string.IsEmpty())
		{
			break;
		}
		else
		{
			tmp_value = (int)(_ttoi(tmp_string));
			m_excel_ID_list_annotation[tmp_value] = row_idx;
		}
		row_idx++;
	}

	XL.OpenExcelFile(m_dataset_excel_personal_path);
	row_idx = 2;
	while (1)
	{
		tmp_string = XL.GetCellValue(colmun_idx, row_idx);
		if (tmp_string.IsEmpty())
		{
			break;
		}
		else
		{
			tmp_value = (int)(_ttoi(tmp_string));
			m_excel_ID_list_personal[tmp_value] = row_idx;
		}
		row_idx++;
	}

	XL.ReleaseExcel();
	XL.ReleaseExcel();

	DrawStyledText(m_text_status.GetDlgCtrlID(), _T("대기중..."), 1000, 20);

	return 0;
}


void CSLDBEditorDlg::OnAcceleratorRecord()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedBtnRecord();
}
void CSLDBEditorDlg::OnAcceleratorPlay()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedButtonPlay();
}
void CSLDBEditorDlg::OnAcceleratorSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedButtonSave();
}
void CSLDBEditorDlg::OnAcceleratorStop()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedButtonPause();
}


int CSLDBEditorDlg::ConvertSVOtoAVI(CString source_path, CString target_path)
{
	// TODO: 여기에 구현 코드 추가.

	sl::Camera zed;
	sl::InitParameters init_parameters;
	init_parameters.input.setFromSVOFile((const char*)CT2CA(source_path));
	if (zed.open(init_parameters) != sl::ERROR_CODE::SUCCESS)
	{
		AfxMessageBox(_T("저장 실패!"));
		return -1;
	}

	sl::Resolution image_size = zed.getCameraInformation().camera_configuration.resolution;
	int width = image_size.width;
	int height = image_size.height;
	int width_sbs = image_size.width * 2;
	cv::Size image_size_sbs(width*2, height);

	
	sl::RuntimeParameters rt_params;
	sl::ERROR_CODE res;
	cv::Mat mat_Image_current;
	mat_Image_current = Mat(height, width * 2, CV_8UC4, 1);

	cv::VideoWriter video_writer;
	int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
	int frame_rate = fmax(zed.getInitParameters().camera_fps, this->m_cam_fps);
	video_writer.open((const char*)CT2CA(target_path), fourcc, frame_rate, image_size_sbs, true);
	if (!video_writer.isOpened())
	{
		AfxMessageBox(_T("저장 실패!"));
		zed.close();
		return -1;
	}

	zed.setSVOPosition(0);
	int svo_position = 0;
	sl::Mat aux(width * 2, height, sl::MAT_TYPE::U8_C4);
	mat_Image_current = slMat2cvMat(aux);

	int i = 0;
	while(1)
	{
		res = zed.grab(rt_params);

		if (zed.getSVOPosition() >= zed.getSVONumberOfFrames())
		{
			break;
		}

		zed.retrieveImage(aux, sl::VIEW::SIDE_BY_SIDE, sl::MEM::CPU);
		cv::Mat bar = slMat2cvMat(aux);
		// Convert SVO image from RGBA to RGB
		cv::cvtColor(bar, mat_Image_current, cv::COLOR_RGBA2RGB);

		video_writer.write(mat_Image_current);
	}

	video_writer.release();
	zed.close();

	return 0;
}


cv::Mat CSLDBEditorDlg::slMat2cvMat(sl::Mat& input)
{
	// TODO: 여기에 구현 코드 추가.
	int cv_type = -1;
	switch (input.getDataType()) {
	case sl::MAT_TYPE::F32_C1: cv_type = CV_32FC1; break;
	case sl::MAT_TYPE::F32_C2: cv_type = CV_32FC2; break;
	case sl::MAT_TYPE::F32_C3: cv_type = CV_32FC3; break;
	case sl::MAT_TYPE::F32_C4: cv_type = CV_32FC4; break;
	case sl::MAT_TYPE::U8_C1: cv_type = CV_8UC1; break;
	case sl::MAT_TYPE::U8_C2: cv_type = CV_8UC2; break;
	case sl::MAT_TYPE::U8_C3: cv_type = CV_8UC3; break;
	case sl::MAT_TYPE::U8_C4: cv_type = CV_8UC4; break;
	default: break;
	}
	// Since cv::Mat data requires a uchar* pointer, we get the uchar1 pointer from sl::Mat (getPtr<T>())
	// cv::Mat and sl::Mat will share a single memory structure
	return cv::Mat(input.getHeight(), input.getWidth(), cv_type, input.getPtr<sl::uchar1>(sl::MEM::CPU));
}




bool CSLDBEditorDlg::IsFileWritable(CString filepath)
{
	// TODO: 여기에 구현 코드 추가.
	HANDLE      hFile = INVALID_HANDLE_VALUE;

	hFile = CreateFile((LPCTSTR)filepath, GENERIC_READ | GENERIC_WRITE,	0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	CloseHandle(hFile);

	return TRUE;

}
