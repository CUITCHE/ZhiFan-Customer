#ifndef LOGINBOX_H
#define LOGINBOX_H
/*!
 * \file LoginBox.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��¼��
 */
#include <QDialog>
class LoginBoxPrivate;
class LoginBox : public QDialog
{
	Q_OBJECT

public:
	LoginBox(QWidget *parent);
	~LoginBox();
	void success();
	void registerSuccess();
	void show();
	QString account()const;
	QString pwd()const;
protected:
	void initWidget();
	LoginBoxPrivate *const d_ptr;
protected slots:
	void onLoginBtnClicked();
	void onRegisterBtnClicked();
private:
	Q_DECLARE_PRIVATE(LoginBox);
};

#endif // LOGINBOX_H
