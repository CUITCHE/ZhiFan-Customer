#include "stdafx.h"
#include "TerminalWidget.h"
#include "packets.h"
#include "SearchWidget.h"
#include "DisplayZhiFanBoard.h"
#include "Utils.h"
#include "NetworkDataWorker.h"
#include "LoginBox.h"
#include "Factory.h"
#include "UserData.h"
#include "CSendW.h"
#include "VerificationBox.h"
#include <QWebView>
#include <QWebFrame>
struct TerminalWidgetPrivate
{
	bool loginStatus = 0;
	VerificationBox *box = 0;
	UserData *userdata;
	QWebView *webView = 0;
	NetworkDataWorker *socket;
	LoginBox *loginbox=0;
	QSize *originSize;
	QPoint *lastPoint;
	//总布局 控制变量声明处
	//unique_ptr<QVBoxLayout> mainLayout;
	//row1 控件声明处
	QPushButton *closeBtn;	//关闭按钮
	QPushButton *extendBtn;	//变大按钮
	QPushButton *narrowBtn;	//缩小按钮
	QLabel *logoLabel;			//显示logo
	QLabel *showUserNameLabel;	//显示用户名字，例如：何先生/李女士
	QPushButton *userHeaderBtn;	//用户头像按钮，点击进入用户管理界面

	//row2 控件声明处
	/*您有新消息未查看，此处为自定义控件【暂时未写】*/

	//row3 控件声明处
	/*显示知返，以“花瓣”网站的风格显示，此处为自定义控件*/
	DisplayZhiFanBoard *displayBoard;

	//row4 第一列 控件声明处
	/*搜索控件，自定义控件*/
	SearchWidget *searchFrame;
	//row4 第二列
	QPushButton *publishBtn;	//我要发布 按钮
};
TerminalWidget *SingleObject;
TerminalWidget::TerminalWidget(const QSize &frame, QWidget *parent /*= 0*/)
	:QWidget(parent)
	, d_ptr(new TerminalWidgetPrivate)
{
	this->setFixedSize(frame);
	initWidget();
	shadowPaint();
	setFillet();
	initStyle();
	d_ptr->originSize = new QSize(frame);
	SingleObject = this;
	d_ptr->socket = new NetworkDataWorker(this);
	connect(d_ptr->socket, &NetworkDataWorker::packetData, this, &TerminalWidget::onPacketData);
	d_ptr->userdata = new UserData(this);
}

TerminalWidget::~TerminalWidget()
{
	delete d_ptr;
}

