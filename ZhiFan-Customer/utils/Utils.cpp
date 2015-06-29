#include "stdafx.h"
#include "Utils.h"
#include "PublishBriefOneEntity.h"
namespace utils{

	void ImageToByteArray(const QImage &image, QByteArray &dataArray, const char *format /*= 0*/)
	{
		dataArray.clear();
		QBuffer buffer(&dataArray);
		buffer.open(QIODevice::ReadWrite);
		bool ret = image.save(&buffer, format);
		if (ret == false){
			qDebug() << "图片转换失败";
		}
	}

	void ByteArrayToImage(const QByteArray &dataArray, QImage &image, const char *format /*= 0*/)
	{
		image = QImage::fromData(dataArray, format);
	}

	QList<PublishBriefOneEntity *> getdata()
	{
		QVector<QImage> data;
		for (int i = 0; i < 3; ++i){
			data.push_back(QImage(QString(":/%1.jpg").arg(i)));
		}
		PublishBriefOneEntity *entity = new PublishBriefOneEntity;
		QList<QVariant> _list;
		for (auto &val : data){
			QByteArray array;
			utils::ImageToByteArray(val, array, "JPG");
			_list.push_back(array);
		}
		entity->photo() = _list;
		entity->briefDesc() = "dsdsfefe";
		entity->responseInfo() = "你壕的。。发得分分发热";
		QList<PublishBriefOneEntity *> lll;
		for (int i = 0; i < 10; ++i){
			PublishBriefOneEntity *e = new PublishBriefOneEntity;
			*e = *entity;
			lll.push_back(e);
		}
		return lll;
	}

}

