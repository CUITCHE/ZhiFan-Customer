#include "stdafx.h"
#include "DetailedBoard.h"
#include "ImageBoard.h"
#include "PublishBriefOneEntity.h"
#include "PublishOneEntity.h"
#include "Utils.h"

struct DetailedBoardPrivate
{
	//ui
	QHBoxLayout *mainLayout = 0;
	//ui 0
	//ui 0 1
	QLabel *header = 0;
	QLabel *userBriefName = 0;
	QPushButton *iKnowBtn = 0;
	//ui 0 2
	//图片显示区，采用QQ空间相册的显示方式
	ImageBoard *imageBoard;
	//ui 0 3
	QTextEdit *describeBoard = 0;

	//ui 1
	//ui 1 1
	//评论显示控件，【未完成】
	//ui 1 2 评论发布编辑区，【未完成】
};
DetailedBoard::DetailedBoard(PublishBriefOneEntity *bEntity, PublishOneEntity *dEntity, QWidget *parent /*= 0*/) : QWidget(parent)
	, d_ptr(new DetailedBoardPrivate)
	, entity_d(dEntity)
	, entity_b(bEntity)
{
	initWidget();
}

DetailedBoard::~DetailedBoard()
{

}

void DetailedBoard::initWidget()
{
	Q_D(DetailedBoard);
	//生成界面

	//左部份布局
	QVBoxLayout *column1 = new QVBoxLayout;
	//第一行 头像，姓名，iknow按钮
	QHBoxLayout *row1 = new QHBoxLayout;
	d->header = new QLabel;
	d->userBriefName = new QLabel;
	d->iKnowBtn = new QPushButton;
	row1->addWidget(d->header);
	row1->addWidget(d->userBriefName);
	row1->addWidget(d->iKnowBtn);
	column1->addLayout(row1);
	//第二行 图片显示区
	QList<QPixmap> mapList;
	{
		QByteArray array;
		QImage image;
		for (auto &val : entity_b->photo()){
			array = val.toByteArray();
			array = QByteArray::fromBase64(array);
			utils::ByteArrayToImage(array, image);
			mapList.push_back(QPixmap::fromImage(image));
		}
	}
	d->imageBoard = new ImageBoard(mapList);
	column1->addWidget(d->imageBoard);
	//第三行 描述信息
	d->describeBoard = new QTextEdit;
	column1->addWidget(d->describeBoard);
	
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	mainLayout->addLayout(column1);

	//右部分 布局

}
