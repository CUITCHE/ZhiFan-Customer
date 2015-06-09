#ifndef ResponseGetZhiFanPublishPageOfRange_H__
#define ResponseGetZhiFanPublishPageOfRange_H__

/*!
 * \file ResponseGetZhiFanPublishPageOfRange.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * For����ȡ֪���������ݣ���Ҫ����GetZhiFanPublishPageOfRange��ResponseGetZhiFanPublishPageOfRange
 */

#include "ZhiFanPublishBriefOne.h"
#include "Range.h"

Q_DECLARE_METATYPE(QList<ZhiFanPublishBriefOnePacket>);
PACKET_DEFINITION_BEGIN(ResponseGetZhiFanPublishPageOfRange)
Q_OBJECT
PACKET_STRUCTION(ResponseGetZhiFanPublishPageOfRange)

//publishList��list< ZhiFanPublishOne >��С�ڵ��� Range
QT_MOC_MINE_DEFINITION(QList<ZhiFanPublishBriefOnePacket>, publishList, PublishList);
//range��Range����Χֵ
QT_MOC_MINE_DEFINITION(Range, range, Range);
//hasNext��bool�����к�������
QT_MOC_MINE_DEFINITION(bool, hasNext, HasNext);

PACKET_DEFINITION_END

#endif // ResponseGetZhiFanPublishPageOfRange_H__
