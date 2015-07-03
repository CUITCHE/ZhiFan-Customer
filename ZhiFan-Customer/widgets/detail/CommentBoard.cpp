#include "stdafx.h"
#include "CommentBoard.h"
#include "CommentBoardItem.h"

struct CommentBoardPrivate
{
	QListWidget *commentListWidget;		//回答的list widget
	QPushButton *previousPageBtn;		//上一页按钮
	QPushButton *nextPageBtn;			//下一页按钮
	CommentBoardPrivate()
		:commentListWidget(new QListWidget)
		, previousPageBtn(new QPushButton(QObject::tr("上一页")))
		, nextPageBtn(new QPushButton(QObject::tr("下一页")))
		, mainLayout(new QVBoxLayout)
	{}
	~CommentBoardPrivate(){
		delete mainLayout;
	}
	CommentBoardItem* lastOne = 0;
	QVBoxLayout *mainLayout;
};

CommentBoard::CommentBoard(QWidget *parent)
	: QWidget(parent)
	, d_ptr(new CommentBoardPrivate)
{
	initWidget();
}

CommentBoard::~CommentBoard()
{
	delete d_ptr;
}

void CommentBoard::initWidget()
{
	Q_D(CommentBoard);
	d->commentListWidget = new QListWidget;

	d->commentListWidget->setSelectionMode(QAbstractItemView::NoSelection);
	d->commentListWidget->setSpacing(5);
	QHBoxLayout *row2 = new QHBoxLayout;
	row2->setAlignment(Qt::AlignCenter);
	//d->previousPageBtn = new QPushButton(tr("上一页"));
	d->previousPageBtn->setEnabled(false);
	//d->nextPageBtn = new QPushButton(tr("下一页"));
	d->nextPageBtn->setEnabled(false);
	row2->addWidget(d->previousPageBtn);
	row2->addWidget(d->nextPageBtn);

	d->mainLayout->setAlignment(Qt::AlignLeft);
	d->mainLayout->addWidget(d->commentListWidget);
	d->mainLayout->addLayout(row2);

	this->setLayout(d->mainLayout);
}

void CommentBoard::addItem(const QString &text, const QString &responserName)
{
	Q_D(CommentBoard);
	
	QListWidgetItem *item = new QListWidgetItem;
	d->commentListWidget->addItem(item);

	CommentBoardItem *Item = new CommentBoardItem(d->commentListWidget);
	Item->setResponserName(responserName);
	Item->setCommentContext(text);
	Item->show();
	d->commentListWidget->setItemWidget(item, Item);
	
	item->setSizeHint({ Item->width(), Item->height() });
	if (d->lastOne){
		d->lastOne->setLine();
	}
	d->lastOne = Item;
}
