#include "stdafx.h"
#include "Entity.h"
using namespace sf;

Entity::Entity(Image &image, float X, float Y, int W, int H)
{
	x = X; y = Y;
	w = W; h = H;
	dx = 0.1; dy = 0.1; //изменение координат
	speed = 0.1; //скорость 
	CurrentFrame = 0;
	life = true; //герой по умолчанию жив
	texture.loadFromImage(image); //изображение сущности   
	sprite.setTexture(texture); //заливка спрайта дял сущности
}


