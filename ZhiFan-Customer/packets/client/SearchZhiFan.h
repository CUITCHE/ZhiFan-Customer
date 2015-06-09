#ifndef SearchZhiFan_H__
#define SearchZhiFan_H__

/*!
 * \file SearchZhiFan.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ����֪��
 */

#include "Packet.h"
/*
userid��int���û�id
codep��int��ʡcode��Ϊ0��ʾnull����ͬ��
codec��int����code
coded��int����code
keyword��string�������ؼ��֣��������ո�
upperLimit��int�������� ]
lowerLimit��int�������� )

*/
PACKET_DEFINITION_BEGIN(SearchZhiFan)
Q_OBJECT
PACKET_STRUCTION(SearchZhiFan)

//userid��int���û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//codep��int��ʡcode��Ϊ0��ʾnull����ͬ��
QT_MOC_MINE_DEFINITION(int, codep, Codep);
//codec��int����code
QT_MOC_MINE_DEFINITION(int, codec, Codec);
//coded��int����code
QT_MOC_MINE_DEFINITION(int, coded, Coded);
//keyword��string�������ؼ��֣��������ո�
QT_MOC_MINE_DEFINITION(QString, keyword, Keyword);
//upperLimit��int�������� ]
QT_MOC_MINE_DEFINITION(int, upperLimit, UpperLimit);
//lowerLimit��int�������� )
QT_MOC_MINE_DEFINITION(int, lowerLimit, LowerLimit);


PACKET_DEFINITION_END
#endif // SearchZhiFan_H__
