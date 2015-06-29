/********************************************************************
	created:	2014/06/14
	created:	14:6:2014   10:42
	filename: 	E:\EngineerIng_PracticeII\picManager\trunk\IPhoto\IPhoto\widgets\HLabel.h
	file ext:	h
	author:		CHE
	
	purpose:	�̳�Qlabel�࣬����hclicked�źŷ��䣬ר��������ʾͼƬ��
*********************************************************************/
#pragma once
#include <QLabel>

class QMouseEvent;

class HLabel: public QLabel
{
	Q_OBJECT
public:
	HLabel(QPixmap &image, int tag = -1, QWidget *parent = NULL);
	~HLabel();
protected:
	void mousePressEvent(QMouseEvent *ev);
signals:
	void clicked(int tag);
private:
	int tag;
};
