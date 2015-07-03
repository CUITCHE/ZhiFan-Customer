#include "stdafx.h"
#include "DisplayZhiFanBoard.h"
#include "ZhiFanBriefFrame.h"
#include "DisplayBoardItemsForColumn.h"
#include "DetailedBoard.h"
#include "PublishBriefOneEntity.h"
#include "PublishOneEntity.h"

const int itemWidth = 300;
const int itemHeight = 500;
const int hspace = 30;
const int vspace = 50;

struct DisplayZhiFanBoardPrivate
{
	QList<ZhiFanBriefFrame *> *frameList;

	int curParseColumn = -1;	//当前Parse到几列
	int curParseRow = -1;
	int maxColumnNum = 0;
	QScrollArea *scrollArea;
	QWidget *board;
	~DisplayZhiFanBoardPrivate(){
		for (auto &val : *frameList){
			delete val;
		}
		delete frameList;
		delete board;
		delete scrollArea;
	}

};

DisplayZhiFanBoard::DisplayZhiFanBoard(QWidget *parent /*= 0*/, int columns /*= 4*/)
	: QWidget(parent)
	, d_ptr(new DisplayZhiFanBoardPrivate)
{
	initColumnWidget(columns);
}

DisplayZhiFanBoard::~DisplayZhiFanBoard()
{
	delete d_ptr;
}

void DisplayZhiFanBoard::initColumnWidget(int columns)
{
	Q_D(DisplayZhiFanBoard);
	d->maxColumnNum = columns > 4 ? 4 : columns;
	//设置滚动条
	d->board = new QWidget(this);
	d->scrollArea = new QScrollArea(this);
	d->scrollArea->setWidget(d->board);
	//
	d->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	d->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	connect(d->scrollArea->verticalScrollBar(), &QScrollBar::valueChanged, this, &DisplayZhiFanBoard::onScrollValueChanged);
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
	frame->setFixedSize(itemWidth, itemHeight);
	frame->initWidget();
	connect(frame, &ZhiFanBriefFrame::havealook, this, &DisplayZhiFanBoard::onBriefBordClicked);
	frame->show();
	
	d->frameList->push_back(frame);

	if (d->curParseRow == 0){
		int xpos = (itemWidth + hspace) * d->curParseColumn+20;
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

void DisplayZhiFanBoard::onScrollValueChanged(int changed)
{
	Q_D(DisplayZhiFanBoard);
	qDebug() << d->scrollArea->verticalScrollBar()->value();
	qDebug() << "知返size：" << d->frameList->first()->size();
}

void DisplayZhiFanBoard::onBriefBordClicked(const PublishBriefOneEntity *eb)
{
	DetailedBoard *widget = new DetailedBoard(eb, 0,this);
	widget->show();
}

