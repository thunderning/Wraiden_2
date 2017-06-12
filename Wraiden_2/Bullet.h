#pragma once
#include "Item.h"
class Bullet :
	public Item
{
protected:
	int damage;  //伤害      
	int speed;  //速度，每x次计数移动一格，值越大速度越慢
	int from;  //子弹源头，0表示我方，1表示敌方
	int direction;  //方向 1 左上； 2 正上； 3 右上；
					//    -1 左下；-2 正下；-3 右下；
public:
	bool fly_by_direction(int k, int l, int h);
	void change_xy(int px, int py);
	int get_speed();
	int get_damage();
	//int set(int t, vector<vector<char>>& output, vector<vector<int>>& quality, vector<vector<int>>& source);
	Bullet(int dmg, int spd, int frm, int drt, int x, int y, int len, int hei, char *p);
	Bullet();
	~Bullet();
};

