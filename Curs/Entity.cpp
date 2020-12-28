#include "stdafx.h"
#include "Entity.h"
using namespace sf;

Entity::Entity(Image &image, float X, float Y, int W, int H)
{
	x = X; y = Y;
	w = W; h = H;
	dx = 0.1; dy = 0.1; //��������� ���������
	speed = 0.1; //�������� 
	CurrentFrame = 0;
	life = false; //����� �� ��������� ���
	game = true;
	texture.loadFromImage(image); //����������� ��������   
	sprite.setTexture(texture); //������� ������� ��� ��������
}

bool Entity::getLife(){
	return life;
}


void Entity::setLife(bool l){
	life = l;
}

bool Entity::getGame(){
	return game;
}


void Entity::setGame(bool l){
	game = l;
}