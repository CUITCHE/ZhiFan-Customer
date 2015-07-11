#ifndef NETWORK_H
#define NETWORK_H
/*!
 * \file Network.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 客户端 底层socket封装。
 * 借用Qt的QTcpSocket
 * 完成客户端 底层数据的接收，发送
 * 将接收到的数据，转交给其它层：即NetworkDataWorker
 *
 * signal:	socketDisconnect：当socket失去与服务器的连接时，会发出此信号
 */
#include <QObject>
#include <memory>
using std::unique_ptr;
class QTcpSocket;
class Network : public QObject
{
	Q_OBJECT

public:
	Network(const QString& ip, quint16 port, QObject *parent = 0);
	~Network();

	//连接网络，当本类实例创建时，会自动调用此函数
	void socketConnect();

	//主动断开网络
	void socketDisConnect();

	//发送数据
	bool send(const QByteArray &data);
signals:
	void socketDisconnect();
	void pengdingdata(const QByteArray &data);
protected slots:
	//槽函数，读取socket缓冲区的数据
	void onReadyRead();

	//断开连接
	void onDisconnected();
private:
	unique_ptr<QTcpSocket> m_socket;
	QString m_ip;
	quint16 m_port;
};

#endif // NETWORK_H
