#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "stdafx.h"
#include "Entity.h"

using namespace sf;

class Player :public Entity {
private:
	int  playerScore;	//���� ������
	int dir; //�����������
public:
	Player(Image &image, float X, float Y, int W, int H);  //����������� ������ image - ����������� ������, X Y ���������� ������, W H ������ � ������ ������ ������
	int getScore(); //������ ��� playerScore
	void setScore(int);  //������ ��� playerScore
	void control(); // �����  ���������� �������
	void checkCollisionWithMap(float Dx, float Dy); //�������� ������������ � ������������� �� �����
	void update(float time); //���������� ��������� ������
};
#endif