#ifndef Factory_H__
#define Factory_H__

/*!
 * \file Factory.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ʵ�幤��������prepareģʽ���γɵ���ģʽ
 * ʵ�幤�������������ʵ��������Ϣ
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
	////////////////////////////////////////////////////////////////////////// -�û���½��Ϣ
	void addUserLoginInfo(const Packet *pck);

	void updateUserLoginInfo(const Packet *pck);

	const UserEntity& getUserLoginInfo()const;

	////////////////////////////////////////////////////////////////////////// -֪�����ݣ���ϸ��
	void addPublishInDetail(const Packet *pck);

	void updatePublishInDetail(const Packet *pck);

	const PublishOneEntity* getPublishInDetailById(ZhiFanIdType id)const;

	////////////////////////////////////////////////////////////////////////// -֪�����ݣ���Ҫ��
	void addPublishBrief(const Packet *pck);

	void updatePublishBrief(const Packet *pck);

	const PublishBriefOneEntity* getPublishBriefById(ZhiFanIdType id)const;
private:
	Factory();
	~Factory();
public:
	UserEntity *userEntityInfo = 0;
	unordered_map<ZhiFanIdType, PublishOneEntity*> *publishInDetail;	//֪�����ݣ���ϸ��
	unordered_map<ZhiFanIdType, PublishBriefOneEntity*> *publishBrief;	//֪�����ݣ���Ҫ��
};
#endif // Factory_H__
