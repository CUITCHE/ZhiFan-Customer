#ifndef ZhiFanPublishBriefOne_H__
#define ZhiFanPublishBriefOne_H__

/*!
 * \file ZhiFanPublishBriefOne.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ZhiFanPublishBriefOne
 */
#include "Packet.h"
#include <QList>
#include <QDateTime>
/*
publishId��int��֪��id
ownerId��int��������id
title��string��64��������
photo��stringBASE64-list��ͼƬ��Ϣ
lightEyes��bool���Ƿ���Ŀ
topTime���ö���ʱ��
briefDesc��string��������Ϣ

type��int��0���죬1Ѱ��
responseNum��int���ش���
responseInfo��string��nchar�������ԵĻش���Ϣ����������
resposneApplaudNum��int�������ش�ĵ��޴���

*/
class ZhiFanPublishBriefOnePacket;
Q_DECLARE_METATYPE(ZhiFanPublishBriefOnePacket);
PACKET_DEFINITION_BEGIN(ZhiFanPublishBriefOne)
Q_OBJECT
PACKET_STRUCTION(ZhiFanPublishBriefOne)
operator QVariant()const{
	return QVariant::fromValue(*this);
}
//publishId��int��֪��id
QT_MOC_MINE_DEFINITION(int, publishId, PublishId);
//ownerId��int��������id
QT_MOC_MINE_DEFINITION(int, ownerId, OwnerId);
//photo��stringBASE64-list��ͼƬ��Ϣ
QT_MOC_MINE_DEFINITION(QList<QVariant>, photo, Photo);
//briefDesc��string�����Ե�������Ϣ
QT_MOC_MINE_DEFINITION(QString, briefDesc, BriefDesc);
//title��string��64��������
QT_MOC_MINE_DEFINITION(QString, title, Title);
//lightEyes��bool���Ƿ���Ŀ
QT_MOC_MINE_DEFINITION(bool, lightEyes, LightEyes);
//topTime���ö���ʱ��
QT_MOC_MINE_DEFINITION(QDateTime, topTime, TopTime);

//type��int��0���죬1Ѱ��
QT_MOC_MINE_DEFINITION(int, type, Type);
//responseNum��int���ش���
QT_MOC_MINE_DEFINITION(int, responseNum, ResponseNum);
//responseInfo��string��nchar�������ԵĻش���Ϣ����������
QT_MOC_MINE_DEFINITION(QString, responseInfo, ResponseInfo);
//resposneApplaudNum��int�������ش�ĵ��޴���
QT_MOC_MINE_DEFINITION(int, resposneApplaudNum, ResposneApplaudNum);


PACKET_DEFINITION_END
#endif // ZhiFanPublishBriefOne_H__
