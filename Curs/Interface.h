#ifndef INTERFACE_H   
#define INTERFACE_H  
#include "Enemy.h"
#include "Entity.h"
#include "stdafx.h"

using namespace sf;
class Interface
{
private:
	Font font;//����� ��� �����
	Image map_image, heroImage;  //����������� ����� � �����
	Texture map;//�������� �����  
	Sprite s_map;//������ �����  
	Clock clock, gameTimeClock;  //�������
	int gameTime; //������� �����
	Map inter;
public:
	Interface();
	~Interface();
	void interact(); //��������� ���������
};

#endif
