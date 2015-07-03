#include "stdafx.h"
#include "ImageBoard.h"
#include "ThumbnailBoard.h"

struct ImageBoardPrivate
{
	QVector<QPixmap> *fullImage;	//完整的图片数据
	QLabel *mainLabel;			//主要显示区
	ThumbnailBoard *thumbnailBoard;	//缩略图显示区
	~ImageBoardPrivate(){
		delete mainLayout;
		delete fullImage;
	}
	QVBoxLayout * mainLayout;
};
ImageBoard::ImageBoard(QList<QPixmap> &images, QWidget *parent /*= 0*/)
	: QWidget(parent)
	, d_ptr(new ImageBoardPrivate)
{
	initWidget(images);
}

ImageBoard::~ImageBoard()
{
	delete d_ptr;
}

void ImageBoard::initWidget(QList<QPixmap> &images)
{
	Q_D(ImageBoard);
	d->mainLayout = new QVBoxLayout(this);

	d->fullImage = new QVector < QPixmap >;
	*d->fullImage = QVector<QPixmap>::fromList(images);

	d->mainLabel = new QLabel;
	d->mainLabel->setFixedSize(200, 300);
	d->mainLabel->setPixmap(d->fullImage->first().scaled(200,300));

	{
		QList<QPixmap> mapList;
		for (auto &val : images){
			mapList.push_back(val.scaled({ 80, 80 }));
		}
		d->thumbnailBoard = new ThumbnailBoard(mapList);
		connect(d->thumbnailBoard, &ThumbnailBoard::clicked, this, &ImageBoard::onThumbnailBoardClicked);
	}
	d->mainLayout->setMargin(0);
	d->mainLayout->addWidget(d->mainLabel,Qt::AlignLeft);
	d->mainLayout->addWidget(d->thumbnailBoard);

	this->setLayout(d->mainLayout);
}

void ImageBoard::onThumbnailBoardClicked(int tag)
{
	Q_D(ImageBoard);
	if (tag < 0 && tag >= d->fullImage->size()){
		qWarning("index of Image of ImageBoard tag is out of range!");
		return;
	}
	QSize size{ this->width(), (int)(this->height()*0.7) };
	d->mainLabel->setFixedSize(size);
	d->mainLabel->setPixmap(d->fullImage->at(tag).scaled(size));
}

void ImageBoard::resizeEvent(QResizeEvent *event)
{
	Q_D(ImageBoard);
	
	QSize size{ event->size().width(), (int)(event->size().height()*0.7) };
	d->mainLabel->setFixedSize(size);
	d->mainLabel->setPixmap(d->fullImage->at(0).scaled(size));
}
