#include "EnemyPlane.h"



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
	setPixmap(p);
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
