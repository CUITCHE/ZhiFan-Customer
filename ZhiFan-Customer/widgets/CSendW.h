//
#ifndef CSENDW_H
#define CSENDW_H
//
#include <QDialog>
#include <QStringList>
#include <QFileDialog>
#include <QPainter>
#include "ui_CSendW.h"
//
namespace Ui {
class CSendW;
}
//
//
class CSendW : public QDialog
{
    Q_OBJECT
    //
public:
    explicit CSendW(QWidget *parent = 0);
    ~CSendW();
	QString getTitle()const;
	QString getplace()const;
	QString getType()const;
	QString getDate()const;
public slots:
    void slotAddPic();
    void slotDelPic();
    void slotSubmitBtn();
protected:
    void paintEvent(QPaintEvent*);
signals:
	void sigSubmitBtn(QStringList &);
private:
    Ui::CSendW *ui;
    QStringList m_picUrlList;
    QLabel *m_picLArray[5];
};
//
//
#endif // CSENDW_H
