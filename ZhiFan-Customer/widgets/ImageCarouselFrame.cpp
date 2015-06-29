#include "stdafx.h"
#include "ImageCarouselFrame.h"
static auto once = [](){
	QTime t = QTime::currentTime();
	qsrand(t.msec() + t.second() * 1000);
	return true;
}();
ImageCarouselFrame::ImageCarouselFrame(const QVector<QImage> &imageData, QWidget *parent)
	:QWidget(parent)
	, labels(new QVector<QLabel *>)
	, labelSize(200, 300)
{
	//this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	setAttribute(Qt::WA_TranslucentBackground, true); //【1】
	setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的

	initWidget(imageData);
}

ImageCarouselFrame::~ImageCarouselFrame()
{
	timer->stop();
	animation->stop();
}

int timerInterval()
{
	return qrand() % 1500 + 2000;
}


void ImageCarouselFrame::initWidget(const QVector<QImage> &imageData)
{
	QLabel *p = 0;
	int i = 0;
	for (auto &val : imageData){
		p = new QLabel(this);
		p->setFixedSize(labelSize);
		p->hide();
		p->setPixmap(QPixmap::fromImage(val).scaled(labelSize));
		labels->push_back(p);
	}
	if (labels->size() > 1){
		timer = new QTimer(this);
		timer->start(timerInterval());
		connect(timer, &QTimer::timeout, this, &ImageCarouselFrame::onTimerSwitchImage);

#define __duration (1 * 800)
		animation = new QPropertyAnimation(labels->at(0), "geometry");
		animation->setDuration(__duration);
		connect(animation, &QPropertyAnimation::finished, this, &ImageCarouselFrame::onAnimationFinished);
#undef __duration
	}
	labels->first()->show();
}

void ImageCarouselFrame::onTimerSwitchImage()
{
	index = ++index % (labels->size());
	
	animation->stop();
	startAnimation();
	if (index == 0){
		labels->at(labels->size() - 1)->hide();
	}
	labels->at(index)->show();
}

void ImageCarouselFrame::startAnimation()
{
	static char increament = -1;
	increament = ++increament % 4;
	animation->setTargetObject(labels->at(index));
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
	animation->start();
}

void ImageCarouselFrame::fromTopToBottom()
{
	animation->setStartValue(QRect({ 0, -labelSize.height() }, labelSize));
	animation->setEndValue(QRect({ 0, 0 }, labelSize));
	animation->setEasingCurve(QEasingCurve::OutBounce);
}

void ImageCarouselFrame::fromBottomToTop()
{
	animation->setStartValue(QRect({ 0, labelSize.height() * 2 }, labelSize));
	animation->setEndValue(QRect({ 0, 0 }, labelSize));
	animation->setEasingCurve(QEasingCurve::OutQuad);
}

void ImageCarouselFrame::fromLeftToRight()
{
	animation->setStartValue(QRect({ -labelSize.width(), 0 }, labelSize));
	animation->setEndValue(QRect({ 0, 0 }, labelSize));
	animation->setEasingCurve(QEasingCurve::InOutBack);
}

void ImageCarouselFrame::fromRightToLeft()
{
	animation->setStartValue(QRect({ labelSize.width() * 2, 0 }, labelSize));
	animation->setEndValue(QRect({ 0, 0 }, labelSize));
	animation->setEasingCurve(QEasingCurve::OutInBack);
}

void ImageCarouselFrame::onAnimationFinished()
{
	for (int i = 0; i < labels->size();++i){
		if (i != index){
			labels->at(i)->hide();
		}
	}
}

void ImageCarouselFrame::resizeEvent(QResizeEvent *event)
{
	auto size = event->size();
	labelSize = size;
	this->setFixedSize(size);
	auto &datas = *labels;
	for (auto &val : datas){
		val->setFixedSize(size);
	}
}

void ImageCarouselFrame::setTimerOn(bool on /*= true*/)
{
	if (on && !timer->isActive()){
		timer->stop();
	}
	else{
		timer->start(timerInterval());
	}
}
