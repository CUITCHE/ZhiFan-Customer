#ifndef UserEntity_H__
#define UserEntity_H__

/*!
 * \file UserEntity.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��½֮�󣬱����û�����Ϣ
 */
#include "Entity.h"

ENTITY_CLASS_DEFINITION_BEGIN(UserEntity)

ENTITY_MEMBER_DEFINITION(bool, identification);
ENTITY_MEMBER_DEFINITION(QString, idCardSubstring);
ENTITY_MEMBER_DEFINITION(int, zfb);
ENTITY_MEMBER_DEFINITION(int, userid);

ENTITY_CLASS_DEFINITION_END
#endif // UserEntity_H__
