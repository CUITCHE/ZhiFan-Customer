#ifndef Identity_H__
#define Identity_H__

/*!
 * \file Identity.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ʵ����֤
 */

#include "Packet.h"

PACKET_DEFINITION_BEGIN(Identity)
Q_OBJECT
PACKET_STRUCTION(Identity)

QT_MOC_MINE_DEFINITION(int, id, Id);
QT_MOC_MINE_DEFINITION(QString, mobile, Mobile);
//���֤�ţ��ͻ���Ҫ�����֤�ŵ�У��
QT_MOC_MINE_DEFINITION(QString, IDCard, IDCard);
//���֤�����Ӧ������
QT_MOC_MINE_DEFINITION(QString, actname, Actname);

PACKET_DEFINITION_END

#endif // Identity_H__
