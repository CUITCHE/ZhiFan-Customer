#ifndef ApplaudZhiFan_H__
#define ApplaudZhiFan_H__

/*!
 * \file ApplaudZhiFan.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��ͬ�򷴶�֪����һ���ش�
 */
#include "Packet.h"
/*
userid��int��˭�������ͬ�򷴶�
responseid��int64���ش��id
applaudoppose��bool��0��ͬ��1����

*/
PACKET_DEFINITION_BEGIN(ApplaudZhiFan)
Q_OBJECT
PACKET_STRUCTION(ApplaudZhiFan)
//userid��int��˭�������ͬ�򷴶�
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//responseid��int64���ش��id
QT_MOC_MINE_DEFINITION(long long, responseid, Responseid);
//applaudoppose��bool��0��ͬ��1����
QT_MOC_MINE_DEFINITION(bool, applaudoppose, Applaudoppose);

PACKET_DEFINITION_END
#endif // ApplaudZhiFan_H__
