#include "stdafx.h"
#include "PublishOneEntity.h"
#include "ZhiFanPublishOne.h"

void PublishOneEntity::update_impl(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishOnePacket*>(pck);
	Q_ASSERT(p);
	__lock__;
	_publishId = p->getPublishId();
	_ownerId = p->getOwnerId();
	_publishdate = p->getPublishdate();
	_lostType = p->getLostType();
	_contactPlaceCode = p->getContactPlaceCode();
	_lostDate = p->getLostDate();
	_lostPlaceCodep = p->getLostPlaceCodep();
	_lostPlaceCodec = p->getLostPlaceCodec();
	_lostPlaceCoded = p->getLostPlaceCoded();
	_lostPlacedetail = p->getLostPlacedetail();
	_bills = p->getBills();
}