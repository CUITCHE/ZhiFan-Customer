#include "stdafx.h"
#include "CommentBoardItem.h"

struct CommentBoardItemPrivate
{
	QTextEdit *text;			//回答的内容显示框
	QLabel *responserName;		//回答者姓名
	QPushButton *apprecoateBtn;	//感谢按钮
	QPushButton *appluadBtn;	//点赞按钮
	QPushButton *reportBtn;		//举报按钮

	~CommentBoardItemPrivate(){
		delete mainLayout;
	}
	QVBoxLayout *mainLayout;
	QFrame *line = 0;
};
CommentBoardItem::CommentBoardItem(QWidget *parent)
	: QWidget(parent)
	, d_ptr(new CommentBoardItemPrivate)
{
	initWidget();
	initStyle();
}

CommentBoardItem::~CommentBoardItem()
{
	delete d_ptr;
}

void CommentBoardItem::initWidget()
{
	Q_D(CommentBoardItem);
	d->text = new QTextEdit;
	d->text->setStyleSheet("border: 0px");
	d->text->setReadOnly(true);
	
	QHBoxLayout *row1 = new QHBoxLayout;
	row1->setMargin(0);
	d->responserName = new QLabel(tr("张三"));
	d->apprecoateBtn = new QPushButton(tr("感谢"));
	d->apprecoateBtn->setObjectName("apprecoateBtn");
	d->appluadBtn = new QPushButton(tr("赞"));
	d->appluadBtn->setObjectName("appluadBtn");
	d->reportBtn = new QPushButton(tr("举报"));
	d->reportBtn->setObjectName("reportBtn");
	row1->addWidget(d->responserName,0,Qt::AlignLeft);
	row1->addWidget(d->apprecoateBtn,0,Qt::AlignRight);
	row1->addSpacing(5);
	row1->addWidget(d->appluadBtn, 0, Qt::AlignRight);
	row1->addSpacing(5);
	row1->addWidget(d->reportBtn, 0, Qt::AlignRight);

	d->mainLayout = new QVBoxLayout(this);
	d->mainLayout->setMargin(0);
	d->mainLayout->addWidget(d->text);
	d->mainLayout->addLayout(row1);

	this->setLayout(d->mainLayout);
}

void CommentBoardItem::setResponserName(const QString &name)
{
	Q_D(CommentBoardItem);
	d->responserName->setText(name);
	int len = name.size() / 20;
	d->text->setFixedHeight(len ? len * 30 : 30);
}

void CommentBoardItem::setCommentContext(const QString &text)
{
	Q_D(CommentBoardItem);
	d->text->setText(text);
}

void CommentBoardItem::setLine()
{
	Q_D(CommentBoardItem);
	if (!d->line){
		d->line = new QFrame;
		d->line->setFrameShape(QFrame::HLine);
		QPalette pal;
		pal.setColor(QPalette::WindowText, QColor(0, 0, 0, 255 * 0.4));
		d->line->setPalette(pal);
		d->mainLayout->addWidget(d->line);
	}
}

void CommentBoardItem::initStyle()
{
	QFile file(":/zhifan.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}
