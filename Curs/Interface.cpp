#include "stdafx.h" 
#include "Interface.h" 
#include "Player.h" 
#include "Entity.h"
#include "Enemy.h" 
using namespace sf;


Interface::Interface(){
	font.loadFromFile("fonts/Strenuous.ttf");//��������� ������
	map_image.loadFromFile("images/map.png");//��������� ���� � ��������� ����� 
	map.loadFromImage(map_image);//�������� �������� ����� �� ��������
	s_map.setTexture(map);//������������� �������� �����
	gameTime = 0;//������ �������� �������   
	heroImage.loadFromFile("images/hero.png"); // ��������� ����������� �������
	enemy1.loadFromFile("images/enemy1.png"); // ��������� ����������� �������� 
	enemy2.loadFromFile("images/enemy2.png"); 
	enemy3.loadFromFile("images/enemy3.png");  
}

Interface::~Interface()
{
};


void Interface::interact(){

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(608, 704, desktop.bitsPerPixel), "PacMan");

	Text text("", font, 20);//������� ������ ����� 
	text.setColor(Color::Yellow);//��������� ����� � ������� 
	text.setStyle(Text::Bold);//������ �����. 

	Player p(heroImage, 288, 512, 30, 30);//������ ������ ������
	srand(time(0));
	enemy.push_back(new Enemy(enemy1, 288, 288, 32, 32)); //������� ������ � �������� � ������  
	enemy.push_back(new Enemy(enemy2, 256, 320, 32, 32));
	enemy.push_back(new Enemy(enemy3, 288, 320, 32, 32));

	while (window.isOpen())  { //���� �������
		float time = clock.getElapsedTime().asMicroseconds(); //������ ������        
		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();//������� �����
		clock.restart(); //���������� �������
		time = time / 800;

		while (window.pollEvent(event))  //���������� ������� �� ��������
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		p.update(time); //���������� ������

		if (p.life)
		for (it = enemy.begin(); it != enemy.end(); it++)
		{
			(*it)->update(time); //��������� ����� update()  
		}

		if (p.life == true)
		{//���� ����� ��� 
			for (it = enemy.begin(); it != enemy.end(); it++)
			{//����� �� ������ ������   
				if ((p.getRect().intersects((*it)->getRect())))
				{
					p.life = false;
					std::cout << "���������";
				}
			}
		}

		window.clear();

		for (int i = 0; i < 22; i++)//��������� ����� �� ������� �� map.cpp
		for (int j = 0; j < 19; j++)
		{
			if (inter.TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));   //���� �����, �� �������� ���� �����
			if (inter.TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));  //���� �����, �� �������� ������
			if ((inter.TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32)); //���� �����������, �� �������� ���� �����

			s_map.setPosition(j * 32, i * 32);
			window.draw(s_map);   //��������
		}

		std::ostringstream playerScoreString, gameTimeString;
		playerScoreString << p.getScore(); gameTimeString << gameTime;//�������� ���� � ����� � ����
		text.setString("Score: " + playerScoreString.str() + "                                                                             Time: " + gameTimeString.str());//������ ������ ������  
		text.setPosition(5, 2);//������ ������� ������  
		window.draw(text);//������ ���� ����� 

		window.draw(p.sprite);//������ ������ �������  
		for (it = enemy.begin(); it != enemy.end(); it++)
		{
			window.draw((*it)->sprite); //������ ���������
		}
		window.display();
	}

}