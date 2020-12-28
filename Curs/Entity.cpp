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
	life = true; //����� �� ��������� ���
	texture.loadFromImage(image); //����������� ��������   
	sprite.setTexture(texture); //������� ������� ��� ��������
}


