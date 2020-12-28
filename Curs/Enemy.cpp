#pragma once
#include "stdafx.h"
#include "Enemy.h"
using namespace sf;

Enemy::Enemy(Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H)
{
	sprite.setTextureRect(IntRect(0, 0, w, h));
	direction = rand() % (3);   //случайное направление
	speed = 0.1; //скорость
	dx = speed;
}
