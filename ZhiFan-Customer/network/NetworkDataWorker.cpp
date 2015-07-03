#include "stdafx.h"
#include "NetworkDataWorker.h"
#include "Packet.h"
#include "Network.h"
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

	emit packetData(packet);
	delete packet;
}

void NetworkDataWorker::sendRequest(const Packet *packet)
{
	auto json = packet->toJson();
	worker->send(json);
}