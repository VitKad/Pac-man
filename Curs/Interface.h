#ifndef INTERFACE_H   
#define INTERFACE_H  
#include "Enemy.h"
#include "Entity.h"
#include "stdafx.h"

using namespace sf;
class Interface
{
private:
	Font font;//Шрифт для строк
	Image map_image, heroImage;  //Изображение карты и героя
	Texture map;//текстура карты  
	Sprite s_map;//спрайт карты  
	Clock clock, gameTimeClock;  //таймеры
	int gameTime; //игровое время
	Map inter;
	Event event;
	Image map_image, heroImage, enemy1, enemy2, enemy3;
	std::list<Entity*>  enemy; //список врагов         
	std::list<Entity*>::iterator it; //итератор для списка врагов
public:
	Interface();
	~Interface();
	void interact(); //интерфейс программы
};

#endif
