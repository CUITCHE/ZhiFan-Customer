#ifndef NETWORKDATAWORKER_H
#define NETWORKDATAWORKER_H
/*!
 * \file NetworkDataWorker.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 根据Network发来的数据，以客户端底层数据格式封装成相应的Packet类
 * 传递给TerminalWidget类去处理，并进行更下一步的传递
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
