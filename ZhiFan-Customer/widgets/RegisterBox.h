#ifndef REGISTERBOX_H
#define REGISTERBOX_H
/*!
 * \file RegisterBox.h
 *
 * \author CHE
 * \date ÆßÔÂ 2015
 *
 * ×¢²á¿ò
 */
#include <QDialog>
class RegisterBoxPrivate;

class RegisterBox : public QDialog
{
	Q_OBJECT

public:
	RegisterBox(QWidget *parent);
	~RegisterBox();
	void success();
	void show();
protected slots:
	void onQuitBtnClicked();
	void onRegisterBtnClicked();
protected:
	void initWidget();
	RegisterBoxPrivate *const d_ptr;
private:
	Q_DECLARE_PRIVATE(RegisterBox);
};

#endif // REGISTERBOX_H
