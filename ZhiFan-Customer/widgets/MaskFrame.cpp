#include "stdafx.h"
#include "MaskFrame.h"

MaskFrame::MaskFrame(QWidget *parent)
	: QWidget(parent)
{
	initWidget();
}

MaskFrame::~MaskFrame()
{
	delete lookOverBtn;
	delete maskLabel;
}

void MaskFrame::initWidget()
{
	maskLabel = new QLabel(this);
	maskLabel->setAutoFillBackground(true);
	QPalette pal;
	pal.setColor(QPalette::Background, QColor(0, 0, 0, 255 * 0.4));
	maskLabel->setPalette(pal);

	lookOverBtn = new QPushButton(tr("²é¿´"), this);
	QPalette pal2;
	pal2.setBrush(QPalette::Shadow, QColor(0,0,0,100));
	lookOverBtn->setPalette(pal2);
	lookOverBtn->setStyleSheet(
		"background:#3E97C5; "
		"border-radius:5px;"
		"border:2px solid #aaaaaa;"
		"height:30px;"
		"width:100px;"
		"color:white;"
		"font-size:18px;"
		"font-family:Î¢ÈíÑÅºÚ; "
		);
	connect(lookOverBtn, &QPushButton::clicked, this, &MaskFrame::onBtnClicked);
}

void MaskFrame::enterEvent(QEvent *event)
{
	//show();
}

void MaskFrame::leaveEvent(QEvent *event)
{
	//hide();
}

void MaskFrame::resizeEvent(QResizeEvent *event)
{
	auto size = event->size();
	maskLabel->setGeometry({ { 0, 0 }, size });
	lookOverBtn->move((size.width() - lookOverBtn->width()/2) / 2, (size.height() - lookOverBtn->height()/2) / 2);
}

void MaskFrame::onBtnClicked()
{
	emit tryToLook();
}

void MaskFrame::showOne()
{
	QWidget::show();
	lookOverBtn->hide();
}

void MaskFrame::showAll()
{
	QWidget::show();
	maskLabel->show();
	lookOverBtn->show();
}
