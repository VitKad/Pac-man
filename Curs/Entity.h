#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "stdafx.h"
#include "map.h"
class Entity {  ///����� ��������//
protected:
	float dx, dy, x, y, speed;  //dx,dy ��������� �����������, x,y ����������, speed �������� ���������
	int w, h, stone; //w-������, h-����� ����� ��������
	Texture texture;//�������� ��������
	Map mp; //������ ������ �����
	float CurrentFrame;//������� ����  

public:
	bool life; //���������� �����
	bool game;
	Sprite sprite;//������ ��������   
	Entity(Image &image, float X, float Y, int W, int H);//�����������
	FloatRect getRect() //��������� ������������� (���������� � �������)
	{
		FloatRect FR(x, y, w, h); 
		return FR;  
	}
	virtual void update(float time) = 0; //����� ����������
};




#endif