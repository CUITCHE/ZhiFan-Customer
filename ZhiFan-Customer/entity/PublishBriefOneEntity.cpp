#include "stdafx.h"
#include "PublishBriefOneEntity.h"
#include "ZhiFanPublishBriefOne.h"

void PublishBriefOneEntity::update_impl(const Packet *pck)
{
	auto p = dynamic_cast<const ZhiFanPublishBriefOnePacket*>(pck);
	Q_ASSERT(!p);
	__lock__;
	_publishId = p->getPublishId();
	_ownerId = p->getOwnerId();
	_title = p->getTitle();
	_photo = p->getPhoto();
	_lightEyes = p->getLightEyes();
	_topTime = p->getTopTime();
	_briefDesc = p->getBriefDesc();
	_type = p->getType();
	_responseNum = p->getResponseNum();
	_responseInfo = p->getResponseInfo();
	_resposneApplaudNum = p->getResposneApplaudNum();
}