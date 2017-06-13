#include "Plane.h"



Plane::Plane()
{
}


Plane::~Plane()
{
}

int Plane::get_life()
{
	return life;
}

int Plane::get_speed()
{
	return move_speed;
}

int Plane::get_bullet()
{
	return bullet;
}
