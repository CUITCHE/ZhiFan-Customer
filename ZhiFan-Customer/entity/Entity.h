#ifndef Entity_H__
#define Entity_H__

/*!
 * \file Entity.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ʵ����࣬
 * ������Ҫ��дupdate�����������û����update������ʵ���������������
 * isVaild�����Ը�������ѡ����д��
 */
#include "defs.h"
#include <QString>
#include <QDateTime>
#include <QMutex>
class Packet;
class Entity
{
public:
#define __lock__ Q_lock(mtx)
public:
	Entity();
	virtual ~Entity();

	void update(const Packet *pck);

	//��¼��ʵ������ʱ��
	ENTITY_MEMBER_DEFINITION(QTime, generatedTime);
protected:
	//��������д�������
	virtual void update_impl(const Packet *pck) = 0;

	//�������п��ƣ�ʵ�����ʱ�䣬Ĭ����15���ӹ���
	//If it needs not update, it will return true
	virtual bool isVaild(const QTime& other);

	//ÿ������ʵ�����ݵ�ʱ����Ҫ���ô˺���
	void updateTime();
protected:
	QMutex* mtx;
};

#define ENTITY_CLASS_DEFINITION_BEGIN(Class)\
	class Class: public Entity{\
	public:Class(){} ~##Class()override{}\
	void update_impl(const Packet *pck)override;
#define ENTITY_CLASS_DEFINITION_END };
#endif // Entity_H__
