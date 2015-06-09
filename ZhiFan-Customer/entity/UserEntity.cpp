#include "stdafx.h"
#include "UserEntity.h"
#include "ResponseLogin.h"

void UserEntity::update_impl(const Packet *pck)
{
	auto p = dynamic_cast<const ResponseLoginPacket*>(pck);
	Q_ASSERT(!p);
	__lock__;
	_identification = p->getIdentification();
	_idCardSubstring = p->getIDCardSubstring().right(7);
	_zfb = p->getZfb();
	_userid = p->getUserid();
}

