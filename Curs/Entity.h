#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "stdafx.h"
#include "map.h"
class Entity {  ///Класс сущности//
protected:
	float dx, dy, x, y, speed;  //dx,dy изменение направления, x,y координаты, speed скорость изменения
	int w, h; //w-ширина, h-длина нашей сущности
	Texture texture;//текстура сущности
	Map mp; //объект класса карта
	float CurrentFrame;//текущий кадр  
	bool life; //переменная жизни
	bool game;
public:
	Sprite sprite;//спрайт сущности   
	Entity(Image &image, float X, float Y, int W, int H);//конструктор
	FloatRect getRect() //получение прямуоголника (координаты и размеры)
	{
		FloatRect FR(x, y, w, h); 
		return FR;  
	}
	bool getLife();
	void setLife(bool l);
	bool getGame();
	void setGame(bool l);
	virtual void update(float time) = 0; //метод обновления
};




#endif