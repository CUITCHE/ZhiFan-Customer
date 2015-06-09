#ifndef UserCenterEntity_H__
#define UserCenterEntity_H__

/*!
 * \file UserCenterEntity.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 用户中心信息实体
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(UserCenterEntity)

ENTITY_MEMBER_DEFINITION(int, type);
ENTITY_MEMBER_DEFINITION(int, id);
ENTITY_MEMBER_DEFINITION(QString, briefmsg);

ENTITY_CLASS_DEFINITION_END
#endif // UserCenterEntity_H__
