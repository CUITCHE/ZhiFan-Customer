#include "stdafx.h"
#include "Network.h"
#include <QTcpSocket>
#include <QHostAddress>
Network::Network(const QString& ip, quint16 port, QObject *parent)
	: QObject(parent)
	, m_socket(new QTcpSocket(this))
	, m_ip(ip)
	, m_port(port)
{
	socketConnect();
	connect(m_socket.get(), &QTcpSocket::readyRead, this, &Network::onReadyRead);
}

Network::~Network()
{

}

void Network::socketConnect()
{
	if (m_socket->state() != QAbstractSocket::UnconnectedState){
		return;
	}
	m_socket->connectToHost(QHostAddress(m_ip), m_port);
	int i = 0;
	while (!m_socket->waitForConnected(20)){
		qDebug() << "socket连接失败，正在重连…………" << "连接错误信息："
			<< m_socket->errorString();
		m_socket->connectToHost(QHostAddress(m_ip), m_port);
		if (++i > 20){
			qDebug() << "稍后将进行网络连接";
			break;
		}
	}

}

void Network::socketDisConnect()
{
	m_socket->abort();
}

bool Network::send(const QByteArray &data)
{
	socketConnect();
	if (m_socket->state() != QAbstractSocket::ConnectedState){
		return false;
	}
	m_socket->write(data);
	return true;
}

void Network::onReadyRead()
{
	auto data = m_socket->readAll();
	QList<QByteArray> dataList = data.split('}');
	for (auto &val : dataList){
		val.append('}');
		//将处理好的数据，交给其它层
		emit pengdingdata(val);
	}
	
}

void Network::onDisconnected()
{
	m_socket->abort();
	emit socketDisconnect();
}
