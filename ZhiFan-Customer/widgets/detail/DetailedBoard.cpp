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
	//ͼƬ��ʾ��������QQ�ռ�������ʾ��ʽ
	ImageBoard *imageBoard;
	//ui 0 3
	QTextEdit *describeBoard = 0;

	//ui 1
	//ui 1 1
	//������ʾ�ؼ�����δ��ɡ�
	//ui 1 2 ���۷����༭������δ��ɡ�
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
	//���ɽ���

	//�󲿷ݲ���
	QVBoxLayout *column1 = new QVBoxLayout;
	//��һ�� ͷ��������iknow��ť
	QHBoxLayout *row1 = new QHBoxLayout;
	d->header = new QLabel;
	d->userBriefName = new QLabel;
	d->iKnowBtn = new QPushButton;
	row1->addWidget(d->header);
	row1->addWidget(d->userBriefName);
	row1->addWidget(d->iKnowBtn);
	column1->addLayout(row1);
	//�ڶ��� ͼƬ��ʾ��
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
	//������ ������Ϣ
	d->describeBoard = new QTextEdit;
	column1->addWidget(d->describeBoard);
	
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	mainLayout->addLayout(column1);

	//�Ҳ��� ����

}
