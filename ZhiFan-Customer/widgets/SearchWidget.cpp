#include "stdafx.h"
#include "SearchWidget.h"
const int FrameRange = 86;
SearchWidget::SearchWidget(QWidget *parent)
	: QWidget(parent)
	, mainLayout(new QGridLayout)
	, timeLine(new QTimeLine)
	, animationOrder(ShowCity)
{
	initWidget();
}

SearchWidget::~SearchWidget()
{

}

void SearchWidget::initWidget()
{
	//省份
	provinceBox = new QComboBox;
	provinceBox->setFixedWidth(80);
	provinceBox->addItem(tr("全国"), 0);
	provinceBox->addItem(tr("四川"), 1);
	provinceBox->setEditable(false);

	//市
	cityBox = new QComboBox;
	cityBox->setFixedWidth(80);
	cityBox->addItem(tr("请选择"), 0);
	cityBox->addItem(tr("双流"), 1);
	opacityForCityBox = new QGraphicsOpacityEffect(cityBox);
	cityBox->setGraphicsEffect(opacityForCityBox);
	cityBox->setEditable(false);
	cityBox->hide();
	//区
	districtBox = new QComboBox;
	districtBox->setFixedWidth(80);
	districtBox->addItem(tr("请选择"), 0);
	opacityForDistrictBox = new QGraphicsOpacityEffect(districtBox);
	districtBox->setGraphicsEffect(opacityForDistrictBox);
	districtBox->setEditable(false);
	districtBox->hide();

	//关键字输入框
	QHBoxLayout *row = new QHBoxLayout;
	keywordInputFrame = new QLineEdit;
	keywordInputFrame->setPlaceholderText(tr("请输入搜索关键字,不包含空格"));
	//搜索按钮
	searchBtn = new QPushButton(tr("搜索"));
	row->addWidget(keywordInputFrame);
	row->addWidget(searchBtn);
	
	mainLayout->addWidget(provinceBox,0,0);
	mainLayout->addWidget(cityBox,0,1);
	mainLayout->addWidget(districtBox,0,2);
	mainLayout->addLayout(row,0,3);

	this->setLayout(mainLayout.get());

	//GUI无关 设置
	timeLine->setFrameRange(0, FrameRange);
	
	connect(timeLine, &QTimeLine::frameChanged, this, &SearchWidget::onTimeLineFrameChanged);
	connect(timeLine, &QTimeLine::finished, this, &SearchWidget::onTimeLineFinished);

	connect(provinceBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SearchWidget::onComboBoxCurrentIndexChanged);
	connect(cityBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SearchWidget::onComboBoxCurrentIndexChanged);
}

void SearchWidget::getProviceAndCityAndDistrcitData(const QVector<SearchPCD> &pcd)
{
	const Range range{ 0, 3 };
	QComboBox *tmpArray[] = { provinceBox, cityBox, districtBox };
	for (auto &val : pcd){
		if (val.first == range){
			tmpArray[val.first]->addItem(val.second.second, val.second.first);
		}
	}
}

void SearchWidget::onTimeLineFrameChanged(int frame)
{
	switch (animationOrder)
	{
	case ShowCity:
		showCity(frame);
		break;
	case ShowDistrict:
		showDistrict(frame);
		break;
	case HideCity:
		hideCity(frame);
		break;
	case HideDistrict:
		hideDistrict(frame);
		break;
	}
}

void SearchWidget::showCity(int frame)
{
	if (cityBox->isHidden() == true){
		cityBox->move(provinceBox->pos());
		cityBox->show();
	}
	auto pos = provinceBox->pos();
	cityBox->move(QPoint{ pos.x() + frame, pos.y() });
	opacityForCityBox->setOpacity(frame*1.0f / FrameRange);
}

void SearchWidget::hideCity(int frame)
{
	QPoint pos{ provinceBox->x() + provinceBox->width() - frame, provinceBox->y() };

	cityBox->move(pos);
	opacityForCityBox->setOpacity(frame*1.0f / FrameRange);
	if (districtBox->isHidden() == false){
		pos += QPoint{ cityBox->width(), 0 };
		districtBox->move(pos);
		opacityForDistrictBox->setOpacity(frame*1.0f / FrameRange);
	}
}

void SearchWidget::showDistrict(int frame)
{
	if (districtBox->isHidden() == true){
		districtBox->move(provinceBox->pos());
		districtBox->show();
	}

	districtBox->move(QPoint{ cityBox->x() + frame, cityBox->y() });
	opacityForDistrictBox->setOpacity(frame*1.0f / FrameRange);
}

void SearchWidget::hideDistrict(int frame)
{
	if (cityBox->isHidden()==false){

		districtBox->move(QPoint{ cityBox->x() + cityBox->width() - frame, cityBox->y() });
		opacityForDistrictBox->setOpacity(frame*1.0f / FrameRange);
	}
}

void SearchWidget::onComboBoxCurrentIndexChanged(int index)
{
	auto box = dynamic_cast<QComboBox*>(sender());
	if (box == provinceBox){
		if (index == 0 && cityBox->isHidden() == false){
			animationOrder = HideCity;
		}
		else if (index != 0 && cityBox->isHidden() == true){
			animationOrder = ShowCity;
		}
	}
	else if (box == cityBox){
		//区box处于显示状态
		if (index == 0 && districtBox->isHidden() == false){
			animationOrder = HideDistrict;
		}
		//区box处于隐藏状态
		else if (index != 0 && districtBox->isHidden()==true){
			animationOrder = ShowDistrict;
		}
	}
	else{
		return;
	}
	timeLine->start();
}

void SearchWidget::onTimeLineFinished()
{
	if (animationOrder == HideCity){
		cityBox->hide();
		cityBox->setCurrentIndex(0);
		districtBox->hide();
	}
	else if (animationOrder == HideDistrict){
		districtBox->hide();
	}
}
