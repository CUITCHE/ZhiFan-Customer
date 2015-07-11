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
	worker = new Network(ins->getValue("serverIp").toString(), ins->getValue("serverPort").toInt(), this);
	//关联信号-槽
	connect(worker, &Network::pengdingdata, this, &NetworkDataWorker::workForNetdata);
}

void NetworkDataWorker::workForNetdata(const QByteArray& data)
{
	static QJsonParseError error;
	QString str(data);
	//将传入data实例化成JSON格式的数据
	QJsonDocument jsonDocument = QJsonDocument::fromJson(data, &error);
	if (error.error != QJsonParseError::NoError){
		qDebug() << "JSON parse error in" << __FUNCSIG__;
		qDebug() << "data of recieving is :" << data;
		return;
	}
	//得到数据map
	QMap<QString,QVariant> datamap = jsonDocument.toVariant().toMap();
	int protocol = Packet::Protocol(datamap);
	
	Packet* packet = net::get(protocol);
	if (!packet){
		return;
	}

	packet->write(datamap);

	//将已经处理好的数据，发送到其它层，即：TerminalWidget
	emit packetData(packet);
	delete packet;
}

bool NetworkDataWorker::sendRequest(const Packet *packet)
{
	auto json = packet->toJson();
	return worker->send(json);
}