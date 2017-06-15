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
#include <QVector>
#include <QString>
#include "ui_Wraiden_2.h"
#include "ui_StartPage.h"
//#include "Item.h"
#include "MyPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"

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
	QGraphicsPixmapItem* a;
	QGraphicsItemAnimation* gia;
	QTimeLine *tl;
	QVector<QGraphicsItemAnimation*> bl_template;
	QVector<QGraphicsItemAnimation*> ep_template;
	void init_mp();
	void init_bl_temp();
	void init_ep_temp();
	void addTempleToBl(int time,QString picPath,QList<QPair<qreal, QPointF>> pathPoint, QTimeLine::CurveShape mode, int dmg);
	void addTempleToEP(int time, QString picPath, QList<QPair<qreal, QPointF>> pathPoint, QTimeLine::CurveShape mode, int dmg, int life,int blt,int lspd);
	void addBltoGragh(Plane *plane, int quality);
	void addEptoGragh(int num, QPointF position);
	void collidChange(Item *it,int quality);
private slots:
	void changeBGPic();
	void gameStart();
	void moveMyplane();
	void launchBullet();
	void setNewEnemy();
	void deleteItems();
	void time20CountPlus();
	void time1000CountPlus();
	void checkCollid();
protected:
	int bgy = 0;
	QGraphicsScene *gragh;
	QTimer *timer_20;
	QTimer *timer_1000;
	MyPlane *myplane;
	int time_20_count = 0;
	int time_1000_count = 0;
	QVector<QGraphicsItemAnimation*> bullets;
	QVector<QGraphicsItemAnimation*> enemys;
	enum MyEnum
	{
		MYPLANE, MYBULLET, ENEMYPLANE, ENEMYBULLET, SUPPORT
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