void TerminalWidget::initWidget()
{
	Q_D(TerminalWidget);
	d->lastPoint = new QPoint;
	//row1
	const QSize size{ 30, 30 };
	QHBoxLayout *row1 = new QHBoxLayout;
	row1->setAlignment(Qt::AlignLeft);
	row1->setMargin(0);
	{
		QHBoxLayout *row = new QHBoxLayout;
		d->closeBtn = new QPushButton;
		d->closeBtn->setFixedSize(size);
		d->closeBtn->setObjectName("closeBtn");
		connect(d->closeBtn, &QPushButton::clicked, this, &TerminalWidget::onQuit);
		d->extendBtn = new QPushButton;
		d->extendBtn->setFixedSize(size);
		d->extendBtn->setObjectName("extendBtn");
		connect(d->extendBtn, &QPushButton::clicked, this, &TerminalWidget::onExtend);
		d->narrowBtn = new QPushButton;
		d->narrowBtn->setFixedSize(size);
		d->narrowBtn->setObjectName("narrowBtn");
		connect(d->narrowBtn, &QPushButton::clicked, this, &TerminalWidget::onMinus);
		row->addWidget(d->closeBtn, Qt::AlignCenter | Qt::AlignLeft);
		row->addWidget(d->extendBtn, Qt::AlignCenter | Qt::AlignLeft);
		row->addWidget(d->narrowBtn, Qt::AlignCenter | Qt::AlignLeft);
		row1->addLayout(row);
		row1->addSpacing(200);
	}
	d->logoLabel = new QLabel;
	d->logoLabel->setObjectName("logoLabel");
	d->logoLabel->setFixedSize(size);
	row1->addWidget(d->logoLabel, Qt::AlignCenter);
	row1->addSpacing(100);

	d->showUserNameLabel = new QLabel;
	d->showUserNameLabel->setText(tr("请登录"));
	d->showUserNameLabel->setAlignment(Qt::AlignRight|Qt::AlignCenter);
	//d->showUserNameLabel->hide();
	row1->addWidget(d->showUserNameLabel);
	row1->addSpacing(100);

	d->publishBtn = new QPushButton(tr("发布"));
	row1->addWidget(d->publishBtn, 0, Qt::AlignBottom | Qt::AlignRight);
	connect(d->publishBtn, &QPushButton::clicked, this, &TerminalWidget::onPublishBtnClicked);
	d->userHeaderBtn = new QPushButton;
	connect(d->userHeaderBtn, &QPushButton::clicked, this, &TerminalWidget::login);
	d->userHeaderBtn->setObjectName("userHeaderBtn");
	d->userHeaderBtn->setFixedSize(size);
	row1->addWidget(d->userHeaderBtn, Qt::AlignRight);
	row1->addSpacing(20);
	//row2
	QHBoxLayout *row2 = new QHBoxLayout;

	//row3
	QHBoxLayout *row3 = new QHBoxLayout;
	d->displayBoard = new DisplayZhiFanBoard;
	d->displayBoard->setFixedHeight(this->height()*0.85);
	row3->addWidget(d->displayBoard);

	//row4
	d->searchFrame = new SearchWidget;

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setContentsMargins(10, 10, 10, 10);
	mainLayout->addLayout(row1);
	mainLayout->addSpacing(5);
	mainLayout->addLayout(row2);
	mainLayout->addSpacing(5);
	mainLayout->addLayout(row3);
	mainLayout->addSpacing(5);
	mainLayout->addWidget(d->searchFrame, 0, Qt::AlignBottom);
	mainLayout->addSpacing(1);
	this->setLayout(mainLayout);
	QTimer::singleShot(100, [=](){d->displayBoard->addItems(utils::getdata()); });
}

void TerminalWidget::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(150 - qSqrt(i) * 50);
		painter.setPen(color);
		painter.drawPath(path);
	}
}

void TerminalWidget::mousePressEvent(QMouseEvent *event)
{
	Q_D(TerminalWidget);
	*d->lastPoint = event->globalPos();
	event->ignore();
}

void TerminalWidget::mouseMoveEvent(QMouseEvent *event)
{
	Q_D(TerminalWidget);
	if (event->buttons() ==Qt::LeftButton){
		QPoint newPos = event->globalPos();
		QPoint updateLeft = mapToParent(newPos - *d->lastPoint);
		move(updateLeft);
		*d->lastPoint = newPos;
		event->accept();
	}
}

void TerminalWidget::shadowPaint()
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_ShowWithoutActivating, true);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); ////水平方向和垂直方向任意伸展
}

void TerminalWidget::setFillet()
{/*
	QPainterPath path;
	QRectF rect = QRectF(10, 10, this->width()-20, this->height()-20);
	path.addRoundRect(rect, 1, 1);
	QPolygon polygon = path.toFillPolygon().toPolygon();//获得这个路径上的所有的点
	QRegion region(polygon);//根据这些点构造这个区域
	setMask(region);*/
}

