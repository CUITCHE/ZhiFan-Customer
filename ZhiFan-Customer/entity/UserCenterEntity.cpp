#include "stdafx.h"
#include "UserCenterEntity.h"
#include "PullUserCenter.h"

void UserCenterEntity::update_impl(const Packet *pck)
{
	auto p = dynamic_cast<const PullUserCenterPacket*>(pck);
	Q_ASSERT(!p);
	__lock__;
	_type = p->getType();
	_id = p->getUserid();
	_briefmsg = p->getBriefmsg();
}