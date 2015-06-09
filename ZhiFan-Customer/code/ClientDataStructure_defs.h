#ifndef ClientDataStructure_defs_H__
#define ClientDataStructure_defs_H__

/*!
 * \file ClientDataStructure_defs.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �ͻ��˵ײ����ݽṹ���崦
 * ���磺ʡ��+��+�����������ݰ�����
 */

#include <QPair>
#include "Range.h"
enum AreaCode:int{
	//ʡ��/ֱϽ��
	Province,
	//��/��
	City,
	//��/��
	District
};
using SearchPCD = QPair < AreaCode, QPair<int, QString> > ;
//�ж�num �Ƿ�����[left,right)��Χ
inline bool operator==(int num, const Range &range)
{
	return num >= range.getLeft() && num < range.getRight();
}
#endif // ClientDataStructure_defs_H__
