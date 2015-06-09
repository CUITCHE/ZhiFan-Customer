#ifndef TRANSACTION_H
#define TRANSACTION_H
/********************************************************************
	created:	2015/03/19
	created:	19:3:2015   11:51
	file base:	Transaction
	author:		CHE
	
	purpose:	事务处理类
				调用数据库接口，处理服务端与数据库
				处理服务端与客户端的事务逻辑交互。【implement】
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
	// Qualifier: 传入需要处理的Packet指针，进入事务流程，并对事务进行上锁
	// Parameter: Packet * pct 为下一个事务准备请求包内容
	// Parameter: QTcpSocket * sock 来自sock，请求了服务。
	//************************************
	void lock(Packet *pct, Error *e);

	//************************************
	// Method:    unlock
	// FullName:  Transaction::unlock
	// Access:    public 
	// Returns:   void
	// Qualifier: 解锁事务，可以进行下一个事务
	//************************************
	AnyPacket* unlock();

#pragma region 请求
	//************************************
	// Method:    Login
	// FullName:  Transaction::Login
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户登陆逻辑处理
	//************************************
	void Login();

	//************************************
	// Method:    Register
	// FullName:  Transaction::Register
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户注册
	//************************************
	void Register();

	
	//************************************
	// Method:    Identity
	// FullName:  Transaction::Identity
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户实名认证
	//************************************
	void Identity();

	//************************************
	// Method:    PublishZhiFan
	// FullName:  Transaction::PublishZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户发布知返
	//************************************
	void PublishZhiFan();

	//************************************
	// Method:    ResponseZhiFan
	// FullName:  Transaction::ResponseZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: 回答一个知返
	//************************************
	void ResponseZhiFan();

	//************************************
	// Method:    CommentResponse
	// FullName:  Transaction::CommentResponse
	// Access:    public 
	// Returns:   void
	// Qualifier: 评论一个回答
	//************************************
	void CommentResponse();
	
	//************************************
	// Method:    CompleteZhiFan
	// FullName:  Transaction::CompleteZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: 完成知返
	//************************************
	void CompleteZhiFan();

	//************************************
	// Method:    ApplaudZhiFan
	// FullName:  Transaction::ApplaudZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: 赞同或反对知返的一个回答
	//************************************
	void ApplaudZhiFan();

	//************************************
	// Method:    GetZhiFanPublishPageOfRange
	// FullName:  Transaction::GetZhiFanPublishPageOfRange
	// Access:    public 
	// Returns:   void
	// Qualifier: 获取知返发布内容（扼要）
	//************************************
	void GetZhiFanPublishPageOfRange();

	//************************************
	// Method:    GetOneZhiFanPublish
	// FullName:  Transaction::GetOneZhiFanPublish
	// Access:    public 
	// Returns:   void
	// Qualifier:获取知返发布内容（详细）
	//************************************
	void GetOneZhiFanPublish();

	//************************************
	// Method:    SearchZhiFan
	// FullName:  Transaction::SearchZhiFan
	// Access:    public 
	// Returns:   void
	// Qualifier: 搜索知返
	//************************************
	void SearchZhiFan();
#pragma endregion 请求
#pragma region 应答
	void onServerBack();
	void onResponseGetOneZhiFanPublish();
	void onResponseGetZhiFanPublishPageOfRange();
	void onResponseLogin();
	void onResponsePullUserCenter();
	void onResponseSearchZhiFan();
#pragma endregion

private:
	Packet *preparePacket;		//临时包
	QTcpSocket *remoteSocket;	//临时远程socket套接字
	AnyPacket waitPacket;		//返回给调用者
	Error *err;
	static unordered_map<NetCommunicationProtocol, FunctionType> transactionMap;
};

#endif // TRANSACTION_H
