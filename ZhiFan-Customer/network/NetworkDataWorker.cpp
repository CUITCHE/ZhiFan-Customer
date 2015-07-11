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
	//�����ź�-��
	connect(worker, &Network::pengdingdata, this, &NetworkDataWorker::workForNetdata);
}

void NetworkDataWorker::workForNetdata(const QByteArray& data)
{
	static QJsonParseError error;
	QString str(data);
	//������dataʵ������JSON��ʽ������
	QJsonDocument jsonDocument = QJsonDocument::fromJson(data, &error);
	if (error.error != QJsonParseError::NoError){
		qDebug() << "JSON parse error in" << __FUNCSIG__;
		qDebug() << "data of recieving is :" << data;
		return;
	}
	//�õ�����map
	QMap<QString,QVariant> datamap = jsonDocument.toVariant().toMap();
	int protocol = Packet::Protocol(datamap);
	
	Packet* packet = net::get(protocol);
	if (!packet){
		return;
	}

	packet->write(datamap);

	//���Ѿ�����õ����ݣ����͵������㣬����TerminalWidget
	emit packetData(packet);
	delete packet;
}

bool NetworkDataWorker::sendRequest(const Packet *packet)
{
	auto json = packet->toJson();
	return worker->send(json);
}