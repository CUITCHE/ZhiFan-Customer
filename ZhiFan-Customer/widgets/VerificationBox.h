#ifndef VERIFICATIONBOX_H
#define VERIFICATIONBOX_H

#include <QWidget>
#include "ui_VerificationBox.h"

class VerificationBox : public QWidget
{
    Q_OBJECT

public:
    VerificationBox(QWidget *parent = 0);
    ~VerificationBox();

private:
    Ui::VerificationBox ui;
};

#endif // VERIFICATIONBOX_H
