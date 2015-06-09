#ifndef UserEntity_H__
#define UserEntity_H__

/*!
 * \file UserEntity.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 登陆之后，保存用户的信息
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(UserEntity)

ENTITY_MEMBER_DEFINITION(bool, identification);
ENTITY_MEMBER_DEFINITION(QString, idCardSubstring);
ENTITY_MEMBER_DEFINITION(int, zfb);
ENTITY_MEMBER_DEFINITION(int, userid);

ENTITY_CLASS_DEFINITION_END
#endif // UserEntity_H__
