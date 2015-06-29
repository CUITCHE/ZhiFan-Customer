#include "stdafx.h"
#include "ImageBoard.h"
#include "ThumbnailBoard.h"

struct ImageBoardPrivate
{
	QVector<QPixmap> *fullImage;	//完整的图片数据
	QLabel *mainLabel;			//主要显示区
	ThumbnailBoard *thumbnailBoard;	//缩略图显示区
};

ImageBoard::ImageBoard(QList<QPixmap> &images, QWidget *parent /*= 0*/)
	: QWidget(parent)
	, d_ptr(new ImageBoardPrivate)
{
	initWidget(images);
}

ImageBoard::~ImageBoard()
{

}

void ImageBoard::initWidget(QList<QPixmap> &images)
{
	QVBoxLayout * mainLayout = new QVBoxLayout(this);
	Q_D(ImageBoard);

	d->fullImage = new QVector < QPixmap >;
	*d->fullImage = QVector<QPixmap>::fromList(images);

	d->mainLabel = new QLabel;
	d->mainLabel->setPixmap(d->fullImage->first());

	{
		QList<QPixmap> mapList;
		for (auto &val : images){
			mapList.push_back(val.scaled({ 80, 80 }));
		}
		d->thumbnailBoard = new ThumbnailBoard(mapList);
		connect(d->thumbnailBoard, &ThumbnailBoard::clicked, this, &ImageBoard::onThumbnailBoardClicked);
	}
	mainLayout->addWidget(d->mainLabel);
	mainLayout->addWidget(d->thumbnailBoard);

	this->setLayout(mainLayout);
}

void ImageBoard::onThumbnailBoardClicked(int tag)
{
	Q_D(ImageBoard);
	if (tag < 0 && tag >= d->fullImage->size()){
		qWarning("index of Image of ImageBoard tag is out of range!");
		return;
	}
	d->mainLabel->setPixmap(d->fullImage->at(tag));
}
