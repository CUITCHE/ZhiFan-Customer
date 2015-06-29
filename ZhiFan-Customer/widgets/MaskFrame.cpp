#include "stdafx.h"
#include "MaskFrame.h"

MaskFrame::MaskFrame(QWidget *parent)
	: QWidget(parent)
{
	initWidget();
}

MaskFrame::~MaskFrame()
{

}

void MaskFrame::initWidget()
{
	lookOverBtn = new QPushButton(tr("²é¿´"),this);
	connect(lookOverBtn, &QPushButton::clicked, this, &MaskFrame::onBtnClicked);

	maskLabel = new QLabel(this);
	maskLabel->setAutoFillBackground(true);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(0, 0, 0, 255 * 0.4));
	maskLabel->setPalette(pal);
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
	lookOverBtn->move((size.width() - lookOverBtn->width()/2) / 2, (size.height() - lookOverBtn->height()/2) / 2);
	maskLabel->setGeometry({ { 0, 0 }, size });
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
