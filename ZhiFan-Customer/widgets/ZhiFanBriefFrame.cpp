#include "stdafx.h"
#include "ZhiFanBriefFrame.h"
#include "PublishBriefOneEntity.h"
#include "ImageCarouselFrame.h"
#include "MaskFrame.h"
#include "Utils.h"
ZhiFanBriefFrame::ZhiFanBriefFrame(const PublishBriefOneEntity *entity, QWidget *parent /*= 0*/)
	:entity(entity)
	, QWidget(parent)
	, mainLayout(new QVBoxLayout)
{
	parseImageData();
	initWidget();
}

ZhiFanBriefFrame::~ZhiFanBriefFrame()
{

}

void ZhiFanBriefFrame::initWidget()
{
	//row1
	QHBoxLayout *row1 = new QHBoxLayout;
	publisherHeaderImage = new QLabel;
	publisherName = new QLabel(tr("ºÎÏÈÉú"));
	responseNum = new QLabel(tr("%1").arg(5320));
	row1->addWidget(publisherHeaderImage);
	row1->addWidget(publisherName);
	row1->addWidget(responseNum);

	//row2
	QHBoxLayout *row2 = new QHBoxLayout;
	imageShow = new ImageCarouselFrame(imageData, this);
	imageShow->setFixedSize(200, 300);
	row2->addWidget(imageShow);

	//row3
	QHBoxLayout *row3 = new QHBoxLayout;
	describeMsg = new QLabel;
	describeMsg->setText(entity->briefDesc());
	row3->addWidget(describeMsg);

	//row4
	QHBoxLayout *row4 = new QHBoxLayout;
	responseMuchOfAppluad = new QLabel;
	responseMuchOfAppluad->setText(entity->responseInfo());
	row4->addWidget(responseMuchOfAppluad);

	mainLayout->addLayout(row1);
	mainLayout->addLayout(row2);
	mainLayout->addLayout(row3);
	mainLayout->addLayout(row4);

	this->setLayout(mainLayout.get());
	mainLayout->setMargin(0);

	maskFrame = new MaskFrame(this);
	connect(maskFrame, &MaskFrame::tryToLook, this, &ZhiFanBriefFrame::onImageLookDetailed);
	maskFrame->hide();
}

void ZhiFanBriefFrame::parseImageData()
{
	auto &imageBase64Data = entity->photo();
	imageData.reserve(imageBase64Data.size());
	QByteArray tmpData;
	QImage image;
	for (auto &val : imageBase64Data){
		tmpData = val.toByteArray();
		utils::ByteArrayToImage(tmpData, image);
		imageData.push_back(image);
	}
}

#define __duration (1 * 500)
void ZhiFanBriefFrame::enterEvent(QEvent *)
{
	if (animationShow == 0){

		animationShow = new QPropertyAnimation(maskFrame, "geometry");
		animationShow->setDuration(__duration);
		connect(animationShow, &QPropertyAnimation::finished, this, &ZhiFanBriefFrame::onAnimationShowFinished);
		animationShow->setStartValue(QRect({ maskFrame->pos().x(), -maskFrame->size().height() }, maskFrame->size()));
		animationShow->setEndValue(QRect({ maskFrame->pos().x(), maskFrame->pos().y() }, maskFrame->size()));
		animationShow->setEasingCurve(QEasingCurve::InCubic);
	}
	animationShow->stop();
	animationHide ? animationHide->stop() : 0;

	maskFrame->showOne();
	animationShow->start();
}

void ZhiFanBriefFrame::leaveEvent(QEvent *)
{
	animationShow->stop();
	if (animationHide == 0){

		animationHide = new QPropertyAnimation(maskFrame, "geometry");
		animationHide->setDuration(__duration);
		connect(animationHide, &QPropertyAnimation::finished, this, &ZhiFanBriefFrame::onAnimationHideFinished);
		animationHide->setStartValue(QRect({ maskFrame->pos().x(), maskFrame->pos().y() }, maskFrame->size()));
		animationHide->setEndValue(QRect({ maskFrame->pos().x(), -maskFrame->size().height() }, maskFrame->size()));
		animationHide->setEasingCurve(QEasingCurve::OutCubic);
	}
	animationHide->stop();
	animationHide->start();
}
#undef __duration
void ZhiFanBriefFrame::onImageLookDetailed()
{
	emit havealook(entity->publishId());
}

void ZhiFanBriefFrame::onAnimationHideFinished()
{
	maskFrame->hide();
}

void ZhiFanBriefFrame::onAnimationShowFinished()
{
	maskFrame->showAll();
}

void ZhiFanBriefFrame::setImageCarouselState(bool on /*= true*/)
{
	imageShow->setTimerOn(on);
}

void ZhiFanBriefFrame::resizeEvent(QResizeEvent *event)
{
	maskFrame->setFixedSize(event->size());
}
