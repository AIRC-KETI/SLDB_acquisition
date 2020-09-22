
// SLDBEditorDlg.h: 헤더 파일
//
#include "StatusDlg.h"

#pragma once

// CSLDBEditorDlg 대화 상자
class CSLDBEditorDlg : public CDialogEx
{
// 생성입니다.
public:
	CSLDBEditorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SLDBEDITOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	StatusDlg* m_status_dlg;
	CString m_dataset_path;
	CString m_dataset_video_path;
	CString m_dataset_annotation_path;
	CString m_dataset_excel_annotation_path;
	CString m_dataset_excel_personal_path;

	CStatic m_cam_view;
	sl::Camera* m_cam_left;
	sl::Camera* m_cam_center;
	sl::Camera* m_cam_right;
	sl::Camera* m_cam_current;
	sl::Camera m_video_current;
	sl::CalibrationParameters m_cam_calibration_param_left;
	sl::CalibrationParameters m_cam_calibration_param_center;
	sl::CalibrationParameters m_cam_calibration_param_right;
	CWinThread *m_thread_grab_image;
	CWinThread *m_thread_play_video;
	CWinThread *m_thread_record_image;
	CWinThread *m_thread_record_image_left;
	CWinThread *m_thread_record_image_center;
	CWinThread *m_thread_record_image_right;
	CWinThread* m_thread_save_avi_left;
	CWinThread* m_thread_save_avi_center;
	CWinThread* m_thread_save_avi_right;
	Size m_cam_resolution;
	float m_cam_aspect_ratio;
	float m_cam_fps;
	float m_video_fps;
	bool m_run;
	bool m_view_flag;
	bool m_recording_flag;
	bool m_record_frame_left_flag;
	bool m_record_frame_center_flag;
	bool m_record_frame_right_flag;
	bool m_play_flag;
	bool m_save_avi_left_flag;
	bool m_save_avi_center_flag;
	bool m_save_avi_right_flag;
	bool m_save_avi_switch;
	afx_msg UINT CSLDBEditorDlg::GrabLoop();
	afx_msg UINT CSLDBEditorDlg::PlayLoop();

	afx_msg void OnSize(UINT nType, int cx, int cy);
	CComboBox m_combo_cam_select;
	afx_msg void OnSelendokComboCamSelect();
	afx_msg void OnDestroy();
	int DisplayCamImage(Mat mat_image);
	CButton m_btn_record;
	afx_msg void OnBnClickedBtnRecord();
	int DrawBitmapButton(CButton *button, int bitmap_id);
	CButton m_btn_play;
	afx_msg void OnBnClickedButtonPlay();
	CButton m_btn_pause;
	afx_msg void OnBnClickedButtonPause();
	CStatic m_text_status;
	int DrawStyledText(int text_ID, CString contents, int weight, int height);
	CEdit m_edit_personal_ID;
	CEdit m_edit_personal_name;
	CEdit m_edit_personal_age;
	CComboBox m_combo_personal_sex;
	CEdit m_edit_personal_home;
	CComboBox m_combo_personal_hand_dominance;
	CEdit m_edit_personal_school;
	CComboBox m_combo_personal_family;
	CEdit m_edit_personal_experience;
	CStatic m_static_personal;
	CStatic m_static_personal_ID;
	CStatic m_static_personal_name;
	CStatic m_static_personal_age;
	CStatic m_static_personal_sex;
	CStatic m_static_personal_home;
	CStatic m_static_personal_hand_dominance;
	CStatic m_static_personal_school;
	CStatic m_static_personal_family;
	CStatic m_static_personal_experience;

	CButton m_btn_save;
	afx_msg void OnBnClickedButtonSave();
	CEdit m_edit_annotation_ID;
	CComboBox m_combo_annotation_type;
	CEdit m_edit_annotation_year;
	CEdit m_edit_annotation_korean;
	CListCtrl m_list_annotation_gloss;
	CStatic m_static_annotation;
	CStatic m_static_annotation_ID;
	CStatic m_static_annotation_type;
	CStatic m_static_annotation_year;
	CStatic m_static_annotation_korean;
	CStatic m_static_annotation_gloss;
	UINT RecordLoop();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	UINT RecordLoop_left();
	UINT RecordLoop_center();
	UINT RecordLoop_right();

	// excel contents
	int m_annotation_ID;
	int m_excel_ID_list_personal[100000];
	int m_excel_ID_list_annotation[100000];
	int LoadExcelContents();
	int FindItemRowInExcel(CString path, CString item, int colmun_idx);
	int LoadExcelIDList();
	afx_msg void OnAcceleratorPlay();
	afx_msg void OnAcceleratorRecord();
	afx_msg void OnAcceleratorSave();
	afx_msg void OnAcceleratorStop();
	HACCEL m_Accelerators;
	int ConvertSVOtoAVI(CString source_path, CString target_path);
	cv::Mat slMat2cvMat(sl::Mat& input);


	int m_annotation_ID_prev;
	UINT SaveAVI_left();
	UINT SaveAVI_center();
	UINT SaveAVI_right();
	bool IsFileWritable(CString filepath);
};

UINT ThreadProcGrab(LPVOID IParam);
UINT ThreadProcPlay(LPVOID IParam);
UINT ThreadProcRecord(LPVOID IParam);
UINT ThreadProcRecord_left(LPVOID IParam);
UINT ThreadProcRecord_center(LPVOID IParam);
UINT ThreadProcRecord_right(LPVOID IParam);
UINT ThreadProcSave_left(LPVOID IParam);
UINT ThreadProcSave_center(LPVOID IParam);
UINT ThreadProcSave_right(LPVOID IParam);

