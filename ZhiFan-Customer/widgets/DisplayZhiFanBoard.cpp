#include "stdafx.h"
#include "DisplayZhiFanBoard.h"
#include "ZhiFanBriefFrame.h"
#include "DisplayBoardItemsForColumn.h"


const int itemWidth = 200;
const int itemHeight = 400;
const int hspace = 10;
const int vspace = 10;

struct DisplayZhiFanBoardPrivate
{
	QList<ZhiFanBriefFrame *> *frameList;

	int curParseColumn = -1;	//当前Parse到几列
	int curParseRow = -1;
	int maxColumnNum = 0;
	QScrollArea *scrollArea;
	QWidget *board;

};

DisplayZhiFanBoard::DisplayZhiFanBoard(QWidget *parent /*= 0*/, int columns /*= 4*/)
	: QWidget(parent)
	, d_ptr(new DisplayZhiFanBoardPrivate)
{
	initColumnWidget(columns);
}

DisplayZhiFanBoard::~DisplayZhiFanBoard()
{
	
}

void DisplayZhiFanBoard::initColumnWidget(int columns)
{
	Q_D(DisplayZhiFanBoard);
	d->maxColumnNum = columns > 4 ? 4 : columns;
	//设置滚动条
	d->board = new QWidget(this);
	d->scrollArea = new QScrollArea(this);
	d->scrollArea->setWidget(d->board);
	//设置滚动条只能垂直滚动
	d->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	d->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	d->frameList = new QList < ZhiFanBriefFrame * > ;
	//先申请20个frame的预留空间备用
	d->frameList->reserve(20);
}

void DisplayZhiFanBoard::addItem(const PublishBriefOneEntity *entity)
{
	static QWidget* lastRowFrameForColumn[] = { 0, 0, 0, 0 };
	Q_D(DisplayZhiFanBoard);
	d->curParseColumn = ++d->curParseColumn % d->maxColumnNum;
	
	d->curParseRow = d->frameList->size() / d->maxColumnNum;

	ZhiFanBriefFrame * frame = new ZhiFanBriefFrame(entity, d->board);
	frame->show();
	frame->setFixedSize(itemWidth, itemHeight);
	d->frameList->push_back(frame);

	if (d->curParseRow == 0){
		int xpos = (itemWidth + hspace) * d->curParseColumn;
		d->curParseColumn % 2 ? frame->move(xpos, 0) : frame->move(xpos, 30);
		lastRowFrameForColumn[d->curParseColumn] = frame;
	}
	else{
		QWidget *widget = lastRowFrameForColumn[d->curParseColumn];
		frame->move(widget->x(), widget->y() + widget->height() + vspace);
		lastRowFrameForColumn[d->curParseColumn] = frame;
	}
	int tmpHeight = frame->y() + itemHeight;
	if (tmpHeight > d->board->height()){
		d->board->setFixedHeight(tmpHeight);
	}
}

void DisplayZhiFanBoard::addItems(const QList<PublishBriefOneEntity*> &entities)
{
	for (auto val : entities){
		addItem(val);
	}
}

void DisplayZhiFanBoard::resizeEvent(QResizeEvent *event)
{
	Q_D(DisplayZhiFanBoard);
	d->board->setFixedSize(event->size());
	d->scrollArea->setFixedSize(event->size());
}

