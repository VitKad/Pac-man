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
}

Interface::~Interface()
{
};


void Interface::interact(){

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(608, 704, desktop.bitsPerPixel), "PacMan");
	Player p(heroImage, 288, 512, 30, 30);//������ ������ ������
	srand(time(0));
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
		window.clear();
		for (int i = 0; i < 22; i++)
		for (int j = 0; j < 19; j++)
		{
			if (inter.TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));   //���� �����, �� �������� ���� �����
			if ((inter.TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32)); //���� �����������, �� �������� ���� �����

			s_map.setPosition(j * 32, i * 32);
			window.draw(s_map);   //��������
		}
		window.draw(p.sprite);//������ ������ ������� �p� ������ �Player�   
		window.display();
	}

}