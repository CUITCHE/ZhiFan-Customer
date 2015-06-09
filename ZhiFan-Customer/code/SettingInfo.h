#ifndef SETTINGINFO_H
#define SETTINGINFO_H

#include "AbstractParseJson.h"

class SettingInfo : public AbstractParseJson
{
	Q_OBJECT
	//���ݿ�����
	QT_MOC_MINE_DEFINITION(QString, DBServerName, DBServerName);
	QT_MOC_MINE_DEFINITION(int, DBServerPort, DBServerPort);
	QT_MOC_MINE_DEFINITION(QString, DBDatabaseName, DBDatabaseName);
	QT_MOC_MINE_DEFINITION(QString, DBUserName, DBUserName);
	QT_MOC_MINE_DEFINITION(QString, DBPassword, DBPassword);
	QT_MOC_MINE_DEFINITION(QString, serverIp, ServerIp);
	QT_MOC_MINE_DEFINITION(int, serverPort, ServerPort);
// 	//������ip��ַ�Ͷ˿�����
// 	QT_MOC_MINE_DEFINITION(QString, serverIp, ServerIp);
// 	QT_MOC_MINE_DEFINITION(int, serverPort, ServerPort);
// 	//http����������֤��http������
// 	QT_MOC_MINE_DEFINITION(QString, httpServerIp, HttpServerIp);
// 	QT_MOC_MINE_DEFINITION(int, httpServerPort, HttpServerPort);
// 	QT_MOC_MINE_DEFINITION(QString, httpServerTail, HttpServerTail);
// 	//�ʼ�����������
// 	QT_MOC_MINE_DEFINITION(QString, mailServerAddress, MailServerAddress);
// 	QT_MOC_MINE_DEFINITION(QString, mailServerUsrName, MailServerUsrName);
// 	QT_MOC_MINE_DEFINITION(QString, mailServerUsrPassword, MailServerUsrPassword);
// 	QT_MOC_MINE_DEFINITION(QString, mailServerSubject, MailServerSubject);
// 	QT_MOC_MINE_DEFINITION(QString, mailServerContent, MailServerContent);
};

#endif // SETTINGINFO_H
