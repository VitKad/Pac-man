#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "stdafx.h"
#include "map.h"
class Entity {  ///Класс сущности//
protected:
	enum { left, right, up, down } state; //определяет состояние объекта 
	float dx, dy, x, y, speed;  //dx,dy изменение направления, x,y координаты, speed скорость изменения
	int w, h, stone; //w-ширина, h-длина нашей сущности
	Texture texture;//текстура сущности
	Map mp; //объект класса карта
	float CurrentFrame;//текущий кадр  

public:
	bool life; //переменная жизни
	Sprite sprite;//спрайт сущности   
	Entity(Image &image, float X, float Y, int W, int H);//конструктор
	FloatRect getRect() //получение прямуоголника (координаты и размеры)
	{
		FloatRect FR(x, y, w, h); 
		return FR;  
	}
	virtual void update(float time) = 0; //метод обновления
};




#endif