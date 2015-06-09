#ifndef SETTINGHELPER_H
#define SETTINGHELPER_H
/********************************************************************
	created:	2015/02/19
	created:	19:2:2015   13:38
	file base:	SettingHelper
	author:		CHE
	
	purpose:	�����ļ���ȡ������
*********************************************************************/
#include "SettingInfo.h"
class QFile;
class SettingHelper
{
	PREPARE_INSTANCE_DECLARE(SettingHelper)
public:
	QVariant getValue(const char *key);
	void setValue(const char *key, const QVariant &val);

	//�������ù���ֵ���ļ�
	void sync();

	//��ȡ���ö���
	const SettingInfo* getSettingInfo()const;
private:
	SettingHelper();
	~SettingHelper();

	//������Ҫ�����ݱ��浽����
	void maybeNeedFlush();
private:
	bool needFlush;
	QFile *fileCache;
	SettingInfo *dbinfoCache;		//�������û���
};

#endif // SETTINGHELPER_H
