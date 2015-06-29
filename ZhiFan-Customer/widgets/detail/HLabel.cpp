#include "stdafx.h"
#include "HLabel.h"

HLabel::HLabel(QPixmap &image, int tag /*= -1*/, QWidget *parent /*= NULL*/) 
	:QLabel(parent)
	, tag(tag)
{
	this->setPixmap(image);
}

HLabel::~HLabel()
{

}

void HLabel::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		emit clicked(tag);
	}
	e->accept();
}