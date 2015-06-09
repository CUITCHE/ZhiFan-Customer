#ifndef PublishBriefOneEntity_H__
#define PublishBriefOneEntity_H__

/*!
 * \file PublishBriefOneEntity.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ֪����Ϣ��Ҫ
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(PublishBriefOneEntity)
//publishId��int��֪��id
ENTITY_MEMBER_DEFINITION(int, publishId);
//ownerId��int��������id
ENTITY_MEMBER_DEFINITION(int, ownerId);
//photo��stringBASE64-list��ͼƬ��Ϣ
ENTITY_MEMBER_DEFINITION(QList<QVariant>, photo);
//briefDesc��string�����Ե�������Ϣ
ENTITY_MEMBER_DEFINITION(QString, briefDesc);
//title��string��64��������
ENTITY_MEMBER_DEFINITION(QString, title);
//lightEyes��bool���Ƿ���Ŀ
ENTITY_MEMBER_DEFINITION(bool, lightEyes);
//topTime���ö���ʱ��
ENTITY_MEMBER_DEFINITION(QDateTime, topTime);

//type��int��0���죬1Ѱ��
ENTITY_MEMBER_DEFINITION(int, type);
//responseNum��int���ش���
ENTITY_MEMBER_DEFINITION(int, responseNum);
//responseInfo��string��nchar�������ԵĻش���Ϣ����������
ENTITY_MEMBER_DEFINITION(QString, responseInfo);
//resposneApplaudNum��int�������ش�ĵ��޴���
ENTITY_MEMBER_DEFINITION(int, resposneApplaudNum);

ENTITY_CLASS_DEFINITION_END
#endif // PublishBriefOneEntity_H__
