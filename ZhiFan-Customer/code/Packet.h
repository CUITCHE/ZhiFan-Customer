#ifndef PAKCET_H
#define PAKCET_H
/********************************************************************
	created:	2015/02/21
	created:	21:2:2015   15:36
	file base:	Packet
	author:		CHE
	
	purpose:	����Ļ����࣬��Ҫ�����������࣬��Ҫ�̳д���
				ͨ��wite() ������д�뵽���ݳ�Ա
				ͨ��read() ���������л���json
*********************************************************************/
#include "AbstractParseJson.h"
#include "NetCommunicationProtocol.h"
using namespace net;
class QVariant;
class Packet : public AbstractParseJson
{
	Q_OBJECT

	QT_MOC_MINE_DEFINITION(int, protocol, Protocol);
public:
	Packet(NetCommunicationProtocol _protocol = Empty, QObject *parent = 0);
	static int Protocol(const QVariantMap &json);
	virtual ~Packet();
};

#ifdef PACKET_STRUCTION
#undef PACKET_STRUCTION
#endif // PACKET_STRUCTION
#define PACKET_STRUCTION(ProrocolName) \
	public:\
	ProrocolName##Packet(NetCommunicationProtocol _protocol = net::ProrocolName):Packet(_protocol){}\
	~ProrocolName##Packet()override{}

#ifdef PACKET_DEFINITION_BEGIN
#undef PACKET_DEFINITION_BEGIN
#endif
#define PACKET_DEFINITION_BEGIN(ProrocolName)\
	class ProrocolName##Packet :public Packet {

#ifdef PACKET_DEFINITION_END
#undef PACKET_DEFINITION_END
#endif
#define PACKET_DEFINITION_END };
//��������Demo
/*
PACKET_DEFINITION_BEGIN(UserLogin)		;�û���½����������ʼ
Q_OBJECT								;�����Qt��ܵĶ�����Ϊ���ܵ��ú�ʵ��������������л����ؼ�
PACKET_STRUCTION(UserLogin)				;�û���¼���๹�캯����UserLogin��������������ռ�net��NetCommunicationProtocolö��ֵ

QT_MOC_MINE_DEFINITION(QString, mailAddress, MailAddress);		;������������������ǣ����ͣ���������get-set�����������QT_MOC_MINE_DEFINITION�Ķ��壩
QT_MOC_MINE_DEFINITION(QString, password, Password);

PACKET_DEFINITION_END					;�û���¼������������
*/
#endif // PAKCET_H
