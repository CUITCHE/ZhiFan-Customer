#include "stdafx.h"
#include "DisplayBoardItemsForColumn.h"

DisplayBoardItemsForColumn::DisplayBoardItemsForColumn(QWidget *parent)
	: QWidget(parent)
	, frameList(new list<QWidget *>)
	, itemSize(200,400)
{
}

DisplayBoardItemsForColumn::~DisplayBoardItemsForColumn()
{

}

void DisplayBoardItemsForColumn::addItem(QWidget *frame)
{
	frame->setFixedSize(itemSize);
	frame->setParent(this);
	if (frameList->empty() == true){
		frame->move(0, 0);
	}
	else{
		frame->move(0, (itemSize.height() + space) * frameList->size());
	}
	this->resize(itemSize.width(), frameList->size() * (itemSize.height() + space));
	frameList->push_back(frame);
}

void DisplayBoardItemsForColumn::addItems(list<QWidget *> &frames)
{
	for (auto frame : frames){
		addItem(frame);
	}
}

void DisplayBoardItemsForColumn::itemDistributionChanged()
{
	/*for (auto val : *frameList){
		val->setFixedSize(itemSize);
	}*/
}

void DisplayBoardItemsForColumn::setItemSize(const QSize &size)
{
	if (itemSize == size){
		return;
	}
	itemSize = size;
	distribution = true;
}

void DisplayBoardItemsForColumn::setItemSize(int width, int height)
{
	setItemSize({ width, height });
}

void DisplayBoardItemsForColumn::setItemSpace(int space /*= 10*/)
{
	if (space == this->space){
		return;
	}
	this->space = space;
	distribution = true;
}

void DisplayBoardItemsForColumn::show()
{
	if (distribution == true){
		itemDistributionChanged();
	}
	QWidget::show();

}

QSizePolicy DisplayBoardItemsForColumn::sizePolicy() const
{
	return QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
