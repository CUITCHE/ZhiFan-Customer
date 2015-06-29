#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H
/*!
 * \file TerminalWidget.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �������������
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
	//�ܲ��� ���Ʊ���������
	unique_ptr<QVBoxLayout> mainLayout;
	//row1 �ؼ�������
	QPushButton *closeBtn;	//�رհ�ť
	QPushButton *extendBtn;	//���ť
	QPushButton *narrowBtn;	//��С��ť
	QLabel *logoLabel;			//��ʾlogo
	QLabel *showUserNameLabel;	//��ʾ�û����֣����磺������/��Ůʿ
	QPushButton *userHeaderBtn;	//�û�ͷ��ť����������û��������

	//row2 �ؼ�������
	/*��������Ϣδ�鿴���˴�Ϊ�Զ���ؼ�����ʱδд��*/

	//row3 �ؼ�������
	/*��ʾ֪�����ԡ����ꡱ��վ�ķ����ʾ���˴�Ϊ�Զ���ؼ�*/
	DisplayZhiFanBoard *displayBoard;

	//row4 ��һ�� �ؼ�������
	/*�����ؼ����Զ���ؼ�*/
	SearchWidget *searchFrame;
	//row4 �ڶ���
	QPushButton *publishBtn;	//��Ҫ���� ��ť
};

#endif // TERMINALWIDGET_H
