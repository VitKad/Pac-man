#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "stdafx.h"
#include "Entity.h"
class Enemy :public Entity{  //�������� ����� �����, �������� �� ������ ��������
public:
	float yy, xx;
	int direction;//����������� ����� 
	Enemy(Image &image, float X, float Y, int W, int H);
	void checkCollisionWithMap(float Dx, float Dy); //����� �������� �� ������������
	void update(float time);//����� ���������� ��������� �����

};

#endif;