#include "stdafx.h"
#include "Factory.h"
#include "UserEntity.h"
#include "UserCenterEntity.h"
#include "PublishOneEntity.h"
#include "PublishBriefOneEntity.h"
#include "packets.h"
using namespace std;
PREPARE_INSTANCE_DEFINITION(Factory)

Factory::Factory()
	:publishInDetail(new unordered_map<ZhiFanIdType, PublishOneEntity*>)
	, publishBrief(new unordered_map<ZhiFanIdType, PublishBriefOneEntity*>)
{

}

Factory::~Factory()
{

}

void Factory::addUserLoginInfo(const Packet *pck)
{
	if (userEntityInfo != 0){
		updateUserLoginInfo(pck);
		return;
	}
	userEntityInfo = new UserEntity;
	userEntityInfo->update(pck);
}

void Factory::updateUserLoginInfo(const Packet *pck)
{
	userEntityInfo->update(pck);
}

const UserEntity& Factory::getUserLoginInfo() const
{
	return *userEntityInfo;
}

void Factory::addPublishInDetail(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishOnePacket*>(pck);
	Q_ASSERT(p);
	auto iter = publishInDetail->find(p->getPublishId());
	if (iter != publishInDetail->end()){
		return;
	}
	PublishOneEntity *entity = new PublishOneEntity;
	entity->update(pck);
	publishInDetail->emplace(move(make_pair(p->getPublishId(), entity)));
}

void Factory::updatePublishInDetail(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishOnePacket*>(pck);
	Q_ASSERT(p);
	auto iter = publishInDetail->find(p->getPublishId());
	if (iter == publishInDetail->end()){
		return;
	}
	PublishOneEntity *entity = iter->second;
	entity->update(pck);
}

const PublishOneEntity* Factory::getPublishInDetailById(ZhiFanIdType id) const
{
	auto iter = publishInDetail->find(id);
	if (iter == publishInDetail->end()){
		return 0;
	}
	return iter->second;
}

void Factory::addPublishBrief(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishBriefOnePacket*>(pck);
	Q_ASSERT(p);
	auto iter = publishBrief->find(p->getPublishId());
	if (iter != publishBrief->end()){
		return;
	}
	PublishBriefOneEntity *entity = new PublishBriefOneEntity;
	entity->update(pck);
	publishBrief->emplace(move(make_pair(p->getPublishId(), entity)));
}

void Factory::updatePublishBrief(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishBriefOnePacket*>(pck);
	Q_ASSERT(p);
	auto iter = publishBrief->find(p->getPublishId());
	if (iter == publishBrief->end()){
		return;
	}
	PublishBriefOneEntity *entity = iter->second;
	entity->update(pck);
}

const PublishBriefOneEntity* Factory::getPublishBriefById(ZhiFanIdType id) const
{
	auto iter = publishBrief->find(id);
	if (iter == publishBrief->end()){
		return 0;
	}
	return iter->second;
}

