#include "stdafx.h" 
#include "Interface.h" 
#include "Player.h" 
#include "Entity.h"
#include "Enemy.h" 
using namespace sf;


Interface::Interface(){
	font.loadFromFile("fonts/Strenuous.ttf");//��������� ������
	map_image.loadFromFile("images/map.png");//��������� ���� � ��������� ����� 
	map.loadFromImage(map_image);//�������� �������� ����� �� ��������
	s_map.setTexture(map);//������������� �������� �����
	gameTime = 0;//������ �������� �������   
	heroImage.loadFromFile("images/hero.png"); // ��������� ����������� �������
}

Interface::~Interface()
{
};