#include "stdafx.h"
#include "ZhiFanBriefFrame.h"
#include "PublishBriefOneEntity.h"
#include "ImageCarouselFrame.h"
#include "MaskFrame.h"
#include "Utils.h"

struct ZhiFanBriefFramePrivate
{
	QVector<QPixmap> *imageData = 0;
	MaskFrame *maskFrame;	//遮罩，有查看按钮
	QPropertyAnimation *animationShow = 0;
	QPropertyAnimation *animationHide = 0;

	//row1
	QLabel *flagZhiFan;	//标识是“知”，还是“返”
	QLabel *title;					//标题
	QLabel *responseNum;			//回答数
	//row2
	ImageCarouselFrame *imageShow;	//显示图片，一张图片
	//row3
	QLabel *describeMsg;	//描述的节约信息
	//row4
	QLabel *responseMuchOfAppluad;	//被点赞最多的回答，扼要信息

	QLabel *bg;

	QVBoxLayout * mainLayout;

	~ZhiFanBriefFramePrivate(){
		delete mainLayout;
		delete animationHide;
		delete animationShow;
	}
};

ZhiFanBriefFrame::ZhiFanBriefFrame(const PublishBriefOneEntity *entity, QWidget *parent /*= 0*/)
	:entity(entity)
	, QWidget(parent)
	, d_ptr(new ZhiFanBriefFramePrivate)
{
	parseImageData();
}

