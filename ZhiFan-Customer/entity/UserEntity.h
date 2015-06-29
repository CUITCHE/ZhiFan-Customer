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
//以下数据来自身份证，若身份证号为空，则数据无效
//出生日期
ENTITY_MEMBER_DEFINITION(QDate, birthday);
//性别
ENTITY_MEMBER_DEFINITION(bool, gender);

ENTITY_CLASS_DEFINITION_END
#endif // UserEntity_H__
