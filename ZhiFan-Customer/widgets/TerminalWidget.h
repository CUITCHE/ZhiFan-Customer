#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H
/*!
 * \file TerminalWidget.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 整体界面生成类
 */
#include <QWidget>
#include <memory>
using std::unique_ptr;

class QVBoxLayout;
class QPushButton;
class QLabel;
class SearchWidget;
class DisplayZhiFanBoard;

class TerminalWidget : public QWidget
{
	Q_OBJECT

public:
	TerminalWidget(const QSize &frame, QWidget *parent = 0);
	~TerminalWidget();
protected:
	void initWidget();
private:
	//总布局 控制变量声明处
	unique_ptr<QVBoxLayout> mainLayout;
	//row1 控件声明处
	QPushButton *closeBtn;	//关闭按钮
	QPushButton *extendBtn;	//变大按钮
	QPushButton *narrowBtn;	//缩小按钮
	QLabel *logoLabel;			//显示logo
	QLabel *showUserNameLabel;	//显示用户名字，例如：何先生/李女士
	QPushButton *userHeaderBtn;	//用户头像按钮，点击进入用户管理界面

	//row2 控件声明处
	/*您有新消息未查看，此处为自定义控件【暂时未写】*/

	//row3 控件声明处
	/*显示知返，以“花瓣”网站的风格显示，此处为自定义控件*/
	DisplayZhiFanBoard *displayBoard;

	//row4 第一列 控件声明处
	/*搜索控件，自定义控件*/
	SearchWidget *searchFrame;
	//row4 第二列
	QPushButton *publishBtn;	//我要发布 按钮
};

#endif // TERMINALWIDGET_H
