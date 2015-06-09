#ifndef CompleteZhiFan_H__
#define CompleteZhiFan_H__

/*!
 * \file CompleteZhiFan.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ���֪��
 */

#include "Packet.h"
/*
publish��int��ĳ��֪���ķ���id
targeted��string�����������û�id���Զ��Ÿ���
type��int����ʲô��ʽ��ɡ�0�ش�1ë���Լ�
bills��int�����ͻ���
*/
PACKET_DEFINITION_BEGIN(CompleteZhiFan)
Q_OBJECT
PACKET_STRUCTION(CompleteZhiFan)
//publish��int��ĳ��֪���ķ���id
QT_MOC_MINE_DEFINITION(int, publish, Publish);
//targeted��string�����������û�id���Զ��Ÿ���
QT_MOC_MINE_DEFINITION(QString, targeted, Targeted);
//type��int����ʲô��ʽ��ɡ�0�ش�1ë���Լ�
QT_MOC_MINE_DEFINITION(int, type, Type);
//bills��int�����ͻ���
QT_MOC_MINE_DEFINITION(int, bills, Bills);
PACKET_DEFINITION_END
#endif // CompleteZhiFan_H__
