#include "stdafx.h"
#include "ThumbnailBoard.h"
#include "HLabel.h"
/*struct ThumbnailBoardPrivate
{
	QVector<HLabel*> *labels;
};*/
ThumbnailBoard::ThumbnailBoard(QList<QPixmap> &ThumbnailImages, QWidget *parent /*= 0*/)
	: QWidget(parent)
	//, d_ptr(new ThumbnailBoardPrivate)
{
	initWidget(ThumbnailImages);
}

ThumbnailBoard::~ThumbnailBoard()
{

}

void ThumbnailBoard::initWidget(QList<QPixmap> &thumbnailImages)
{
	//Q_D(ThumbnailBoard);
	//d->labels = new QVector < HLabel* > ;

	HLabel *label = 0;
	QHBoxLayout * mainLayout = new QHBoxLayout(this);
	int index = -1;
	for (auto &val : thumbnailImages){
		label = new HLabel(val, ++index);
		connect(label, &HLabel::clicked, this, &ThumbnailBoard::clicked);
		//d->labels->push_back(label);
		mainLayout->addWidget(label);
	}
	this->setLayout(mainLayout);
}
