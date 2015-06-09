#include "stdafx.h"
#include "Transaction.h"
#include "packets.h"
#include <QTcpSocket>
#include <QHostAddress>
#define TransMapGenerate(_protocol_) {net::_protocol_, &Transaction::_protocol_}
unordered_map<NetCommunicationProtocol, FunctionType> Transaction::transactionMap = {
	TransMapGenerate(Register),
	TransMapGenerate(Login),
	TransMapGenerate(Identity),
	TransMapGenerate(PublishZhiFan),
	TransMapGenerate(ResponseZhiFan),
	TransMapGenerate(CommentResponse),
	TransMapGenerate(CompleteZhiFan),
	TransMapGenerate(ApplaudZhiFan),
	TransMapGenerate(GetZhiFanPublishPageOfRange),
	TransMapGenerate(GetOneZhiFanPublish),
	TransMapGenerate(SearchZhiFan)
};
#undef TransMapGenerate
Transaction::Transaction(QObject *parent)
	: QObject(parent)
	, preparePacket(nullptr)
	, remoteSocket(nullptr)
{

}

Transaction::~Transaction()
{

}

unordered_map<NetCommunicationProtocol, FunctionType>& Transaction::getTransactionMap()
{
	return transactionMap;
}