#include "HolisticTrackingApi.h"
#include "HolisticTrackingDetect.h"

using namespace GoogleMediapipeDetect;

HolisticTrackingDetect m_HolisticTrackingDetect;

EXPORT_API int MediapipeHolisticTrackingInit(
	const char* model_path,
	bool is_need_video_outputstream,
	bool is_need_pose_outputstream,
	bool is_need_hand_outputstream,
	bool is_need_face_outputstream)
{
	return m_HolisticTrackingDetect.InitModel(model_path,is_need_video_outputstream,is_need_pose_outputstream,is_need_hand_outputstream,is_need_face_outputstream);
}

EXPORT_API int MediapipeHolisticTrackingDetectFrameDirect(int image_width, int image_height, void* image_data, int* detect_result, void* show_data,  bool show_result_image)
{
	return m_HolisticTrackingDetect.DetectImageDirect(image_width, image_height, image_data, detect_result, show_data, show_result_image);
}

EXPORT_API int MediapipeHolisticTrackingDetectFrameBodyInfo(int image_width, int image_height, void* image_data, void* show_data, std::vector<std::vector<std::vector<float>>>& vec_BodykeyPoints, bool show_result_image)
{
	return m_HolisticTrackingDetect.DetectImageBodyInfo(image_width, image_height, image_data, show_data, vec_BodykeyPoints, show_result_image);
}

EXPORT_API int MediapipeHolisticTrackingDetectCamera(bool show_image)
{
	return m_HolisticTrackingDetect.DetectCamera(show_image);
}

EXPORT_API int MediapipeHolisticTrackingRelease()
{
	return m_HolisticTrackingDetect.Release();
}
