#ifndef Utils_H__
#define Utils_H__

/*!
 * \file Utils.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 所有需要用到的工具，方法
 */
class QVariant;
class QByteArray;
class QImage;
class PublishBriefOneEntity;
template<typename T> class QList;
namespace utils{
	//@brief bytes 不会经过base64加密
	void ImageToByteArray(const QImage &image, QByteArray &dataArray, const char *format = 0);

	//@brief bytes 不是经过base64加密的数据
	void ByteArrayToImage(const QByteArray &dataArray, QImage &image, const char *format = 0);

	//@brief 测试数据块
	QList<PublishBriefOneEntity *> getdata();
}
#endif // Utils_H__
