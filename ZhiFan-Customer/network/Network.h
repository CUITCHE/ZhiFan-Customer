#ifndef NETWORK_H
#define NETWORK_H
/*!
 * \file Network.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �ͻ��� �ײ�socket��װ��
 * ����Qt��QTcpSocket
 * ��ɿͻ��� �ײ����ݵĽ��գ�����
 * �����յ������ݣ�ת���������㣺��NetworkDataWorker
 *
 * signal:	socketDisconnect����socketʧȥ�������������ʱ���ᷢ�����ź�
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

	//�������磬������ʵ������ʱ�����Զ����ô˺���
	void socketConnect();

	//�����Ͽ�����
	void socketDisConnect();

	//��������
	bool send(const QByteArray &data);
signals:
	void socketDisconnect();
	void pengdingdata(const QByteArray &data);
protected slots:
	//�ۺ�������ȡsocket������������
	void onReadyRead();

	//�Ͽ�����
	void onDisconnected();
private:
	unique_ptr<QTcpSocket> m_socket;
	QString m_ip;
	quint16 m_port;
};

#endif // NETWORK_H
