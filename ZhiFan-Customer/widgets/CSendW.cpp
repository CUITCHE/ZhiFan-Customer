#include "stdafx.h"
#include "CSendW.h"
//
//
CSendW::CSendW(QWidget *parent) :
	QDialog(parent),
    ui(new Ui::CSendW)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    //
    ui->capLE->setFixedHeight(30);
    ui->placeLE->setFixedHeight(30);
    ui->timeLE->setFixedHeight(30);
    ui->typeCB->setFixedHeight(30);
    ui->timePicL->setFixedSize(25,25);
    ui->pic1L->setFixedSize(30,30);
    ui->pic2L->setFixedSize(30,30);
    ui->pic3L->setFixedSize(30,30);
    ui->pic4L->setFixedSize(30,30);
    ui->pic5L->setFixedSize(30,30);
    ui->addPicBtn->setFixedSize(20,20);
    ui->delPicBtn->setFixedSize(20,20);
    ui->submitBtn->setFixedHeight(25);
    m_picLArray[0] = ui->pic1L;
    m_picLArray[1] = ui->pic2L;
    m_picLArray[2] = ui->pic3L;
    m_picLArray[3] = ui->pic4L;
    m_picLArray[4] = ui->pic5L;
    //
    connect(ui->addPicBtn, SIGNAL(clicked()), this, SLOT(slotAddPic()));
    connect(ui->delPicBtn, SIGNAL(clicked()), this, SLOT(slotDelPic()));
    connect(ui->submitBtn, SIGNAL(clicked()), this, SLOT(slotSubmitBtn()));
	setAttribute(Qt::WA_DeleteOnClose);
}

CSendW::~CSendW()
{
    delete ui;
}

void CSendW::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    const int cstShadowS = 3;
    //
    painter.setRenderHint(QPainter::Antialiasing);
    //----------------------------------------------------------------------------------------------- 绘制边框阴影
    QPainterPath shadowPath1;
    shadowPath1.addRoundRect(0,0,width(),height(),4);
    painter.setPen(QColor(0, 0, 0, 10));
    painter.drawPath(shadowPath1);
    QPainterPath shadowPath2;
    shadowPath2.addRoundRect(1,1,width()-2,height()-2,3);
    painter.setPen(QColor(0, 0, 0, 20));
    painter.drawPath(shadowPath2);
    QPainterPath shadowPath3;
    shadowPath3.addRoundRect(2,2,width()-4,height()-4,3);
    painter.setPen(QColor(0, 0, 0, 60));
    painter.drawPath(shadowPath3);
    QPainterPath borderPath;
    borderPath.addRoundRect(cstShadowS,cstShadowS,width()-2*cstShadowS,height()-2*cstShadowS,2);
    painter.setPen(Qt::black);
    painter.drawPath(borderPath);
    //----------------------------------------------------------------------------------------------- background
    QPainterPath bgPath;
    bgPath.addRoundRect(cstShadowS,cstShadowS,width()-2*cstShadowS,height()-2*cstShadowS,2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPath(bgPath);
    //-----------------------------------------------------------------------------------------------
    for(int i=0; i<m_picUrlList.size(); i++){
        QPixmap LPix(m_picUrlList.at(i));
        m_picLArray[i]->setPixmap(LPix);
    }
}

void CSendW::slotAddPic()
{
    QFileDialog *fileDialog = new QFileDialog(this,"import image",".","Image Files(*.bmp *.jpg *.png)");
    QString fileName = QString();
    if(fileDialog->exec() == QDialog::Accepted)
        fileName = fileDialog->selectedFiles()[0];
    if(fileName.isEmpty())
        return;
    else{
        if(m_picUrlList.size() < 5){
            m_picUrlList.append(fileName);
            update();
        }else{
            return;
        }
    }
}

void CSendW::slotDelPic()
{
    if(m_picUrlList.size()){
        m_picLArray[m_picUrlList.size()-1]->setPixmap(QPixmap(""));
        m_picUrlList.pop_back();
    }
}

void CSendW::slotSubmitBtn()
{
	emit sigSubmitBtn(m_picUrlList);
}

QString CSendW::getTitle() const
{
	return ui->capLE->text();
}

QString CSendW::getplace() const
{
	return ui->placeLE->text();
}

QString CSendW::getType() const
{
	return ui->typeCB->currentText();
}

QString CSendW::getDate() const
{
	return ui->timeLE->text();
}



