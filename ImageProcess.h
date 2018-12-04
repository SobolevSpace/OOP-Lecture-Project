#ifndef _IMAGE_PROCESS_H
#define _IMAGE_PROCESS_H
/*
 * ���ʹ��ImageProcess��ImageConverter��
 * ImageProcess.h������cv::Mat��ʵ�֣����ǰ�˲���Ҫ׼��OpenCV�������ɰ���ͷ�ļ�
 * ǰ�˵���ʱ���������н�ImageProcess.cpp�е�ʵ���޸�Ϊ����ҪOpenCV��
 * ����QImageToMatת����������QImage���κ�ת����ֻ�Ƿ���QImage��ָ�룻MatToQImageҲֻ�ǽ���ָ��
 * ��ǰ��˺ϲ�ʱ���ٰ�ImageProcess.cpp��Ϊ��ǰ�������õ�ʵ�֡�
 * ����ImageProcess.cpp������Qtͷ�ļ�����˺�˲���Ҫӵ��Qt������
 * 
 * ImageConvertor.hͬ��������cv::Mat��ʵ��
 * ����ǰ�˵���ʱ����OpenCV����ʹ�á�
 * ���û��ʹ�����������ͷ�ļ���ֱ��ʹ����Qt�ࡣ
 */

namespace cv {
	class Mat;
}

class ImageProcess
{
	using MAT = cv::Mat*;
	static cv::Mat& parseMAT(MAT Mat);
public:
	static MAT generate3ChannelsNormalTexture(MAT Mat);
};

#endif