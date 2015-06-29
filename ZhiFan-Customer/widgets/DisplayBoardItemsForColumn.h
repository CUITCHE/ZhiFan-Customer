#ifndef DISPLAYBOARDITEMSFORCOLUMN_H
#define DISPLAYBOARDITEMSFORCOLUMN_H
/*!
 * \file DisplayBoardItemsForColumn.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 控制展示板 一列的显示方式
 * 默认的size = (200,400)
 */
#include "defs.h"
#include <QWidget>
#include <list>
using std::list;
class QVBoxLayout;

class DisplayBoardItemsForColumn : public QWidget
{
	Q_OBJECT

public:
	DisplayBoardItemsForColumn(QWidget *parent = 0);
	void addItem(QWidget *frame);
	void addItems(list<QWidget *> &frames);
	void setItemSize(const QSize &size);
	void setItemSize(int width, int height);
	void setItemSpace(int space = 10);
	void show();
	~DisplayBoardItemsForColumn();
	QSizePolicy sizePolicy()const;
protected:
	//item size/space改变，需要重新布置item
	void itemDistributionChanged();
private:
	bool distribution = false;	//是否需要重新布局
	list<QWidget *> *frameList;
	QSize itemSize;	//item的大小
	int space = 10;	//item之间的间隔
};

#endif // DISPLAYBOARDITEMSFORCOLUMN_H
