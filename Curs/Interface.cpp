#include "stdafx.h" 
#include "Interface.h" 
#include "Player.h" 
#include "Entity.h"
#include "Enemy.h" 
using namespace sf;


Interface::Interface(){
	font.loadFromFile("fonts/Strenuous.ttf");//установка шрифта
	map_image.loadFromFile("images/map.png");//загружаем файл с текстурой карты 
	map.loadFromImage(map_image);//зар€жаем текстуру карты из картинки
	s_map.setTexture(map);//устанавливаем текстуру карты
	gameTime = 0;//начало игрового времени   
	heroImage.loadFromFile("images/hero.png"); // загружаем изображение ѕакћэна
}

Interface::~Interface()
{
};