#include "EnemyPlane.h"



QRectF EnemyPlane::boundingRect() const
{
	return QRectF(0, 0, pic.width(), pic.height());
}

void EnemyPlane::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawPixmap(0, 0, pic);
}

void EnemyPlane::setPath(QGraphicsItemAnimation * p)
{
	path = p;
}

QGraphicsItemAnimation * EnemyPlane::getPath()
{
	return path;
}

int EnemyPlane::get_damage()
{
	return damage;
}

EnemyPlane::EnemyPlane(QPixmap & p, int lf, int bulletnum, int dmg)
{
	pic=p;
	life = lf;
	bullet = bulletnum;
	damage = dmg;
}

EnemyPlane::EnemyPlane()
{
}


EnemyPlane::~EnemyPlane()
{
}
