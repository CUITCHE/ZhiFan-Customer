#ifndef ZhiFanPublishOne_H__
#define ZhiFanPublishOne_H__

/*!
 * \file ZhiFanPublishOne.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ֪�����ݰ���ZhiFanPublishOne
 */

#include "Packet.h"
#include <QDateTime>
#include <QList>
/*
publishId��int��֪��������
ownerId��int��������id
publishdate��datetime����������
lostType��int��֪������
contactPlaceCode��string��64������ϵ�ص㣬ʧ������ݿ��ʡ�е���ֵ��ɣ��ɶ��Ÿ���
lostDate��date����Ʒ��ʧʱ��
lostPlaceCodep��int��ʡcode
lostPlaceCodec��int����code
lostPlaceCoded��int����code
lostPlacedetail��string��128������ϸ��ַ
bills��int�����ͻ���


*/
class ZhiFanPublishOnePacket;
Q_DECLARE_METATYPE(ZhiFanPublishOnePacket);
PACKET_DEFINITION_BEGIN(ZhiFanPublishOne)
Q_OBJECT
PACKET_STRUCTION(ZhiFanPublishOne)
operator QVariant()const{
	return QVariant::fromValue(*this);
}
//publishId��int��֪��������
QT_MOC_MINE_DEFINITION(int, publishId, PublishId);
//ownerId��int��������id
QT_MOC_MINE_DEFINITION(int, ownerId, OwnerId);

//publishdate��datetime����������
QT_MOC_MINE_DEFINITION(QDateTime, publishdate, Publishdate);

//lostType��int��֪������
QT_MOC_MINE_DEFINITION(int, lostType, LostType);
//contactPlaceCode��string��64������ϵ�ص㣬ʧ������ݿ��ʡ�е���ֵ��ɣ��ɶ��Ÿ���
QT_MOC_MINE_DEFINITION(QString, contactPlaceCode, ContactPlaceCode);
//lostDate��date����Ʒ��ʧʱ��
QT_MOC_MINE_DEFINITION(QDate, lostDate, LostDate);
//lostPlaceCodep��int��ʡcode
QT_MOC_MINE_DEFINITION(int, lostPlaceCodep, LostPlaceCodep);
//lostPlaceCodec��int����code
QT_MOC_MINE_DEFINITION(int, lostPlaceCodec, LostPlaceCodec);
//lostPlaceCoded��int����code
QT_MOC_MINE_DEFINITION(int, lostPlaceCoded, LostPlaceCoded);
//lostPlacedetail��string��128������ϸ��ַ
QT_MOC_MINE_DEFINITION(QString, lostPlacedetail, LostPlacedetail);
//bills��int�����ͻ���
QT_MOC_MINE_DEFINITION(int, bills, Bills);
PACKET_DEFINITION_END
#endif // ZhiFanPublishOne_H__
