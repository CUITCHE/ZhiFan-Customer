#ifndef USERDATA_H
#define USERDATA_H
/*!
 * \file UserData.h
 *
 * \author CHE
 * \date 七月 2015
 *
 * 用于JS调用
 */
#include <QObject>

class UserData : public QObject
{
	Q_OBJECT

public:
	UserData(QObject *parent = 0);
	~UserData();
public slots:
	QString userAccount();
	QString pwd();
public:
	QString account;
	QString _pwd;
};

#endif // USERDATA_H
