#include "stdafx.h"
#include "TerminalWidget.h"
#include "SearchWidget.h"
#include "DisplayZhiFanBoard.h"
#include "Utils.h"
TerminalWidget::TerminalWidget(const QSize &frame, QWidget *parent /*= 0*/)
	:QWidget(parent)
	, mainLayout(new QVBoxLayout)
{
	this->setFixedSize(frame);
	initWidget();
}

TerminalWidget::~TerminalWidget()
{

}

void TerminalWidget::initWidget()
{
	//row1
	QHBoxLayout *row1 = new QHBoxLayout;
	{
		QHBoxLayout *row = new QHBoxLayout;
		closeBtn = new QPushButton;
		closeBtn->setObjectName("closeBtn");
		extendBtn = new QPushButton;
		extendBtn->setObjectName("extendBtn");
		narrowBtn = new QPushButton;
		narrowBtn->setObjectName("narrowBtn");
		row->addWidget(closeBtn);
		row->addWidget(extendBtn);
		row->addWidget(narrowBtn);
		row1->addLayout(row);
	}
	logoLabel = new QLabel;
	logoLabel->setObjectName("logoLabel");
	row1->addWidget(logoLabel);

	showUserNameLabel = new QLabel;
	showUserNameLabel->setText(tr("�û���"));
	row1->addWidget(showUserNameLabel);

	userHeaderBtn = new QPushButton;
	userHeaderBtn->setObjectName("userHeaderBtn");
	row1->addWidget(userHeaderBtn);

	//row2
	QHBoxLayout *row2 = new QHBoxLayout;

	//row3
	QHBoxLayout *row3 = new QHBoxLayout;
	displayBoard = new DisplayZhiFanBoard(this);
	displayBoard->setFixedSize(this->width(), this->height()*0.7);
	row3->addWidget(displayBoard);

	//row4
	QHBoxLayout *row4 = new QHBoxLayout;
	searchFrame = new SearchWidget;
	row4->addWidget(searchFrame);

	mainLayout->addLayout(row1);
	mainLayout->addLayout(row2);
	mainLayout->addLayout(row3);
	mainLayout->addLayout(row4);

	this->setLayout(mainLayout.get());

	QTimer::singleShot(1000, [&](){displayBoard->addItems(utils::getdata()); });
}
