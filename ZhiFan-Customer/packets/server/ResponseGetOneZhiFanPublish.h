#ifndef ResponseGetOneZhiFanPublish_H__
#define ResponseGetOneZhiFanPublish_H__

/*!
 * \file ResponseGetOneZhiFanPublish.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * For����ȡ֪������ϸ���ݣ���ϸ����GetOneZhiFanPublish��ResponseGetOneZhiFanPublish

 */
#include "ZhiFanPublishOne.h"

class ResponseGetOneZhiFanPublishPacket : public ZhiFanPublishOnePacket
{
	Q_OBJECT
public:
	ResponseGetOneZhiFanPublishPacket(){}
	~ResponseGetOneZhiFanPublishPacket()override{}
};

#endif // ResponseGetOneZhiFanPublish_H__
