#ifndef ResponsePullUserCenter_H__
#define ResponsePullUserCenter_H__

/*!
 * \file ResponsePullUserCenter.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * For��������ȡ�û��������ͣ�PullUserCenter��ResponsePullUserCenter
 */

#include "Packet.h"
/*
type��int��0��ͨϵͳ��Ϣ���ͣ�1����ע��֪�����µĻش�2���Ļش����µ����ۣ�3�����۵Ļش����µ�����
id��int64��0û��id������id
briefmsg��string����ϢժҪ��idΪ0ʱ������ϸ��Ϣ��

*/
PACKET_DEFINITION_BEGIN(ResponsePullUserCenter)
Q_OBJECT
PACKET_STRUCTION(ResponsePullUserCenter)
//type��int��0��ͨϵͳ��Ϣ���ͣ�1����ע��֪�����µĻش�2���Ļش����µ����ۣ�3�����۵Ļش����µ�����
QT_MOC_MINE_DEFINITION(int, type, Type);
//id��int64��0û��id������id
QT_MOC_MINE_DEFINITION(long long, id, Id);
//briefmsg��string����ϢժҪ��idΪ0ʱ������ϸ��Ϣ��
QT_MOC_MINE_DEFINITION(QString, briefmsg, Briefmsg);

PACKET_DEFINITION_END
#endif // ResponsePullUserCenter_H__
