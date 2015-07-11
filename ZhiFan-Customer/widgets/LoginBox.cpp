#include "stdafx.h"
#include "LoginBox.h"
#include "Login.h"
#include "RegisterBox.h"
struct LoginBoxPrivate
{
	QLabel *accountLabel;
	QLabel *pwdLabel;
	QLabel *hintLabel;
	QLineEdit *accountInput;
	QLineEdit *pwdInput;
	QPushButton *registerBtn;
	QPushButton *loginBtn;
	LoginBoxPrivate()
		:accountLabel(new QLabel(QObject::tr("帐号:")))
		, pwdLabel(new QLabel("密码:"))
		, accountInput(new QLineEdit)
		, pwdInput(new QLineEdit)
		, registerBtn(new QPushButton("注册"))
		, loginBtn(new QPushButton("登陆"))
		, hintLabel(new QLabel)
		, mainLayout(new QVBoxLayout)
	{}
	~LoginBoxPrivate(){
		delete mainLayout;
		delete box;
	}
	RegisterBox *box = 0;
	QVBoxLayout *mainLayout;
};
LoginBox::LoginBox(QWidget *parent)
	: QDialog(parent)
	, d_ptr(new LoginBoxPrivate)
{
	initWidget();
}

LoginBox::~LoginBox()
{
	delete d_ptr;
}

void LoginBox::initWidget()
{
	Q_D(LoginBox);
	d->accountInput->setPlaceholderText(tr("请输入手机号码"));
	
	d->accountInput->setValidator(new QRegExpValidator(QRegExp("^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\\d{8}$"), this));
	d->pwdInput->setPlaceholderText(tr("请输入密码"));
	d->pwdInput->setEchoMode(QLineEdit::Password);
	connect(d->loginBtn, &QPushButton::clicked, this, &LoginBox::onLoginBtnClicked);
	connect(d->registerBtn, &QPushButton::clicked, this, &LoginBox::onRegisterBtnClicked);
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
	row4->addWidget(d->loginBtn);

	d->mainLayout->addLayout(row1);
	d->mainLayout->addLayout(row2);
	d->mainLayout->addWidget(d->hintLabel);
	d->mainLayout->addLayout(row4);

	setLayout(d->mainLayout);
}

void LoginBox::onLoginBtnClicked()
{
	Q_D(LoginBox);
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

	LoginPacket *pck = new LoginPacket;
	pck->setMobile(account);
	pck->setPassword(pwdEncry);

	auto ret = SingleObject->sendRequest(pck);
	if (ret == false){
		d->hintLabel->setText("网络连接失败, 请重试!");
		d->hintLabel->show();
	}
	delete pck;
}

void LoginBox::onRegisterBtnClicked()
{
	Q_D(LoginBox);
	if (!d->box){
		d->box = new RegisterBox(this);
	}
	d->box->show();
}

void LoginBox::success()
{
	close();
}

void LoginBox::registerSuccess()
{
	Q_D(LoginBox);
	if (d->box){
		d->box->success();
	}
}

void LoginBox::show()
{
	Q_D(LoginBox);
	d->accountInput->clear();
	d->pwdInput->clear();
	QWidget::show();
}

QString LoginBox::account() const
{
	Q_D(const LoginBox);
	return d->accountInput->text();
}

QString LoginBox::pwd() const
{
	Q_D(const LoginBox);
	QByteArray pwd = d->pwdInput->text().toLatin1();

	auto pwdEncry = QCryptographicHash::hash(pwd, QCryptographicHash::Md5).toHex();
	return pwdEncry;
}
