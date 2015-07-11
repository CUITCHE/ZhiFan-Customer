#include "stdafx.h"
#include "RegisterBox.h"
#include "Register.h"
struct RegisterBoxPrivate
{
	QLabel *accountLabel;
	QLabel *pwdLabel;
	QLabel *hintLabel;
	QLineEdit *accountInput;
	QLineEdit *pwdInput;
	QPushButton *quitBtn;
	QPushButton *registerBtn;
	RegisterBoxPrivate()
		:accountLabel(new QLabel(QObject::tr("帐号:")))
		, pwdLabel(new QLabel("密码:"))
		, accountInput(new QLineEdit)
		, pwdInput(new QLineEdit)
		, quitBtn(new QPushButton("退出"))
		, registerBtn(new QPushButton("注册"))
		, hintLabel(new QLabel)
		, mainLayout(new QVBoxLayout)
	{}
	~RegisterBoxPrivate(){
		delete mainLayout;
	}
	QVBoxLayout *mainLayout;
};
RegisterBox::RegisterBox(QWidget *parent)
	: QDialog(parent)
	, d_ptr(new RegisterBoxPrivate)
{
	initWidget();
}

RegisterBox::~RegisterBox()
{
	delete d_ptr;
}

void RegisterBox::initWidget()
{
	Q_D(RegisterBox);
	d->accountInput->setPlaceholderText(tr("请输入手机号码"));
	d->accountInput->setValidator(new QRegExpValidator(QRegExp("^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\\d{8}$"), this));
	d->pwdInput->setPlaceholderText(tr("请输入密码"));
	d->pwdInput->setEchoMode(QLineEdit::Password);
	connect(d->registerBtn, &QPushButton::clicked, this, &RegisterBox::onRegisterBtnClicked);
	connect(d->quitBtn, &QPushButton::clicked, this, &RegisterBox::onQuitBtnClicked);
	d->hintLabel->hide();

	//布局整理
	QHBoxLayout *row1 = new QHBoxLayout;
	row1->addWidget(d->accountLabel);
	row1->addWidget(d->accountInput);

	QHBoxLayout *row2 = new QHBoxLayout;
	row2->setAlignment(Qt::AlignRight);
	row2->addWidget(d->pwdLabel);
	row2->addWidget(d->pwdInput);

	QHBoxLayout *row4 = new QHBoxLayout;
	row4->addWidget(d->registerBtn);
	row4->addWidget(d->registerBtn);

	d->mainLayout->addLayout(row1);
	d->mainLayout->addLayout(row2);
	d->mainLayout->addWidget(d->hintLabel);
	d->mainLayout->addLayout(row4);

	setLayout(d->mainLayout);
}

void RegisterBox::onQuitBtnClicked()
{
	close();
}

void RegisterBox::onRegisterBtnClicked()
{
	Q_D(RegisterBox);
	d->hintLabel->hide();

	auto account = d->accountInput->text();
	if (account.size() != 11){
		d->hintLabel->setText("帐号格式不正确!请重新输入");
		d->hintLabel->show();
		return;
	}
	QByteArray pwd = d->pwdInput->text().toLatin1();
	if (!pwd.size()){
		d->hintLabel->setText("请输入密码");
		d->hintLabel->show();
		return;
	}
	auto pwdEncry = QCryptographicHash::hash(pwd, QCryptographicHash::Md5).toHex();

	RegisterPacket *pck = new RegisterPacket;
	pck->setMobile(account);
	pck->setPassword(pwdEncry);

	auto ret = SingleObject->sendRequest(pck);
	if (ret == false){
		d->hintLabel->setText("网络连接失败, 请重试!");
		d->hintLabel->show();
	}
	delete pck;
}

void RegisterBox::success()
{
	close();
}

void RegisterBox::show()
{
	Q_D(RegisterBox);
	d->accountInput->clear();
	d->pwdInput->clear();
	QWidget::show();
}
