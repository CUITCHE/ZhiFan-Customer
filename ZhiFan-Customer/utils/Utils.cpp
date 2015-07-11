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
			qDebug() << "ͼƬת��ʧ��";
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
		entity->title() = "Ѱ��ͯ��ļ���";
		entity->briefDesc() = "Ŭ�����󣬲�֪��������飬��ּ�֣��͹����ˡ�ÿ���˶���̽�����˵����壬�Ҹ�������ǰ��Ҹ�����һ����Ϊ���ܰ����еķ��ն���������ν����������Ȩ����Ҳ�����������˶ദ������������룬Ҫ��ƽ�����գ���ô����Ȼ����Ҫһ����ƽ����̬��";
		entity->responseInfo() = "��������������������ģ������Ƿ�����Щ�����Ͳ�����ġ���ָ�����е��˶��ܶ��㣬ʹ������֪����α����Լ����޹�����֪����ʹ��ʲô�о���ɵ������֪����ʱ�ļ�����������������֪���Լ���ʵ�ܴ�������ʵ���������Ҫ��ôЩ��ν��ִ�ţ�û��ʲô����Ĳ��ܸ��ᡣ";
		entity->responseNum() = 52654;
		QList<PublishBriefOneEntity *> lll;
		for (int i = 0; i < 10; ++i){
			PublishBriefOneEntity *e = new PublishBriefOneEntity;
			*e = *entity;
			lll.push_back(e);
		}
		delete entity;
		return lll;
	}

}

