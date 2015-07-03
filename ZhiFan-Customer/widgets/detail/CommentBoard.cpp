#include "stdafx.h"
#include "CommentBoard.h"
#include "CommentBoardItem.h"

struct CommentBoardPrivate
{
	QListWidget *commentListWidget;		//�ش��list widget
	QPushButton *previousPageBtn;		//��һҳ��ť
	QPushButton *nextPageBtn;			//��һҳ��ť
	CommentBoardPrivate()
		:commentListWidget(new QListWidget)
		, previousPageBtn(new QPushButton(QObject::tr("��һҳ")))
		, nextPageBtn(new QPushButton(QObject::tr("��һҳ")))
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
	//d->previousPageBtn = new QPushButton(tr("��һҳ"));
	d->previousPageBtn->setEnabled(false);
	//d->nextPageBtn = new QPushButton(tr("��һҳ"));
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
