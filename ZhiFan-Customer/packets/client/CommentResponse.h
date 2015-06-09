#ifndef CommentResponse_H__
#define CommentResponse_H__

/*!
 * \file CommentResponse.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ����һ���ش�
 */
#include "Packet.h"
/*responseid��int64���ش��id
userid��int���������û�id
referuser��int���ظ����û�id
context��string���û����۵ķ�������
*/
PACKET_DEFINITION_BEGIN(CommentResponse)
Q_OBJECT
PACKET_STRUCTION(CommentResponse)
//responseid��int64���ش��id
QT_MOC_MINE_DEFINITION(long long, responseid, Responseid);
//userid��int���������û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//referuser��int���ظ����û�id
QT_MOC_MINE_DEFINITION(int, referuser, Referuser);
//context��string���û����۵ķ�������
QT_MOC_MINE_DEFINITION(QString, context, Context);

PACKET_DEFINITION_END
#endif // CommentResponse_H__
