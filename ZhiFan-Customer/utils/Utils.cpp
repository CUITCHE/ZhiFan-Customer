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
		entity->title() = "寻找童年的记忆";
		entity->briefDesc() = "努力过后，才知道许多事情，坚持坚持，就过来了。每个人都在探索命运的意义，幸福的生活，是把幸福当做一种行为，能把所有的烦恼都看成无所谓，是人生的权利，也是义务。人往人多处活，心往安静处想，要想平复烦恼，那么很显然，需要一个很平的心态。";
		entity->responseInfo() = "放弃是牺牲本来属于你的，放手是放下那些从来就不是你的。别指望所有的人都能懂你，痛过，才知道如何保护自己；哭过，才知道心痛是什么感觉；傻过，才知道适时的坚持与放弃；爱过，才知道自己其实很脆弱。其实，生活并不需要这么些无谓的执着，没有什么就真的不能割舍。";
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

