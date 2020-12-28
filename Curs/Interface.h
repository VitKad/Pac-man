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
	Font font;//����� ��� �����
	Texture map;//�������� �����  
	Sprite s_map;//������ �����  
	Clock clock, gameTimeClock;  //�������
	int gameTime; //������� �����
	Map inter;
	Event event;
	Image map_image, heroImage, enemy1, enemy2, enemy3;
	std::list<Entity*>  enemy; //������ ������         
	std::list<Entity*>::iterator it; //�������� ��� ������ ������
public:
	Interface();
	~Interface();
	void interact(); //��������� ���������
};

#endif
