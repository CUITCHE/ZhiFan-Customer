#include "stdafx.h"
#include "NetworkDataWorker.h"
#include "Network.h"
#include "packets.h"
#include "InstantiationPacketHelper.h"
#include "Error.h"
NetworkDataWorker::NetworkDataWorker(QObject *parent)
	: QObject(parent)
{
	init();
}

NetworkDataWorker::~NetworkDataWorker()
{

}

void NetworkDataWorker::init()
{
	auto ins = getInstance(SettingHelper);
	worker = new Network(ins->getValue("ip").toString(), ins->getValue("port").toInt(), this);
	connect(worker, &Network::pengdingdata, this, &NetworkDataWorker::workForNetdata);
}

void NetworkDataWorker::workForNetdata(const QByteArray& data)
{
	static QJsonParseError error;;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(data, &error);
	if (error.error != QJsonParseError::NoError){
		qDebug() << "JSON parse error in" << __FUNCSIG__;
		qDebug() << "data of recieving is :" << data;
		return;
	}
	auto datamap = jsonDocument.toVariant().toMap();
	int protocol = Packet::Protocol(datamap);
	auto packet = net::get(protocol);
	packet->write(datamap);

	this->task(packet);
}

void NetworkDataWorker::sendRequest(const Packet *packet)
{
	auto json = packet->toJson();
	worker->send(json);
}

void NetworkDataWorker::task(const Packet *packet)
{
	int protocol = packet->getProtocol();
	NetCommunicationProtocol safetyProtocol = net::protocol_cast(protocol);
	if (safetyProtocol == Empty){
		return;
	}
	
}

void NetworkDataWorker::onServerBack(const Packet *packet)
{
	auto pck = dynamic_cast<const ServerBackPacket*>(packet);
}

void NetworkDataWorker::onResponseGetOneZhiFanPublish(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseGetOneZhiFanPublishPacket*>(packet);

}

void NetworkDataWorker::onResponseGetZhiFanPublishPageOfRange(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseGetZhiFanPublishPageOfRangePacket*>(packet);
}

void NetworkDataWorker::onResponseLogin(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseLoginPacket*>(packet);
}

void NetworkDataWorker::onResponsePullUserCenter(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponsePullUserCenterPacket*>(packet);
}

void NetworkDataWorker::onResponseSearchZhiFan(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseSearchZhiFanPacket*>(packet);
}
