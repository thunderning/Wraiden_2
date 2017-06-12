#include "Wraiden_2.h"

Wraiden_2::Wraiden_2(QWidget *parent)
	: QMainWindow(parent)
{
	ui_start.setupUi(this);
	timer_20 = new QTimer;
	timer_20->start(20);
	connect(timer_20, SIGNAL(timeout()), this, SLOT(changeBGPic()));
	connect(ui_start.pushButton, SIGNAL(clicked()), this, SLOT(gameStart()));
	connect(timer_20, SIGNAL(timeout()), this, SLOT(moveMyplane()));
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	gragh = new QGraphicsScene;
	myplane = new MyPlane(t);
	myplane->setQuality(MYPLANE);
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

void Wraiden_2::gameStart()
{
	ui.setupUi(this);
	QGraphicsScene *gt = new QGraphicsScene;
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	gt->addItem(myplane);
	myplane->setPos(275, 675);
	ui.graphicsView->setScene(gt);
	gt->setSceneRect(0, 0, 600, 775);
	//³¢ÊÔ¶¯»­
	QGraphicsItemAnimation* gia=new QGraphicsItemAnimation;
	QGraphicsPixmapItem* a = new QGraphicsPixmapItem(t);
	gt->addItem(a);
	gia->setItem(a);
	QTimeLine *tl=new QTimeLine(4000);
	gia->setTimeLine(tl);
	for (int i = 0; i < 40; i++)
		gia->setPosAt(i / 40.0, QPointF(i, ((i-50)*(i-50)-100)/10));
	tl->start();
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
