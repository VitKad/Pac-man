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
{ //При нажатии на одну из клавиш, меняется направление движения по координате
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
	for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты   
	for (int j = x / 32; j<(x + w) / 32; j++)
	{
		if (mp.TileMap[i][j] == '0')//если естена
		{
			if ((Dy > 0) && (dir == 2)) { y = i * 32 - h;  dy = 0; }//по Y     
			if ((Dy < 0) && (dir == 2)){ y = i * 32 + 32; dy = 0; }//столкновение с верхними краями     
			if ((Dx > 0) && (dir == 1)) { x = j * 32 - w; dx = 0; }//с правым краем карты     
			if ((Dx < 0) && (dir == 1)) { x = j * 32 + 32; dx = 0; }// с левым краем карты    
		}
		if (mp.TileMap[i][j] == 's')
		{
			setScore(playerScore++); //Добавлени очки игроку
			mp.TileMap[i][j] = ' ';
		}
	}
}