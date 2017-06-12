#pragma once
#include "Item.h"
class Bullet :
	public Item
{
protected:
	int damage;  //�˺�      
	int speed;  //�ٶȣ�ÿx�μ����ƶ�һ��ֵԽ���ٶ�Խ��
	int from;  //�ӵ�Դͷ��0��ʾ�ҷ���1��ʾ�з�
	int direction;  //���� 1 ���ϣ� 2 ���ϣ� 3 ���ϣ�
					//    -1 ���£�-2 ���£�-3 ���£�
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

