#ifndef PullUserCenter_H__
#define PullUserCenter_H__

/*!
 * \file PullUserCenter.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ������ȡ�û���������
 */

#include "Packet.h"
/*
userid��int���û�id
type��int��0��ͨϵͳ��Ϣ���ͣ�1����ע��֪�����µĻش�2���Ļش����µ����ۣ�3�����۵Ļش����µ�����
*/
PACKET_DEFINITION_BEGIN(PullUserCenter)
Q_OBJECT
PACKET_STRUCTION(PullUserCenter)
//userid��int���û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//type��int��0��ͨϵͳ��Ϣ���ͣ�1����ע��֪�����µĻش�2���Ļش����µ����ۣ�3�����۵Ļش����µ�����
QT_MOC_MINE_DEFINITION(int, type, Type);

PACKET_DEFINITION_END
#endif // PullUserCenter_H__
