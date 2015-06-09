#ifndef ClientDataStructure_defs_H__
#define ClientDataStructure_defs_H__

/*!
 * \file ClientDataStructure_defs.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 客户端底层数据结构定义处
 * 比如：省份+市+区的整合数据包定义
 */

#include <QPair>
#include "Range.h"
enum AreaCode:int{
	//省份/直辖市
	Province,
	//市/区
	City,
	//县/村
	District
};
using SearchPCD = QPair < AreaCode, QPair<int, QString> > ;
//判断num 是否属于[left,right)范围
inline bool operator==(int num, const Range &range)
{
	return num >= range.getLeft() && num < range.getRight();
}
#endif // ClientDataStructure_defs_H__
