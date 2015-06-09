#ifndef ResponseZhiFan_H__
#define ResponseZhiFan_H__

/*!
 * \file ResponseZhiFan.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �ش�һ��֪��
 */

#include "Packet.h"
/*userid��int���ش���û�
publishid��int��ĳ��֪������id
context��string���û����������
*/
PACKET_DEFINITION_BEGIN(ResponseZhiFan)
Q_OBJECT
PACKET_STRUCTION(ResponseZhiFan)

QT_MOC_MINE_DEFINITION(int, userid, Userid);
QT_MOC_MINE_DEFINITION(int, publishid, Publishid);
QT_MOC_MINE_DEFINITION(QString, context, Context);

PACKET_DEFINITION_END
#endif // ResponseZhiFan_H__
