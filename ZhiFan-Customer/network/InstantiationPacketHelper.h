#ifndef INSTANTIATIONPACKETHELPER_H
#define INSTANTIATIONPACKETHELPER_H
/********************************************************************
	created:	2015/02/22
	created:	22:2:2015   14:45
	file base:	InstantiationPacketHelper
	author:		CHE
	
	purpose:	���ݿͻ�����������ݰ���������Ӧ��Pakcet��
*********************************************************************/

class Packet;
class InstantiationPacketHelper
{
public:
	InstantiationPacketHelper();
	~InstantiationPacketHelper();
	//ͨ��Э��ţ�������Ӧ��Packet���ָ�����
	static Packet* getPacketByProtocol(const int protocol);
};
namespace net{
	Packet* get(const int protocol);
}

#endif // INSTANTIATIONPACKETHELPER_H
