#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Settings.h"

using namespace TheSnake;

struct Position2D {
	float X;
	float Y;
};

enum class Direction {
	Right = 0,
	Up,
	Left,
	Down
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WEIGH, SCREEN_HEIGHT), "TheSnake");

	//Snake
	std::vector<sf::CircleShape> Snake(10);

	float distance = 0;

	std::vector<Position2D> SnakePosition(10);
	for (int i = 0; i < SnakePosition.size(); ++i) {
		SnakePosition[i].X = SCREEN_WEIGH / 2;
		SnakePosition[i].Y = SCREEN_HEIGHT / 2 + distance;
		distance += DISTANCE;
	}
	//Position2D SnakePosition{ SCREEN_WEIGH / 2, SCREEN_HEIGHT / 2 };
	
	Direction SnakeDirection = Direction::Up;

	Position2D Memory{ SnakePosition[0].X, SnakePosition[0].Y};
	Position2D Memory2{ SnakePosition[0].X, SnakePosition[0].Y };

	for (int i = 0; i < Snake.size(); i++) {
		Snake[i].setFillColor(sf::Color::Green);
		//if (i != 0) {
			Memory.X = SnakePosition[i].X;
			Memory.Y = SnakePosition[i].Y;

			SnakePosition[i].X = Memory2.X;
			SnakePosition[i].Y = Memory2.Y;

			Memory2.X = Memory.X;
			Memory2.Y = Memory.Y;
		//}
		Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
		//distance += DISTANCE;
		Snake[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
		Snake[i].setRadius(SNAKE_SIZE / 2);
	}
	

	//TIME
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//EVENT
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		

		//Testing
		//distance = 0;
		//Snake Direction
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			SnakeDirection = Direction::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			SnakeDirection = Direction::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			SnakeDirection = Direction::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			SnakeDirection = Direction::Down;
		}

		//Snake Movement
		if (SnakeDirection == Direction::Right) {
			SnakePosition[0].X += SPEED_OF_SNAKE * deltaTime;
		}
		else if (SnakeDirection == Direction::Up) {
			SnakePosition[0].Y -= SPEED_OF_SNAKE * deltaTime;
		}
		else if (SnakeDirection == Direction::Left) {
			SnakePosition[0].X -= SPEED_OF_SNAKE * deltaTime;
		}
		else if (SnakeDirection == Direction::Down) {
			SnakePosition[0].Y += SPEED_OF_SNAKE * deltaTime;
		}

		Memory2.X = SnakePosition[0].X;
		Memory2.Y = SnakePosition[0].Y;
		
		//DRAWING
		window.clear();
		for (int i = 0; i < Snake.size(); i++) {
			if (i != 0) {
				Memory.X = SnakePosition[i].X;
				Memory.Y = SnakePosition[i].Y;

				SnakePosition[i].X = Memory2.X;
				SnakePosition[i].Y = Memory2.Y;

				Memory2.X = Memory.X;
				Memory2.Y = Memory.Y;
			}
			Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
			distance += DISTANCE;
			window.draw(Snake[i]);
		}
		window.display();
	}

	return 0;
}
