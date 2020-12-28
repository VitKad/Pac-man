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

void Player::control(){ //При нажатии на одну из клавиш, меняется направление движения по координате

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