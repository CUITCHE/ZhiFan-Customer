#ifndef GetOneZhiFanPublish_H__
#define GetOneZhiFanPublish_H__
/*!
 * \file GetOneZhiFanPublish.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��ȡ֪���������ݣ���ϸ��
 */

#include "Packet.h"
/*
userid��int���û�id
published��int��֪��id
*/
PACKET_DEFINITION_BEGIN(GetOneZhiFanPublish)
Q_OBJECT
PACKET_STRUCTION(GetOneZhiFanPublish)
//userid��int���û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//published��int��֪��id
QT_MOC_MINE_DEFINITION(int, publishid, Publishid);


PACKET_DEFINITION_END
#endif // GetOneZhiFanPublish_H__
