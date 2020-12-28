#ifndef INTERFACE_H   
#define INTERFACE_H  
#include "Enemy.h"
#include "Player.h"
#include "Entity.h"
#include "Player.h"
#include "stdafx.h"

using namespace sf;
class Interface
{
private:
	Player* p;
	Font font;//Ўрифт дл€ строк
	Texture map;//текстура карты  
	Sprite s_map;//спрайт карты  
	Clock clock, gameTimeClock;  //таймеры
	int gameTime; //игровое врем€
	Map inter;
	Event event;
	Image map_image, heroImage, enemy1, enemy2, enemy3;
	std::list<Entity*>  enemy; //список врагов         
	std::list<Entity*>::iterator it; //итератор дл€ списка врагов
public:
	Interface();
	~Interface();
	void interact(); //интерфейс программы
};

#endif
