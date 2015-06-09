#ifndef PublishBriefOneEntity_H__
#define PublishBriefOneEntity_H__

/*!
 * \file PublishBriefOneEntity.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 知返信息扼要
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(PublishBriefOneEntity)
//publishId：int：知返id
ENTITY_MEMBER_DEFINITION(int, publishId);
//ownerId：int：发布者id
ENTITY_MEMBER_DEFINITION(int, ownerId);
//photo：stringBASE64-list：图片信息
ENTITY_MEMBER_DEFINITION(QList<QVariant>, photo);
//briefDesc：string：简略的描述信息
ENTITY_MEMBER_DEFINITION(QString, briefDesc);
//title：string（64）：标题
ENTITY_MEMBER_DEFINITION(QString, title);
//lightEyes：bool：是否醒目
ENTITY_MEMBER_DEFINITION(bool, lightEyes);
//topTime：置顶的时间
ENTITY_MEMBER_DEFINITION(QDateTime, topTime);

//type：int：0招领，1寻找
ENTITY_MEMBER_DEFINITION(int, type);
//responseNum：int：回答数
ENTITY_MEMBER_DEFINITION(int, responseNum);
//responseInfo：string（nchar）：简略的回答信息，点赞最多的
ENTITY_MEMBER_DEFINITION(QString, responseInfo);
//resposneApplaudNum：int：这条回答的点赞次数
ENTITY_MEMBER_DEFINITION(int, resposneApplaudNum);

ENTITY_CLASS_DEFINITION_END
#endif // PublishBriefOneEntity_H__
