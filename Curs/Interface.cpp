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
	enemy1.loadFromFile("images/enemy1.png"); // загружаем изображение призрака 
	enemy2.loadFromFile("images/enemy2.png"); 
	enemy3.loadFromFile("images/enemy3.png");  
}

Interface::~Interface()
{
};


void Interface::interact(){

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(608, 704, desktop.bitsPerPixel), "PacMan");

	Text text("", font, 20), menu("", font, 30);//создаем объект текст 
	text.setColor(Color::Yellow);//покрасили текст в красный 
	text.setStyle(Text::Bold);//жирный текст. 
	menu.setColor(Color::Yellow);//покрасили текст в красный 
	menu.setStyle(Text::Bold);//жирный текст. 
	Player p(heroImage, 288, 512, 30, 30);//объект класса игрока
	srand(time(0));
	enemy.push_back(new Enemy(enemy1, 288, 288, 32, 32)); //создаем врагов и помещаем в список  
	enemy.push_back(new Enemy(enemy2, 256, 320, 32, 32));
	enemy.push_back(new Enemy(enemy3, 288, 320, 32, 32));

	while (window.isOpen())  { //пока открыто
		if (p.game == true)
		if (Keyboard::isKeyPressed(Keyboard::Enter)){ p.life = true; p.game = false; }
		float time = clock.getElapsedTime().asMicroseconds(); //таймер логики        
		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое врем€
		clock.restart(); //перезапуск таймера
		time = time / 800;

		while (window.pollEvent(event))  //обработчик событий на закрытие
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Q)) window.close();
		}

		p.update(time); //обновление игрока

		if (p.life)
		for (it = enemy.begin(); it != enemy.end(); it++)
		{
			(*it)->update(time); //запускаем метод update()  
		}

		if (p.life == true)
		{//если игрок жив 
			for (it = enemy.begin(); it != enemy.end(); it++)
			{//бежим по списку врагов   
				if ((p.getRect().intersects((*it)->getRect())))
				{
					p.life = false;
					std::cout << "Game over";
				}
			}
		}

		window.clear();

		for (int i = 0; i < 22; i++)//отрисовка карты по шаблону из map.cpp
		for (int j = 0; j < 19; j++)
		{
			if (inter.TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));   //если пусто, то рисовать блок земли
			if (inter.TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));  //если точка, то рисовать кружок
			if ((inter.TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32)); //если преп€тствие, то рисовать блок стены

			s_map.setPosition(j * 32, i * 32);
			window.draw(s_map);   //рисовать
		}

		std::ostringstream playerScoreString, gameTimeString;
		playerScoreString << p.getScore(); gameTimeString << gameTime;//ѕолучаем счЄт и врем€ в игре
		text.setString("Score: " + playerScoreString.str() + "                                                                             Time: " + gameTimeString.str());//задаем строку тексту  
		text.setPosition(5, 2);//задаем позицию текста  
		window.draw(text);//рисуем этот текст 
		if (p.game){
			menu.setString("Press ENTER for start");
			menu.setPosition(100, 315);//задаем позицию текста  
			window.draw(menu);//рисуем этот текст
		}
		if ((!p.life) && (!p.game)){
			menu.setString("Press Q for exit");
			menu.setPosition(150, 315);//задаем позицию текста  
			window.draw(menu);//рисуем этот текст
		}
		window.draw(p.sprite);//рисуем спрайт ѕакћэна  
		for (it = enemy.begin(); it != enemy.end(); it++)
		{
			window.draw((*it)->sprite); //рисуем призраков
		}
		window.display();
	}

}