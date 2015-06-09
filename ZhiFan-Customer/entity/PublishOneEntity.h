#ifndef PublishOneEntity_H__
#define PublishOneEntity_H__

/*!
 * \file PublishOneEntity.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 知返详细信息实体
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(PublishOneEntity)

ENTITY_MEMBER_DEFINITION(int, publishId);
ENTITY_MEMBER_DEFINITION(int, ownerId);
ENTITY_MEMBER_DEFINITION(QDateTime, publishdate);
ENTITY_MEMBER_DEFINITION(int, lostType);
ENTITY_MEMBER_DEFINITION(QString, contactPlaceCode);
ENTITY_MEMBER_DEFINITION(QDate, lostDate);
ENTITY_MEMBER_DEFINITION(int, lostPlaceCodep);
ENTITY_MEMBER_DEFINITION(int, lostPlaceCodec);
ENTITY_MEMBER_DEFINITION(int, lostPlaceCoded);
ENTITY_MEMBER_DEFINITION(QString, lostPlacedetail);
ENTITY_MEMBER_DEFINITION(int, bills);
ENTITY_MEMBER_DEFINITION(int, userid);

ENTITY_CLASS_DEFINITION_END
#endif // PublishOneEntity_H__
