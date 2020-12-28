#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "stdafx.h"
#include "Entity.h"

using namespace sf;

class Player :public Entity {
private:
	int  playerScore;	//Очки игрока
	int dir; //Направление
public:
	Player(Image &image, float X, float Y, int W, int H);  //конструктор класса image - изображение игрока, X Y координаты игрока, W H высота и ширина модели игрока
	int getScore(); //геттер для playerScore
	void setScore(int);  //сеттер для playerScore
	void control(); // метод  управления игроком
	void checkCollisionWithMap(float Dx, float Dy); //Проверка столкновение с препядствиями на карте
	void update(float time); //Обновление состояния игрока
};
#endif