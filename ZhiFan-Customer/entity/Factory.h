#ifndef Factory_H__
#define Factory_H__

/*!
 * \file Factory.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 实体工厂，采用prepare模式，形成单例模式
 * 实体工厂负责更新所有实例对象信息
 */
#include "defs.h"
#include <unordered_map>
using std::unordered_map;

class Packet;
class UserEntity;
class PublishOneEntity;
class PublishBriefOneEntity;

using UserIdType = int;
using ZhiFanIdType = int;
using ResponseIdType = long long;

class Factory
{
	PREPARE_INSTANCE_DECLARE(Factory);
public:
	////////////////////////////////////////////////////////////////////////// -用户登陆信息
	void addUserLoginInfo(const Packet *pck);

	void updateUserLoginInfo(const Packet *pck);

	const UserEntity& getUserLoginInfo()const;

	////////////////////////////////////////////////////////////////////////// -知返内容（详细）
	void addPublishInDetail(const Packet *pck);

	void updatePublishInDetail(const Packet *pck);

	const PublishOneEntity* getPublishInDetailById(ZhiFanIdType id)const;

	////////////////////////////////////////////////////////////////////////// -知返内容（扼要）
	void addPublishBrief(const Packet *pck);

	void updatePublishBrief(const Packet *pck);

	const PublishBriefOneEntity* getPublishBriefById(ZhiFanIdType id)const;
private:
	Factory();
	~Factory();
public:
	UserEntity *userEntityInfo = 0;
	unordered_map<ZhiFanIdType, PublishOneEntity*> *publishInDetail;	//知返内容（详细）
	unordered_map<ZhiFanIdType, PublishBriefOneEntity*> *publishBrief;	//知返内容（扼要）
};
#endif // Factory_H__
