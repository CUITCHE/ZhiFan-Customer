#ifndef TRANSACTION_H
#define TRANSACTION_H
/********************************************************************
	created:	2015/03/19
	created:	19:3:2015   11:51
	file base:	Transaction
	author:		CHE
	
	purpose:	��������
				�������ݿ�ӿڣ��������������ݿ�
				����������ͻ��˵������߼���������implement��
*********************************************************************/
#include "NetCommunicationProtocol.h"
#include <QObject>
#include <QMap>
#include <unordered_map>
using namespace net;

using std::unordered_map;
class Packet;
class QTcpSocket;
class NetLogicMainProcess;
class Error;
class Transaction;

typedef void(Transaction::*FunctionType)(void);
typedef QPair<NetCommunicationProtocol, Packet*> AnyPacket;

class Transaction : public QObject
{
	Q_OBJECT

public:
	Transaction(QObject *parent);
	~Transaction();
	unordered_map<NetCommunicationProtocol, FunctionType>& getTransactionMap();
	//************************************
	// Method:    lock
	// FullName:  Transaction::lock
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ҫ�����Packetָ�룬�����������̣����������������
	// Parameter: Packet * pct Ϊ��һ������׼�����������
	// Parameter: QTcpSocket * sock ����sock�������˷���
	//************************************
	void lock(Packet *pct, Error *e);

	//************************************
	// Method:    unlock
	// FullName:  Transaction::unlock
	// Access:    public 
	// Returns:   void
	// Qualifier: �������񣬿��Խ�����һ������
	//************************************
	AnyPacket* unlock();

#pragma region ����
	//************************************
	// Method:    Login
	// FullName:  Transaction::Login
	// Access:    public 
	// Returns:   void
	// Qualifier: �û���½�߼�����
	//************************************
	void Login();

	//************************************
	// Method:    Register
	// FullName:  Transaction::Register
	// Access:    public 
	// Returns:   void
	// Qualifier: �û�ע��
	//************************************
	void Register();

	
	//************************************
	// Method:    Identity
	// FullName:  Transaction::Identity
	// Access:    public 
	// Returns:   void
	// Qualifier: �û�ʵ����֤
	//************************************
	void Identity();

	//************************************
	// Method:    PublishZhiFan
	// FullName:  Transaction::PublishZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: �û�����֪��
	//************************************
	void PublishZhiFan();

	//************************************
	// Method:    ResponseZhiFan
	// FullName:  Transaction::ResponseZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: �ش�һ��֪��
	//************************************
	void ResponseZhiFan();

	//************************************
	// Method:    CommentResponse
	// FullName:  Transaction::CommentResponse
	// Access:    public 
	// Returns:   void
	// Qualifier: ����һ���ش�
	//************************************
	void CommentResponse();
	
	//************************************
	// Method:    CompleteZhiFan
	// FullName:  Transaction::CompleteZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: ���֪��
	//************************************
	void CompleteZhiFan();

	//************************************
	// Method:    ApplaudZhiFan
	// FullName:  Transaction::ApplaudZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ͬ�򷴶�֪����һ���ش�
	//************************************
	void ApplaudZhiFan();

	//************************************
	// Method:    GetZhiFanPublishPageOfRange
	// FullName:  Transaction::GetZhiFanPublishPageOfRange
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ȡ֪���������ݣ���Ҫ��
	//************************************
	void GetZhiFanPublishPageOfRange();

	//************************************
	// Method:    GetOneZhiFanPublish
	// FullName:  Transaction::GetOneZhiFanPublish
	// Access:    public 
	// Returns:   void
	// Qualifier:��ȡ֪���������ݣ���ϸ��
	//************************************
	void GetOneZhiFanPublish();

	//************************************
	// Method:    SearchZhiFan
	// FullName:  Transaction::SearchZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: ����֪��
	//************************************
	void SearchZhiFan();
#pragma endregion ����
#pragma region Ӧ��
	void onServerBack();
	void onResponseGetOneZhiFanPublish();
	void onResponseGetZhiFanPublishPageOfRange();
	void onResponseLogin();
	void onResponsePullUserCenter();
	void onResponseSearchZhiFan();
#pragma endregion

private:
	Packet *preparePacket;		//��ʱ��
	QTcpSocket *remoteSocket;	//��ʱԶ��socket�׽���
	AnyPacket waitPacket;		//���ظ�������
	Error *err;
	static unordered_map<NetCommunicationProtocol, FunctionType> transactionMap;
};

#endif // TRANSACTION_H
