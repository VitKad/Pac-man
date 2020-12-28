#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "stdafx.h"
#include "Entity.h"
class Enemy :public Entity{  //дочерний класс врага, призрака от класса сущности
private:
	float yy, xx;
	int direction;//Направление врага 
public:
	Enemy(Image &image, float X, float Y, int W, int H);
	void checkCollisionWithMap(float Dx, float Dy); //метод проверки на столкновение
	void update(float time);//метод обновления поведения врага
};

#endif;