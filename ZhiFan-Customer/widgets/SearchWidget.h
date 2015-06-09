#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H
/*!
 * \file SearchWidget.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 搜索控件
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
	//获取省市区名字数据，并刷新combbox控件
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
	QComboBox *provinceBox;		//省份/直辖市
	QComboBox *cityBox;			//市/区
	QComboBox *districtBox;		//县/村
	QLineEdit *keywordInputFrame;	//搜索关键字输入框
	QPushButton *searchBtn;

	//动画控制
	ShowOrder animationOrder;
	QTimeLine *timeLine;
};

#endif // SEARCHWIDGET_H