ZhiFanBriefFrame::~ZhiFanBriefFrame()
{
	delete d_ptr;
}
void ZhiFanBriefFrame::initStyle()
{
	QFile file(":/zhifan.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}
void ZhiFanBriefFrame::initWidget()
{
	Q_D(ZhiFanBriefFrame);
	//row1
	QHBoxLayout *row1 = new QHBoxLayout;
	row1->setAlignment(Qt::AlignBottom);
	d->flagZhiFan = new QLabel;
	d->flagZhiFan->setObjectName("flagZhiFan");
	d->flagZhiFan->setFixedSize(64, 64);
	QPixmap pixmap(entity->type() == 1 ? ":/zhi.png" : ":/fan.png");
	d->flagZhiFan->setPixmap(pixmap.scaled(64,64));

	d->title = new QLabel(entity->title());	//标题
	d->title->setObjectName("BriefFrameTitle");
	d->responseNum = new QLabel(tr("已有%1回复").arg(entity->responseNum()));
	d->responseNum->setObjectName("responseNum");	//回复数

	row1->setMargin(0);
	row1->addWidget(d->flagZhiFan, 0, Qt::AlignLeft);
	row1->addWidget(d->title, 0, Qt::AlignCenter);

	//row2
	d->imageShow = new ImageCarouselFrame(this);
	d->imageShow->setFixedSize(this->width(), this->height()*0.6);
	d->imageShow->initWidget(d->imageData);
	delete d->imageData;
	d->imageData = 0;

	//row3
	d->describeMsg = new QLabel;
	d->describeMsg->setWordWrap(true);
	d->describeMsg->setObjectName("describeMsg");
	d->describeMsg->setText("描述：\n"+entity->briefDesc().left(50)+"......");
	d->describeMsg->setFixedWidth(width());

	//row4
	d->responseMuchOfAppluad = new QLabel;
	d->responseMuchOfAppluad->setWordWrap(true);
	d->responseMuchOfAppluad->setObjectName("responseMuchOfAppluad");
	d->responseMuchOfAppluad->setText("精彩回答：\n"+entity->responseInfo().left(50) + "......");
	d->responseMuchOfAppluad->setFixedWidth(width());

	d->mainLayout = new QVBoxLayout;
	d->mainLayout->setMargin(0);
	d->mainLayout->addLayout(row1);
	d->mainLayout->addWidget(d->responseNum, 0, Qt::AlignRight | Qt::AlignBottom);
	d->mainLayout->setSpacing(3);
	d->mainLayout->addWidget(d->imageShow);
	d->mainLayout->setSpacing(2);
	//d->mainLayout->addLayout(row3);
	d->mainLayout->addWidget(d->describeMsg);
	d->mainLayout->setSpacing(2);
	d->mainLayout->addWidget(d->responseMuchOfAppluad);

	d->bg = new QLabel(this);
	d->bg->setFixedSize(size());
	d->bg->setLayout(d->mainLayout);
	d->bg->setStyleSheet("background-color: #5299A9");

	d->maskFrame = new MaskFrame(this);
	d->maskFrame->setFixedSize(size());
	connect(d->maskFrame, &MaskFrame::tryToLook, this, &ZhiFanBriefFrame::onImageLookDetailed);
	d->maskFrame->hide();

	initStyle();
}

void ZhiFanBriefFrame::parseImageData()
{
	Q_D(ZhiFanBriefFrame);

	auto &imageBase64Data = entity->photo();
	d->imageData = new QVector < QPixmap > ;
	d->imageData->reserve(imageBase64Data.size());
	QByteArray tmpData;
	QImage image;
	for (auto &val : imageBase64Data){
		tmpData = val.toByteArray();
		utils::ByteArrayToImage(tmpData, image);
		d->imageData->push_back(QPixmap::fromImage(image));
	}
}

#define __duration (1 * 500)
void ZhiFanBriefFrame::enterEvent(QEvent *)
{
	Q_D(ZhiFanBriefFrame);
	if (d->animationShow == 0){

		d->animationShow = new QPropertyAnimation(d->maskFrame, "geometry");
		d->animationShow->setDuration(__duration);
		connect(d->animationShow, &QPropertyAnimation::finished, this, &ZhiFanBriefFrame::onAnimationShowFinished);
		d->animationShow->setStartValue(QRect({ d->maskFrame->pos().x(), -d->maskFrame->size().height() }, d->maskFrame->size()));
		d->animationShow->setEndValue(QRect({ d->maskFrame->pos().x(), d->maskFrame->pos().y() }, d->maskFrame->size()));
		d->animationShow->setEasingCurve(QEasingCurve::InCubic);
	}
	d->animationShow->stop();
	d->animationHide ? d->animationHide->stop() : 0;

	d->maskFrame->showOne();
	d->animationShow->start();
}

void ZhiFanBriefFrame::leaveEvent(QEvent *)
{
	Q_D(ZhiFanBriefFrame);
	d->animationShow->stop();
	if (d->animationHide == 0){

		d->animationHide = new QPropertyAnimation(d->maskFrame, "geometry");
		d->animationHide->setDuration(__duration);
		connect(d->animationHide, &QPropertyAnimation::finished, this, &ZhiFanBriefFrame::onAnimationHideFinished);
		d->animationHide->setStartValue(QRect({ d->maskFrame->pos().x(), d->maskFrame->pos().y() }, d->maskFrame->size()));
		d->animationHide->setEndValue(QRect({ d->maskFrame->pos().x(), -d->maskFrame->size().height() }, d->maskFrame->size()));
		d->animationHide->setEasingCurve(QEasingCurve::OutCubic);
	}
	d->animationHide->stop();
	d->animationHide->start();
}
#undef __duration
void ZhiFanBriefFrame::onImageLookDetailed()
{
	emit havealook(entity);
}

void ZhiFanBriefFrame::onAnimationHideFinished()
{
	Q_D(ZhiFanBriefFrame);
	d->maskFrame->hide();
}

void ZhiFanBriefFrame::onAnimationShowFinished()
{
	Q_D(ZhiFanBriefFrame);
	d->maskFrame->showAll();
}

void ZhiFanBriefFrame::setImageCarouselState(bool on /*= true*/)
{
	Q_D(ZhiFanBriefFrame);
	d->imageShow->setTimerOn(on);
}
