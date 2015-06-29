#ifndef Utils_H__
#define Utils_H__

/*!
 * \file Utils.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ������Ҫ�õ��Ĺ��ߣ�����
 */
class QVariant;
class QByteArray;
class QImage;
class PublishBriefOneEntity;
template<typename T> class QList;
namespace utils{
	//@brief bytes ���ᾭ��base64����
	void ImageToByteArray(const QImage &image, QByteArray &dataArray, const char *format = 0);

	//@brief bytes ���Ǿ���base64���ܵ�����
	void ByteArrayToImage(const QByteArray &dataArray, QImage &image, const char *format = 0);

	//@brief �������ݿ�
	QList<PublishBriefOneEntity *> getdata();
}
#endif // Utils_H__
