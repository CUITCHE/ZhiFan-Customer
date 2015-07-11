#include "stdafx.h"
#include "UserData.h"

UserData::UserData(QObject *parent)
	: QObject(parent)
{

}

UserData::~UserData()
{

}

QString UserData::userAccount()
{
	return account;
}

QString UserData::pwd()
{
	return _pwd;
}
