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

void Enemy::checkCollisionWithMap(float Dx, float Dy)//проверка на препятствие
{
	for (int i = y / 32; i < (y + h) / 32; i++)//цикл проверки следующих элементов 
	for (int j = x / 32; j<(x + w) / 32; j++)
	{
		if (mp.TileMap[i][j] == '0')//если впереди препятствие
		{//в соответствие с выбранным направлением перемещает на предыдущий элемент
			if (Dy > 0) { 
				y = i * 32 - h;  dy = -0.1;
				direction = rand() % (3); //случайное направление    
			}//по Y    
			if (Dy < 0) {
				y = i * 32 + 32; dy = 0.1;
				direction = rand() % (3); 
			}   
			if (Dx > 0) {
				x = j * 32 - w; dx = -0.1;
				direction = rand() % (3);     
			} 
			if (Dx < 0) {
				x = j * 32 + 32; dx = 0.1;
				direction = rand() % (3);
			}

		}
	}
}



void Enemy::update(float time)
{
	if (life)  //если герой все еще жив
	{ 
		switch (direction) //выбор направления
		{
		case 0:
		{//вправо
				  dx = speed; //скорость по х
				  dy = 0; //скорость по у
				  CurrentFrame += 0.005*time; //просчтет кадров
				  if (CurrentFrame > 3) CurrentFrame -= 3;//если достигнет 3, то рисовать спрайт заново
				  sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				  break;
		}
		case 1:
		{//влево  
				  dx = -speed;
				  dy = 0;
				  CurrentFrame += 0.005*time;
				  if (CurrentFrame > 3) CurrentFrame -= 3;
				  sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				  break;
		}
		case 2:
		{//вверх  
				  dy = -speed;
				  dx = 0;
				  CurrentFrame += 0.005*time;
				  if (CurrentFrame > 3) CurrentFrame -= 3;
				  sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				  break;
		}
		case 3:
		{//вниз
				  dy = speed;
				  dx = 0;
				  CurrentFrame += 0.005*time;
				  if (CurrentFrame > 3) CurrentFrame -= 3;
				  sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				  break;
		}
		}

		x += dx*time; //движение по х  
		checkCollisionWithMap(dx, 0);//обработка препятствия
		y += dy*time; //движение по у
		checkCollisionWithMap(0, dy);
		sprite.setPosition(x, y); 
	}

}

