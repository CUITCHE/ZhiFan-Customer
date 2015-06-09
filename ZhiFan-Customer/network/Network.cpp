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
	while (!m_socket->waitForConnected(200)){
		qDebug() << "socket连接失败，正在重连…………" << "连接错误信息："
			<< m_socket->errorString();
		m_socket->connectToHost(QHostAddress(m_ip), m_port);
	}

}

void Network::socketDisConnect()
{
	m_socket->abort();
}

void Network::send(const QByteArray &data)
{
	m_socket->write(data);
}

void Network::onReadyRead()
{
	auto data = m_socket->readAll();
	qDebug() << data;
	emit pengdingdata(data);
}

void Network::onDisconnected()
{
	m_socket->abort();
	emit socketDisconnect();
}
