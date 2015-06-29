#ifndef DISPLAYBOARDITEMSFORCOLUMN_H
#define DISPLAYBOARDITEMSFORCOLUMN_H
/*!
 * \file DisplayBoardItemsForColumn.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ����չʾ�� һ�е���ʾ��ʽ
 * Ĭ�ϵ�size = (200,400)
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
	//item size/space�ı䣬��Ҫ���²���item
	void itemDistributionChanged();
private:
	bool distribution = false;	//�Ƿ���Ҫ���²���
	list<QWidget *> *frameList;
	QSize itemSize;	//item�Ĵ�С
	int space = 10;	//item֮��ļ��
};

#endif // DISPLAYBOARDITEMSFORCOLUMN_H
