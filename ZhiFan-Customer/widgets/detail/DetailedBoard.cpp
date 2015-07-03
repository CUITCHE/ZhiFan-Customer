#include "stdafx.h"
#include "DetailedBoard.h"
#include "ImageBoard.h"
#include "PublishBriefOneEntity.h"
#include "PublishOneEntity.h"
#include "Utils.h"
#include "CommentBoard.h"

struct DetailedBoardPrivate
{
	//ui
	//ui 0
	//ui 0 1
	QPushButton *flagZhiFanBtn;
	QLabel *titleZhiFan;
	QLabel *userBriefName;
	//ui 0 2
	//ͼƬ��ʾ��������QQ�ռ�������ʾ��ʽ
	ImageBoard *imageBoard = 0;
	//ui 0 3
	QTextEdit *describeBoard;

	//ui 1
	//ui 1 1
	//������ʾ�ؼ�
	CommentBoard *commentBoard;
	//ui 1 2 ���۷����༭��
	QTextEdit *commentEdit;
	QPushButton *commitBtn;

	/*���岼�� ������*/
	QLabel *leftPart;
	QLabel *rightPart;
	QHBoxLayout *mainLayout;
	DetailedBoardPrivate()
		:mainLayout(new QHBoxLayout)
		, leftPart(new QLabel)
		, rightPart(new QLabel)
		,flagZhiFanBtn(new QPushButton)
		, titleZhiFan(new QLabel)
		, userBriefName(new QLabel)
		, describeBoard(new QTextEdit)
		, commentBoard(new CommentBoard)
		, commentEdit(new QTextEdit)
		, commitBtn(new QPushButton)
	{
	}
	~DetailedBoardPrivate(){
		delete mainLayout;
	}
};
DetailedBoard::DetailedBoard(const PublishBriefOneEntity *bEntity, const PublishOneEntity *dEntity, QWidget *parent /*= 0*/) 
	: QDialog(parent)
	, d_ptr(new DetailedBoardPrivate)
	, entity_d(dEntity)
	, entity_b(bEntity)
{
	//setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_DeleteOnClose);
	setFixedSize({800,600});
	initWidget();
	initStyle();
}

DetailedBoard::~DetailedBoard()
{
	delete d_ptr;
}

void DetailedBoard::initWidget()
{
	Q_D(DetailedBoard);
	//���ɽ���

	//�󲿷ݲ���
	QVBoxLayout *column1 = new QVBoxLayout;
	column1->setMargin(0);
	//��һ�� ͷ��������iknow��ť
	QHBoxLayout *row1 = new QHBoxLayout;
	row1->setMargin(0);
	
	d->flagZhiFanBtn->setObjectName("flagZhiFanBtn");
	d->flagZhiFanBtn->setFixedSize(64, 30);
	if (entity_b->type() == 1){
		d->flagZhiFanBtn->setText(tr("��"));
	}
	else{
		d->flagZhiFanBtn->setText(tr("֪"));
	}
	d->flagZhiFanBtn->setObjectName("flagZhiFanBtn");
	d->titleZhiFan->setText(entity_b->title());
	d->titleZhiFan->setObjectName("titleZhiFan");

	d->userBriefName->setText(tr("֪���û�"));
	d->userBriefName->setObjectName("userBriefName");
	d->userBriefName->setFixedHeight(20);

	row1->addSpacing(5);
	row1->addWidget(d->flagZhiFanBtn, 0, Qt::AlignTop | Qt::AlignLeft);
	row1->addWidget(d->titleZhiFan, 0, Qt::AlignCenter | Qt::AlignBottom);
	row1->addWidget(d->userBriefName, 0, Qt::AlignTop | Qt::AlignRight);
	column1->addLayout(row1);
	//�ڶ��� ͼƬ��ʾ��
	QList<QPixmap> mapList;
	{
		QByteArray array;
		QImage image;
		for (auto &val : entity_b->photo()){
			array = val.toByteArray();
			//array = QByteArray::fromBase64(array);
			utils::ByteArrayToImage(array, image);
			mapList.push_back(QPixmap::fromImage(image));
		}
	}
	d->imageBoard = new ImageBoard(mapList);
	d->imageBoard->setFixedSize(width()/2-5, height()*0.7);
	column1->addWidget(d->imageBoard, 0, Qt::AlignCenter);
	//������ ������Ϣ
	d->describeBoard->setReadOnly(true);
	d->describeBoard->setFixedSize(width() / 2 - 5, height()*0.2);
	d->describeBoard->setText(entity_b->briefDesc());
	column1->addWidget(d->describeBoard);
	d->leftPart->setFixedSize(width() / 2-5, height());
	d->leftPart->setStyleSheet("background-color: #5299A9");
	d->leftPart->setLayout(column1);

	//�Ҳ��� ����
	QVBoxLayout *column2 = new QVBoxLayout;
	column2->setAlignment(Qt::AlignLeft);

	d->commentBoard->addItem("English", "֪���û�");
	d->commentBoard->addItem("English", "֪���û�");
	d->commentBoard->addItem("English", "֪���û�");
	d->commentBoard->addItem("English", "֪���û�");
	d->commentBoard->addItem("English", "֪���û�");
	d->commentBoard->addItem("English", "֪���û�");
	column2->addWidget(d->commentBoard);
	
	d->commentEdit->setFixedSize(width()/2-5, height()*0.2);
	column2->addWidget(d->commentEdit);

	d->commitBtn->setText(tr("�ύ"));
	column2->addWidget(d->commitBtn, 0, Qt::AlignRight);
	d->rightPart->setFixedSize(width() / 2 - 5, height());
	d->rightPart->setLayout(column2);

	d->mainLayout->setMargin(0);
	d->mainLayout->addWidget(d->leftPart,0,Qt::AlignLeft);
	d->mainLayout->addWidget(d->rightPart,0,Qt::AlignRight);

	this->setLayout(d->mainLayout);
}

void DetailedBoard::parseData()
{
	//debug model

}

void DetailedBoard::initStyle()
{
	QFile file(":/zhifan.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}