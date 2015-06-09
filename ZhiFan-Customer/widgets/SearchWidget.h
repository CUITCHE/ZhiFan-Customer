#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H
/*!
 * \file SearchWidget.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �����ؼ�
 */
#include "ClientDataStructure_defs.h"
#include <QWidget>
#include <memory>
#include <vector>
using std::vector;
using std::unique_ptr;

class QComboBox;
class QLineEdit;
class QPushButton;
class QGridLayout;
class QTimeLine;

enum ShowOrder
{
	ShowCity,
	ShowDistrict,
	HideCity,
	HideDistrict
};
class SearchWidget : public QWidget
{
	Q_OBJECT

public:
	SearchWidget(QWidget *parent = 0);
	~SearchWidget();
	//��ȡʡ�����������ݣ���ˢ��combbox�ؼ�
	void getProviceAndCityAndDistrcitData(const vector<SearchPCD> &pcd);
protected:
	void initWidget();
protected slots:
	void onTimeLineFrameChanged(int frame);
	void onTimeLineFinished();
	void onComboBoxCurrentIndexChanged(int index);
private:
	void showCity(int frame);
	void hideCity(int frame);
	void showDistrict(int frame);
	void hideDistrict(int frame);
private:
	unique_ptr<QGridLayout> mainLayout;
	QComboBox *provinceBox;		//ʡ��/ֱϽ��
	QComboBox *cityBox;			//��/��
	QComboBox *districtBox;		//��/��
	QLineEdit *keywordInputFrame;	//�����ؼ��������
	QPushButton *searchBtn;

	//��������
	ShowOrder animationOrder;
	QTimeLine *timeLine;
};

#endif // SEARCHWIDGET_H
