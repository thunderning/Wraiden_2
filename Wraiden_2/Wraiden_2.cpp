#include "Wraiden_2.h"

Wraiden_2::Wraiden_2(QWidget *parent)
	: QMainWindow(parent)
{
	ui_start.setupUi(this);
	timer_20 = new QTimer;
	timer_20->start(20);
	timer_2000 = new QTimer;
	timer_2000->start(2000);
	connect(timer_20, SIGNAL(timeout()), this, SLOT(changeBGPic()));
	connect(ui_start.pushButton, SIGNAL(clicked()), this, SLOT(gameStart()));
	gragh = new QGraphicsScene;
}

void Wraiden_2::paintEvent(QPaintEvent * event)
{
	QPixmap tmp("Resources/bgp.jpg");
	QPainter painter(this);
	painter.drawPixmap(0, -bgy, tmp);
	painter.drawPixmap(0, -bgy - 1064, tmp);
}

void Wraiden_2::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		if (!event->isAutoRepeat()) keyUpPressed = true;
		break;
	case Qt::Key_Down:
		if (!event->isAutoRepeat()) keyDownPressed = true;
		break;
	case Qt::Key_Left:
		if (!event->isAutoRepeat()) keyLeftPressed = true;
		break;
	case Qt::Key_Right:
		if (!event->isAutoRepeat()) keyRightPressed = true;
		break;
	default:
		break;
	}
}

void Wraiden_2::keyReleaseEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		if (!event->isAutoRepeat()) keyUpPressed = false;
		break;
	case Qt::Key_Down:
		if (!event->isAutoRepeat()) keyDownPressed = false;
		break;
	case Qt::Key_Left:
		if (!event->isAutoRepeat()) keyLeftPressed = false;
		break;
	case Qt::Key_Right:
		if (!event->isAutoRepeat()) keyRightPressed = false;
		break;
	default:
		break;
	}
}

void Wraiden_2::changeBGPic()
{
	bgy = (bgy - 1) % 1064;
	update();
}

void Wraiden_2::init_mp()
{
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	myplane = new MyPlane(t,1,1);
	myplane->setQuality(MYPLANE);
	gragh->addItem(myplane);
	myplane->setPos(275, 675);
	gragh->setSceneRect(0, 0, 600, 775);
	connect(timer_20, SIGNAL(timeout()), this, SLOT(moveMyplane()));
	connect(timer_2000, SIGNAL(timeout()), this, SLOT(setNewEnemy()));
}

void Wraiden_2::init_bl_temp()
{
}

void Wraiden_2::init_ep_temp()
{
	QTimeLine *tl = new QTimeLine(4000);
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	gia->setTimeLine(tl);
	EnemyPlane *ep = new EnemyPlane(t, 1, 1, 1);
	ep->setPath(gia);
	gia->setItem((QGraphicsItem*)ep);
	gia->setPosAt(0.0, QPointF(0, 0));
	gia->setPosAt(0.5, QPointF(50, 200));
	gia->setPosAt(1.0, QPointF(600, 700));
	ep_template.push_back(gia);
}

void Wraiden_2::gameStart()
{
	ui.setupUi(this);
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	ui.graphicsView->setScene(gragh);
	init_mp();
	init_ep_temp();
	//³¢ÊÔ¶¯»­
}

void Wraiden_2::moveMyplane()
{
	int spd = myplane->get_speed();
	if (keyUpPressed)
	{
		myplane->moveBy(0, -spd);
		if (!myplane->check_out(windwid, windhei))
			myplane->moveBy(0, spd);
	}
	if (keyDownPressed)
	{
		myplane->moveBy(0, spd);
		if (!myplane->check_out(windwid, windhei))
			myplane->moveBy(0, -spd);
	}
	if (keyLeftPressed)
	{
		myplane->moveBy(-spd, 0);
		if (!myplane->check_out(windwid, windhei))
			myplane->moveBy(spd, 0);
	}
	if (keyRightPressed)
	{
		myplane->moveBy(spd, 0);
		if (!myplane->check_out(windwid, windhei))
			myplane->moveBy(-spd, 0);
	}
}

void Wraiden_2::setNewEnemy()
{
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	EnemyPlane *t = (EnemyPlane*)ep_template[0]->item();
	EnemyPlane *ep = new EnemyPlane(t->pixmap(), t->get_life(), t->get_bullet(), t->get_damage());
	ep->setPath(gia);
	gragh->addItem(ep);
	QTimeLine *tl = new QTimeLine(ep_template[0]->timeLine()->duration());
	gia->setTimeLine(tl);
	gia->setItem(ep);
	QList<QPair<qreal, QPointF>> ls = ep_template[0]->posList();
	for (int i = 0; i < ls.size(); i++)
		gia->setPosAt(ls[i].first, ls[i].second);
	enemys.push_back(gia);
	tl->start();
}

void Wraiden_2::hitit()
{
}
