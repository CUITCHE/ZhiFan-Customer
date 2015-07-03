#include "stdafx.h"
#include "ThumbnailBoard.h"
#include "HLabel.h"
struct ThumbnailBoardPrivate
{
	QVector<HLabel*> *labels;
	~ThumbnailBoardPrivate(){
		for (auto &val : *labels){
			delete val;
		}
		delete labels;
		delete mainLayout;
	}
	QHBoxLayout * mainLayout;
};
ThumbnailBoard::ThumbnailBoard(QList<QPixmap> &ThumbnailImages, QWidget *parent /*= 0*/)
	: QWidget(parent)
	, d_ptr(new ThumbnailBoardPrivate)
{
	initWidget(ThumbnailImages);
}

ThumbnailBoard::~ThumbnailBoard()
{
	delete d_ptr;
}

void ThumbnailBoard::initWidget(QList<QPixmap> &thumbnailImages)
{
	Q_D(ThumbnailBoard);
	d->labels = new QVector < HLabel* > ;

	HLabel *label = 0;
	d->mainLayout = new QHBoxLayout(this);
	int index = -1;
	for (auto &val : thumbnailImages){
		label = new HLabel(val, ++index);
		label->setFixedSize(val.size());
		connect(label, &HLabel::clicked, this, &ThumbnailBoard::clicked);
		d->labels->push_back(label);
		d->mainLayout->addWidget(label);
	}
	this->setLayout(d->mainLayout);
}
