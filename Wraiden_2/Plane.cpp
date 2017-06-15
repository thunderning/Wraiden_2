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

int Plane::get_launchSpeed()
{
	return launch_speed;
}

int Plane::get_bullet()
{
	return bullet;
}

void Plane::set_bullet(int blt)
{
	bullet = blt;
}

void Plane::set_lauchSpeed(int spd)
{
	launch_speed = spd;
}

int Plane::change_life(int dmg)
{
	life -= dmg;
	return life;
}
