#include "Wraiden_2.h"

Wraiden_2::Wraiden_2(QWidget *parent)
	: QMainWindow(parent)
{
	ui_start.setupUi(this);
	timer_20 = new QTimer;
	timer_20->start(20);
	timer_1000 = new QTimer;  //用以生成敌机
	timer_1000->start(1000);
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
	myplane->set_bullet(0);
	connect(timer_20, SIGNAL(timeout()), this, SLOT(moveMyplane()));
	connect(timer_1000, SIGNAL(timeout()), this, SLOT(setNewEnemy()));
	connect(timer_20, SIGNAL(timeout()), this, SLOT(deleteItems()));
}

void Wraiden_2::init_bl_temp()
{
	QList<QPair<qreal, QPointF>> ls;
	ls.push_back(QPair<qreal, QPointF>(1.0, QPointF(0, -700)));
	addTempleToBl(2000, "Resources/bullet/img_bullet 1_14.PNG", ls, QTimeLine::LinearCurve,1);
	ls.clear();
	for(int i=0;i<40;i++)
		ls.push_back(QPair<qreal, QPointF>(i/40.0, QPointF(0, 700/40*i)));
	//ls.push_back(QPair<qreal, QPointF>(0.1, QPointF(0, 300)));
	//ls.push_back(QPair<qreal, QPointF>(1.0, QPointF(0, 700)));
	addTempleToBl(2000, "Resources/bullet/img_bullet 1_12.PNG", ls, QTimeLine::LinearCurve,1);
}

void Wraiden_2::init_ep_temp()
{
	QList<QPair<qreal, QPointF>> ls;
	//ls.push_back(QPair<qreal, QPointF>(0.3, QPointF(100, 200)));
	for (int i = 0; i < 60; i++)
		ls.push_back(QPair<qreal, QPointF>(i / 60.0, QPointF(10 * i,0 )));
	addTempleToEP(8000, "Resources/RedCruiserSpaceShip-by-MillionthVector/redshipr.png", ls,QTimeLine::LinearCurve,1,1,1,20);
}

void Wraiden_2::addTempleToBl(int time, QString picPath, QList<QPair<qreal, QPointF>> pathPoint, QTimeLine::CurveShape mode,int dmg)
{
	QTimeLine *tl = new QTimeLine(time);
	QPixmap t(picPath);
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	tl->setCurveShape(mode);
	gia->setTimeLine(tl);
	Bullet *bl = new Bullet(t, dmg);
	bl->setPath(gia);
	gia->setItem((QGraphicsItem*)bl);
	for (int i = 0; i < pathPoint.size(); i++)
		gia->setPosAt(pathPoint[i].first, pathPoint[i].second);
	bl_template.push_back(gia);
}

void Wraiden_2::addTempleToEP(int time, QString picPath, QList<QPair<qreal, QPointF>> pathPoint, QTimeLine::CurveShape mode, int dmg, int life, int blt,int lspd)
{
	QTimeLine *tl = new QTimeLine(time);
	QPixmap t(picPath);
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	tl->setCurveShape(mode);
	gia->setTimeLine(tl);
	EnemyPlane *ep = new EnemyPlane(t,life,blt,dmg);
	ep->set_lauchSpeed(lspd);
	ep->setPath(gia);
	gia->setItem((QGraphicsItem*)ep);
	for (int i = 0; i < pathPoint.size(); i++)
		gia->setPosAt(pathPoint[i].first, pathPoint[i].second);
	ep_template.push_back(gia);
}

void Wraiden_2::addBltoGragh(Plane * plane, int quality)
{
	if (time_20_count%plane->get_launchSpeed() != 0)
		return;
	int blt = plane->get_bullet();
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	Bullet *t = (Bullet*)bl_template[blt]->item();
	Bullet *bl = new Bullet(t->pixmap(), t->get_damage()); //创建新子弹对象
	bl->setQuality(quality);                               //设置属性
	QTimeLine *tl = new QTimeLine(bl_template[blt]->timeLine()->duration());             //创建时间线对象
	tl->setCurveShape(bl_template[blt]->timeLine()->curveShape());  //设置时间线形状
	QList<QPair<qreal, QPointF>> ls = bl_template[blt]->posList();  //拷贝路径
	QPointF posBy;
	if (quality == MYBULLET)
	{
		posBy.setX(plane->pixmap().width() / 2 - t->pixmap().width() / 2);
		posBy.setY(-t->pixmap().height());
	}
	else
	{
		posBy.setX(plane->pixmap().width() / 2 - t->pixmap().width() / 2);
		posBy.setY(plane->pixmap().height());
	}
	bl->setPos(plane->pos() + posBy);
	for (int i = 0; i < ls.size(); i++)
		gia->setPosAt(ls[i].first, bl->pos() + ls[i].second);
	bl->setQuality(quality);
	gia->setItem(bl);                                          //为路径添加元素
	gia->setTimeLine(tl);                                      //为路径添加时间线
	bl->setPath(gia);                                          //设置路径指针
	gragh->addItem(bl);                                        //添加到图中
	bullets.push_back(gia);                                     //动画添加进接口
	tl->setCurveShape(QTimeLine::LinearCurve);
	tl->start();                                               //时间线启动
	connect(tl, SIGNAL(finished()), bl, SLOT(deleteItem()));   //连接结束自动删除
}