void TerminalWidget::initStyle()
{
	QFile file(":/zhifan.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}

void TerminalWidget::onQuit()
{
	QApplication::quit();
}

void TerminalWidget::onMinus()
{
	showMinimized();
}

void TerminalWidget::onExtend()
{
	Q_D(TerminalWidget);
	auto size = this->size();
	if (d->originSize->width() < size.width()){
		showNormal();
	}
	else{
		showMaximized();
	}

}

bool TerminalWidget::sendRequest(const Packet *packet)
{
	Q_D(TerminalWidget);
	return d->socket->sendRequest(packet);
}


void TerminalWidget::onPacketData(const Packet *packet)
{
	int protocol = packet->getProtocol();
	NetCommunicationProtocol safetyProtocol = net::protocol_cast(protocol);
	if (safetyProtocol == Empty){
		return;
	}
	switch (safetyProtocol)
	{
	case ServerBack:
		onServerBack(packet);
		break;
	case ResponseLogin:
		onResponseLogin(packet);
		break;
	case ResponseGetOneZhiFanPublish:
		onResponseGetOneZhiFanPublish(packet);
		break;
	case ResponseGetZhiFanPublishPageOfRange:
		onResponseGetZhiFanPublishPageOfRange(packet);
		break;
	}
}
void TerminalWidget::onServerBack(const Packet *packet)
{
	auto pck = dynamic_cast<const ServerBackPacket*>(packet);
	QMessageBox::information(this, "信息", pck->getMsg());
	if (pck->getStatus() == 0){
		Q_D(TerminalWidget);
		switch (pck->getOperator())
		{
		case Login:
			d->userdata->_pwd = d->loginbox->pwd();
			d->loginStatus = true;
			d->loginbox->success();
			break;
		case Register:
			d->loginbox->registerSuccess();
			break;
		}
	}
}

void TerminalWidget::onResponseGetOneZhiFanPublish(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseGetOneZhiFanPublishPacket*>(packet);
}

void TerminalWidget::onResponseGetZhiFanPublishPageOfRange(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseGetZhiFanPublishPageOfRangePacket*>(packet);
}

/*更新用户信息实体*/
void TerminalWidget::onResponseLogin(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseLoginPacket*>(packet);
	Q_D(TerminalWidget);
	d->userdata->account = QString::number(pck->getUserid());
	auto ins = getInstance(Factory);
	ins->addUserLoginInfo(packet);
	d->showUserNameLabel->setText(pck->getUsername());
}

void TerminalWidget::onResponsePullUserCenter(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponsePullUserCenterPacket*>(packet);
}

void TerminalWidget::onResponseSearchZhiFan(const Packet *packet)
{
	auto pck = dynamic_cast<const ResponseSearchZhiFanPacket*>(packet);
	Q_D(TerminalWidget);
	auto ins = getInstance(Factory);
	for (auto &val : pck->getPublishList()){
		ins->addPublishBrief(&val);
		auto iter = ins->publishBrief->find(val.getPublishId());
		if (iter != ins->publishBrief->end()){
			d->displayBoard->addItem(iter->second);
		}
	}
}

void TerminalWidget::login()
{
	Q_D(TerminalWidget);
	if (!d->loginbox){
		d->loginbox = new LoginBox(this);
	}
	if (d->loginStatus){
		if (!d->webView){
			d->webView = new QWebView(0);
			d->box = new VerificationBox(0);
			QObject::connect(d->webView->page()->mainFrame(), &QWebFrame::javaScriptWindowObjectCleared, d->webView, [=](){
				d->webView->page()->mainFrame()->addToJavaScriptWindowObject("userdata", d->userdata);
				d->webView->page()->mainFrame()->addToJavaScriptWindowObject("VerificationBox", d->box);
			});
			
		}
		QUrl url(QString("http://127.0.0.1/user-center.html?userid=%1&token=%2").arg(d->userdata->account).arg(d->userdata->pwd()));
		qDebug() << url;
		d->webView->load(url);
		d->webView->show();
		return;
	}
	d->loginbox->show();
}

void TerminalWidget::onPublishBtnClicked()
{
	CSendW *w = new CSendW(this);
	connect(w, &CSendW::sigSubmitBtn, this, [=](QStringList &dataFileList){
		w->close();
	});
	w->open();
}
