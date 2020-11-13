#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Model.png");
		
	Player player(&playerTexture, sf::Vector2u(3, 4), 0.25f, 100.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}

		//view.setCenter(player.GetPosition());
		player.Update(deltaTime);
		

		window.clear(sf::Color(100, 100, 100));
		window.setView(view);
		player.Draw(window);
		window.display();
	}
	return 0;
}