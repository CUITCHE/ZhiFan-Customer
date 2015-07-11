#include "stdafx.h"
#include "ImageCarouselFrame.h"

int timerInterval()
{
	static float s_rand[] = { 1.3f, 2.0f, 2.4f, 2.9f, 3.4f, 1.4f, 1.9f, 2.8f, 3.1, 1.8f, 4.1f, 5.0f, 4.2f, 2.5f, 1.0f };
	static int index = -1;
	index = ++index % (sizeof(s_rand) / sizeof(float));
	qDebug() << s_rand[index];
	return 1*1000 * s_rand[index];
}

struct ImageCarouselFramePrivate
{
	QVector<QLabel*> *labels=0;
	QTimer *timer=0;
	int index = 0;
	QPropertyAnimation *animation=0;
	int interval;
	static QSize labelSize;
	
	~ImageCarouselFramePrivate(){
		for (auto &val : *labels){
			delete val;
		}
		delete labels;
		delete timer;
		delete animation;
	}
};
QSize ImageCarouselFramePrivate::labelSize = { 300, 400 };

ImageCarouselFrame::ImageCarouselFrame(QWidget *parent)
	:QWidget(parent)
	, d_ptr(new ImageCarouselFramePrivate)
{
	//this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	//setAttribute(Qt::WA_TranslucentBackground, true); //【1】
	//setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的
}

ImageCarouselFrame::~ImageCarouselFrame()
{
	Q_D(ImageCarouselFrame);
	if (d->timer){
		d->timer->stop();
	}
	if (d->animation){
		d->animation->stop();
	}
	delete d_ptr;
}


void ImageCarouselFrame::initWidget(const QVector<QPixmap> *imageData)
{
	Q_D(ImageCarouselFrame);

	QLabel *p = 0;
	int i = 0;
	d->labels = new QVector < QLabel* > ;
	d->labels->reserve(imageData->size());
	for (auto &val : *imageData){
		p = new QLabel(this);
		p->setFixedSize(d->labelSize);
		p->hide();
		p->setPixmap(val.scaled(d->labelSize));
		d->labels->push_back(p);
	}
	if (d->labels->size() > 1){
		d->timer = new QTimer(this);
		d->interval = timerInterval();
		d->timer->start(d->interval);
		connect(d->timer, &QTimer::timeout, this, &ImageCarouselFrame::onTimerSwitchImage);

#define __duration (1 * 800)
		d->animation = new QPropertyAnimation(d->labels->at(0), "geometry");
		d->animation->setDuration(__duration);
		connect(d->animation, &QPropertyAnimation::finished, this, &ImageCarouselFrame::onAnimationFinished);
#undef __duration
	}
	d->labels->first()->show();
}

void ImageCarouselFrame::onTimerSwitchImage()
{
	Q_D(ImageCarouselFrame);

	d->index = ++d->index % (d->labels->size());
	
	d->animation->stop();
	startAnimation();
	if (d->index == 0){
		d->labels->at(d->labels->size() - 1)->hide();
	}
	d->labels->at(d->index)->show();
}

void ImageCarouselFrame::startAnimation()
{
	Q_D(ImageCarouselFrame);

	static char increament = -1;
	increament = ++increament % 4;
	d->animation->setTargetObject(d->labels->at(d->index));
	switch (increament)
	{
	case 0:
		fromTopToBottom();
		break;
	case 1:
		fromBottomToTop();
		break;
	case 2:
		fromLeftToRight();
		break;
	case 3:
		fromRightToLeft();
		break;
	}
	d->animation->start();
}

void ImageCarouselFrame::fromTopToBottom()
{
	Q_D(ImageCarouselFrame);

	d->animation->setStartValue(QRect({ 0, -d->labelSize.height() }, d->labelSize));
	d->animation->setEndValue(QRect({ 0, 0 }, d->labelSize));
	d->animation->setEasingCurve(QEasingCurve::OutBounce);
}

void ImageCarouselFrame::fromBottomToTop()
{
	Q_D(ImageCarouselFrame);
	d->animation->setStartValue(QRect({ 0, d->labelSize.height() * 2 }, d->labelSize));
	d->animation->setEndValue(QRect({ 0, 0 }, d->labelSize));
	d->animation->setEasingCurve(QEasingCurve::OutQuad);
}

void ImageCarouselFrame::fromLeftToRight()
{
	Q_D(ImageCarouselFrame);
	d->animation->setStartValue(QRect({ -d->labelSize.width(), 0 }, d->labelSize));
	d->animation->setEndValue(QRect({ 0, 0 }, d->labelSize));
	d->animation->setEasingCurve(QEasingCurve::InOutBack);
}

void ImageCarouselFrame::fromRightToLeft()
{
	Q_D(ImageCarouselFrame);
	d->animation->setStartValue(QRect({ d->labelSize.width() * 2, 0 }, d->labelSize));
	d->animation->setEndValue(QRect({ 0, 0 }, d->labelSize));
	d->animation->setEasingCurve(QEasingCurve::OutInBack);
}

void ImageCarouselFrame::onAnimationFinished()
{
	Q_D(ImageCarouselFrame);

	for (int i = 0; i < d->labels->size(); ++i){
		if (i != d->index){
			d->labels->at(i)->hide();
		}
	}
}
/*
void ImageCarouselFrame::resizeEvent(QResizeEvent *event)
{
	Q_D(ImageCarouselFrame);
	auto size = event->size();
	d->labelSize = size;
	this->setFixedSize(size);
	auto &datas = *d->labels;
	for (auto &val : datas){
		val->setFixedSize(size);
		//val->setPixmap(val->pixmap()->scaled(size));
	}
}*/

void ImageCarouselFrame::setTimerOn(bool on /*= true*/)
{
	Q_D(ImageCarouselFrame);

	if (on == true && d->timer->isActive() == true){
		d->timer->stop();
	}
	else if(on == false && d->timer->isActive() == false) {
		d->timer->start(d->interval);
	}
}

void ImageCarouselFrame::setFrameSize(const QSize &frameSize)
{
	ImageCarouselFramePrivate::labelSize = frameSize;
}
