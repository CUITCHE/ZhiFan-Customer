#ifndef ServerBackPacket_H__
#define ServerBackPacket_H__

/********************************************************************
	created:	2015/03/19
	created:	19:3:2015   17:25
	file base:	ServerBackPacket
	author:		CHE
	
	purpose:	��������������ʾ���������
				Լ����result=0->�ɹ�������ֵ���ж���
*********************************************************************/
#include "Packet.h"

PACKET_DEFINITION_BEGIN(ServerBack)
Q_OBJECT
PACKET_STRUCTION(ServerBack)

QT_MOC_MINE_DEFINITION(int, Operator, Operator);
QT_MOC_MINE_DEFINITION(QString, msg, Msg);
QT_MOC_MINE_DEFINITION(int, status, Status);
PACKET_DEFINITION_END

#endif // ServerBackPacket_H__