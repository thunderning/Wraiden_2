#ifndef WRAIDEN_2_H
#define WRAIDEN_2_H


#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <QPointF>
#include <QRectF>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "ui_Wraiden_2.h"
#include "ui_StartPage.h"
//#include "Item.h"
#include "MyPlane.h"

class Wraiden_2 : public QMainWindow
{
	Q_OBJECT

public:
	Wraiden_2(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	int windwid = 600;
	int windhei = 775;
private slots:
	void changeBGPic();
	void gameStart();
	void moveMyplane();
protected:
	int bgy = 0;
	QGraphicsScene *gragh;
	QTimer *timer_20;
	MyPlane *myplane;
	enum MyEnum
	{
		MYPLANE, MYBULLET, ENTMYPLANE, ENEMYBULLET, SUPPORT
	};
	bool keyUpPressed = false;
	bool keyDownPressed = false;
	bool keyLeftPressed = false;
	bool keyRightPressed = false;
private:
	Ui::Wraiden_2Class ui;
	Ui::StartPage ui_start;
};
#endif // !WRAIDEN_2_H
