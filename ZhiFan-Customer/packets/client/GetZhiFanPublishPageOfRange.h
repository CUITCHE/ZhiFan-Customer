#ifndef GetZhiFanPublishPageOfRange_H__
#define GetZhiFanPublishPageOfRange_H__

/*!
 * \file GetZhiFanPublishPageOfRange.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��ȡ֪���������ݣ���Ҫ����GetZhiFanPublishPageOfRange
 */


#include "Packet.h"
/*
userid��int���û�id
upperLimit��int�������� ]
lowerLimit��int�������� )

*/
PACKET_DEFINITION_BEGIN(GetZhiFanPublishPageOfRange)
Q_OBJECT
PACKET_STRUCTION(GetZhiFanPublishPageOfRange)
//userid��int���û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//upperLimit��int�������� ]
QT_MOC_MINE_DEFINITION(int, upperLimit, UpperLimit);
//lowerLimit��int�������� )
QT_MOC_MINE_DEFINITION(int, lowerLimit, LowerLimit);

PACKET_DEFINITION_END
#endif // GetZhiFanPublishPageOfRange_H__
