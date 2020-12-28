#include "stdafx.h"
#include "Player.h"

using namespace sf;

Player::Player(Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H)
{
	playerScore = 0;
	state = right;
	dir = 1;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}

int Player::getScore()
{
	return(playerScore);
}

void Player::setScore(int score)
{
	playerScore = score;
}

void Player::control()
{ //��� ������� �� ���� �� ������, �������� ����������� �������� �� ����������
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		dx = -0.1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		dx = 0.1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		dy = -0.1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		dy = 0.1;
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy)
{
	for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����   
	for (int j = x / 32; j<(x + w) / 32; j++)
	{
		if (mp.TileMap[i][j] == '0')//���� ������
		{
			if ((Dy > 0) && (dir == 2)) { y = i * 32 - h;  dy = 0; }//�� Y     
			if ((Dy < 0) && (dir == 2)){ y = i * 32 + 32; dy = 0; }//������������ � �������� ������     
			if ((Dx > 0) && (dir == 1)) { x = j * 32 - w; dx = 0; }//� ������ ����� �����     
			if ((Dx < 0) && (dir == 1)) { x = j * 32 + 32; dx = 0; }// � ����� ����� �����    
		}
		if (mp.TileMap[i][j] == 's')
		{
			setScore(++playerScore); //��������� ���� ������
			mp.TileMap[i][j] = ' ';
		}
	}
}

void Player::update(float time)//����� "���������/����������" ������� ������.  
{
	if (life)
	{//���������, ��� �� ����� 
		control();
		x += dx*time; //�������� �� �X�    
		dir = 1;
		checkCollisionWithMap(dx, 0);//������������ ������������ �� �   
		y += dy*time; //�������� �� �Y�   
		dir = 2;
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y 

		if (dx > 0)	{//��������� ���� ������    

			dx = speed;
			dy = 0;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
		}
		if (dx < 0)
		{//��������� ���� �����    
			dx = -speed;
			dy = 0;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(32 * int(CurrentFrame) + 32, 0, -32, 32));
		}
		if (dy < 0)
		{//���� �����    
			dy = -speed;
			dx = 0;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
		}
		if (dy > 0)
		{//���� ����    
			dy = speed;
			dx = 0;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
		}
	}
	sprite.setPosition(x, y); //������ � ������� (x, y). 		  
}