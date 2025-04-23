#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cassert>
#include "Settings.h"
#include "Math.h"
#include "GameData.h"

using namespace TheSnake;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WEIGH, SCREEN_HEIGHT), "TheSnake");

	//Game
	GameState gameState = GameState::MainMenu;

	//Main menu initialisaton 
	sf::Texture MainMenuBackgroundTexture;
	sf::Sprite MainMenuBackgroundSprite;
	Position2D MainMenuBackgroundPosition{SCREEN_WEIGH / 2,SCREEN_HEIGHT / 2};
	assert(MainMenuBackgroundTexture.loadFromFile(RESOURCES_PATH + "/MainMenuBackground.jpg"));
	MainMenuBackgroundSprite.setTexture(MainMenuBackgroundTexture);
	SetSpriteSize(MainMenuBackgroundSprite, 0.5, 0.5);
	SetSpriteOrigin(MainMenuBackgroundSprite, SCREEN_WEIGH, SCREEN_HEIGHT);
	MainMenuBackgroundSprite.setPosition(MainMenuBackgroundPosition.X, MainMenuBackgroundPosition.Y);
	

	//Snake
	int snakeLength = 10;
	std::vector<sf::CircleShape> Snake(snakeLength);

	float distance = 0;

	std::vector<Position2D> SnakePosition(snakeLength);
	for (int i = 0; i < SnakePosition.size(); ++i) {
		SnakePosition[i].X = SCREEN_WEIGH / 2;
		SnakePosition[i].Y = SCREEN_HEIGHT / 2 - distance;
		distance += DISTANCE;
	}
	//Position2D SnakePosition{ SCREEN_WEIGH / 2, SCREEN_HEIGHT / 2 };
	
	Direction SnakeDirection = Direction::Up;
	//Position2D Memory{ SnakePosition[0].X, SnakePosition[0].Y};
	//Position2D Memory2{ SnakePosition[0].X, SnakePosition[0].Y };

	for (int i = 0; i < Snake.size(); i++) {
		Snake[i].setFillColor(sf::Color::Green);
		Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
		Snake[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
		Snake[i].setRadius(SNAKE_SIZE / 2);
	}
	

	//TIME
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		//SOME GAME STUFF
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//SO IMPORTANT CHECK
		if (gameState == GameState::MainGame) {
			//Testing
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

			//Save the current head position
			std::vector<Position2D> previousPositions = SnakePosition;

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

			for (int i = 1; i < snakeLength; i++) {
				SnakePosition[i] = previousPositions[i - 1];
			}

			//DRAWING
			window.clear();
			for (int i = 0; i < Snake.size(); i++) {
				Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
				window.draw(Snake[i]);
			}
			window.display();
		}
		else if (gameState == GameState::MainMenu) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				gameState = GameState::MainGame;
			}
			window.clear();
			window.draw(MainMenuBackgroundSprite);
			window.display();
		}

		//EVENT
	}

	return 0;
}
