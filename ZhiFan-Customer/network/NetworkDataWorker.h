#ifndef NETWORKDATAWORKER_H
#define NETWORKDATAWORKER_H
/*!
 * \file NetworkDataWorker.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ����Network���������ݣ��Կͻ��˵ײ����ݸ�ʽ��װ����Ӧ��Packet��
 * ���ݸ�TerminalWidget��ȥ���������и���һ���Ĵ���
 */
#include <QObject>
#include <memory>
using std::unique_ptr;

class Network;
class Packet;

class NetworkDataWorker : public QObject
{
	Q_OBJECT

public:
	NetworkDataWorker(QObject *parent = 0);
	~NetworkDataWorker();
	bool sendRequest(const Packet *packet);
protected:
	void init();
signals:
	void packetData(const Packet *packet);
	/*
	void onServerBack(const Packet *packet);
	void onResponseGetOneZhiFanPublish(const Packet *packet);
	void onResponseGetZhiFanPublishPageOfRange(const Packet *packet);
	void onResponseLogin(const Packet *packet);
	void onResponsePullUserCenter(const Packet *packet);
	void onResponseSearchZhiFan(const Packet *packet);*/
protected slots:
	void workForNetdata(const QByteArray& data);
private:
	Network *worker;
};

#endif // NETWORKDATAWORKER_H