void Wraiden_2::addEptoGragh(int num, QPointF position)
{
	QGraphicsItemAnimation *gia = new QGraphicsItemAnimation;
	EnemyPlane *t = (EnemyPlane*)ep_template[num]->item();
	EnemyPlane *ep = new EnemyPlane(t->pixmap(), t->get_life(), t->get_bullet(), t->get_damage()); //创建新敌机对象
	ep->set_lauchSpeed(t->get_launchSpeed());
	QTimeLine *tl = new QTimeLine(ep_template[num]->timeLine()->duration());             //创建时间线对象
	tl->setCurveShape(ep_template[num]->timeLine()->curveShape());
	QList<QPair<qreal, QPointF>> ls = ep_template[num]->posList();  //拷贝路径
	for (int i = 0; i < ls.size(); i++)
		gia->setPosAt(ls[i].first, position+ls[i].second);
	ep->setQuality(ENEMYPLANE);
	gia->setItem(ep);                                          //为路径添加元素
	gia->setTimeLine(tl);                                      //为路径添加时间线
	ep->setPath(gia);                                          //设置路径指针
	gragh->addItem(ep);                                        //添加到图中
	enemys.push_back(gia);                                     //动画添加进接口
	tl->start();                                               //时间线启动
	connect(tl, SIGNAL(finished()), ep, SLOT(deleteItem()));   //连接结束自动删除
}

void Wraiden_2::collidChange(Item * it, int quality)
{
	if (quality==MYPLANE)
	{
		QList<QGraphicsItem*> ls;
		ls=gragh->collidingItems(it);
		if (ls.isEmpty()) 
			return;
		else
		{
			MyPlane *mp = (MyPlane *)it;
			for (int i = 0; i < ls.size(); i++)
			{
				if (((Item *)ls[i])->getQuality() == ENEMYPLANE)
				{
					EnemyPlane *ep = (EnemyPlane *)ls[i];
					if (mp->change_life(ep->get_damage()) <= 0)
					{
						//mp->deleteit();
						timer_20->stop();
						return;
					}
					ep->deleteit();
				}
				else if (((Item *)ls[i])->getQuality() == ENEMYBULLET)
				{
					Bullet *bl = (Bullet *)ls[i];
					if (mp->change_life(bl->get_damage()) <= 0)
					{
						//mp->deleteit();
						timer_20->stop();
						return;
					}
					bl->deleteit();
				}
			}
		}
	}
	else if (quality == ENEMYPLANE)
	{
		QList<QGraphicsItem*> ls;
		ls = gragh->collidingItems(it);
		if (ls.isEmpty())
			return;
		else
		{
			EnemyPlane *ep = (EnemyPlane *)it;
			for (int i = 0; i < ls.size(); i++)
			{
				if (((Item *)ls[i])->getQuality() == MYBULLET)
				{
					Bullet *bl = (Bullet *)ls[i];
					if (ep->change_life(bl->get_damage()) <= 0)
					{
						ep->deleteit();
						//timer_20->stop();
						return;
					}
					bl->deleteit();
				}
			}
		}
	}
}

void Wraiden_2::gameStart()
{
	ui.setupUi(this);
	QPixmap t("Resources/BlueFighterSpaceship-by-MillionthVector/blueships1.png");
	ui.graphicsView->setScene(gragh);
	init_mp();
	init_ep_temp();
	init_bl_temp();
	connect(timer_20, SIGNAL(timeout()), this, SLOT(time20CountPlus()));
	connect(timer_1000, SIGNAL(timeout()), this, SLOT(time1000CountPlus()));
	connect(timer_20, SIGNAL(timeout()), this, SLOT(launchBullet()));
	connect(timer_20, SIGNAL(timeout()), this, SLOT(checkCollid()));
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
	if(time_1000_count%2==0)
		addEptoGragh(0, QPointF(0, 0));
}

void Wraiden_2::deleteItems()
{
	for (int i = 0; i < enemys.size(); i++)
	{
		QGraphicsItemAnimation *gia = enemys[i];
		Item *ep = (Item *)gia->item();
		if (!ep->is_exist())
		{
			gragh->removeItem(ep);
			delete gia->timeLine();
			delete ep;
			delete gia;
			enemys.remove(i);
			i--;
		}
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		QGraphicsItemAnimation *gia = bullets[i];
		Item *bl = (Item *)gia->item();
		if (!bl->is_exist())
		{
			gragh->removeItem(bl);
			delete gia->timeLine();
			delete bl;
			delete gia;
			bullets.remove(i);
			i--;
		}
	}
}

void Wraiden_2::time20CountPlus()
{
	time_20_count++;
}

void Wraiden_2::time1000CountPlus()
{
	time_1000_count++;
}

void Wraiden_2::checkCollid()
{
	for (int i = 0; i < enemys.size(); i++)
	{
		collidChange((Item *)enemys[i]->item(), ENEMYPLANE);
	}
	collidChange(myplane, MYPLANE);
}

void Wraiden_2::launchBullet()
{
	addBltoGragh(myplane, MYBULLET);
	for(int i=0;i<enemys.size();i++)
		addBltoGragh((Plane *)enemys[i]->item(), ENEMYBULLET);
}
