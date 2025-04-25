#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include <cassert>
#include "Settings.h"
#include "Math.h"
#include "GameData.h"
#include "MainMenu.h"

using namespace TheSnake;

//Position2D GenerateApplePosition() {
//	float rangeX = maxX - minX;
//	float rangeY = maxY - minY;
//
//	float randomX = minX + rand() / (float)RAND_MAX * rangeX;
//	float randomY = minY + rand() / (float)RAND_MAX * rangeY;
//
//	return { randomX, randomY };
//}

int main()
{
	int seed = time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TheSnake");

	//Game
	GameState gameState = GameState::MainMenu;

	//Main menu initialisaton 
	MainMenu mainMenu;
	MainMenuInitialization(mainMenu);

	//Game Background Initialization
	sf::Texture MainGameBackgroundTexture;
	sf::Sprite MainGameBackgroundSprite;
	Position2D MainGameBackgroundPosition{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	assert(MainGameBackgroundTexture.loadFromFile(RESOURCES_PATH + "/MainGameBackground.png"));
	MainGameBackgroundSprite.setTexture(MainGameBackgroundTexture);
	SetSpriteSize(MainGameBackgroundSprite, SCREEN_WIDTH / (float)MainGameBackgroundTexture.getSize().x, SCREEN_HEIGHT / (float)MainGameBackgroundTexture.getSize().y);
	SetSpriteOrigin(MainGameBackgroundSprite, 0.5, 0.5);
	MainGameBackgroundSprite.setPosition(MainGameBackgroundPosition.X, MainGameBackgroundPosition.Y);
	
	int UpperFrame = 120;
	int SideFrame = 45;
	int LowerFrame = 33;

	//ApplesInitialization
	bool isAppleEaten = false;
	sf::Texture AppleTexture;
	sf::Sprite AppleSprite;
	Position2D ApplePosition;
	ApplePosition.X = APPLE_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * APPLE_SIZE);
	ApplePosition.Y = APPLE_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * APPLE_SIZE);
	assert(AppleTexture.loadFromFile(RESOURCES_PATH + "/Apple.png"));
	AppleSprite.setTexture(AppleTexture);
	SetSpriteSize(AppleSprite, APPLE_SIZE / (float)AppleTexture.getSize().x, APPLE_SIZE / (float)AppleTexture.getSize().y);
	SetSpriteOrigin(AppleSprite, 0.5, 0.5);
	AppleSprite.setPosition(ApplePosition.X, ApplePosition.Y);

	//Snake
	int SnakeSpeed = SPEED_OF_SNAKE;
	int snakeLength = 10;
	std::vector<sf::CircleShape> Snake(snakeLength);
	Position2D newPart;

	float distance = 0;
	bool isSnakeDead = false;
	bool GetNewPart = false;

	std::vector<Position2D> SnakePosition(snakeLength);
	std::vector<Position2D> PreviousPosition(snakeLength);

	for (int i = 0; i < SnakePosition.size(); ++i) {
		SnakePosition[i].X = SCREEN_WIDTH / 2;
		SnakePosition[i].Y = SCREEN_HEIGHT / 2 - distance;
		distance += DISTANCE;
	}
	
	Direction SnakeDirection = Direction::Up;

	for (int i = 0; i < Snake.size(); i++) {
		Snake[i].setFillColor(sf::Color::Green);
		Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
		Snake[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
		Snake[i].setRadius(SNAKE_SIZE / 2);
	}
	

	//TIME
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();
	float counter = 0;

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
				if (SnakeDirection != Direction::Left) {
					SnakeDirection = Direction::Right;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (SnakeDirection != Direction::Down) {
					SnakeDirection = Direction::Up;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (SnakeDirection != Direction::Right) {
					SnakeDirection = Direction::Left;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (SnakeDirection != Direction::Up) {
					SnakeDirection = Direction::Down;
				}
			}

			//Save the current head position
			std::vector<Position2D> previousPositions = SnakePosition;

			//Snake Movement
			if (SnakeDirection == Direction::Right) {
				SnakePosition[0].X += SnakeSpeed * deltaTime;
			}
			else if (SnakeDirection == Direction::Up) {
				SnakePosition[0].Y -= SnakeSpeed * deltaTime;
			}
			else if (SnakeDirection == Direction::Left) {
				SnakePosition[0].X -= SnakeSpeed * deltaTime;
			}
			else if (SnakeDirection == Direction::Down) {
				SnakePosition[0].Y += SnakeSpeed * deltaTime;
			}

			//Collision with walls
			if (SnakePosition[0].X + SNAKE_SIZE / 2 >= SCREEN_WIDTH - 45 || SnakePosition[0].Y - SNAKE_SIZE / 2 <= 120 || SnakePosition[0].X - SNAKE_SIZE / 2 <= 45 || SnakePosition[0].Y + SNAKE_SIZE / 2 >= SCREEN_HEIGHT - 33) {//Right
				isSnakeDead = true;
			}

			//Update position of snake
			counter += deltaTime;
			if (counter > 1.0f / 20.0f)
			{
				counter = 0.0f;
				for (int i = 1; i < snakeLength; i++) {
					SnakePosition[i] = PreviousPosition[i - 1];
				}

				if (GetNewPart) {
					sf::CircleShape newPartCircle;
					newPartCircle.setFillColor(sf::Color::Green);
					newPartCircle.setPosition(newPart.X, newPart.Y);
					newPartCircle.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
					newPartCircle.setRadius(SNAKE_SIZE / 2);
					Snake.push_back(newPartCircle);
					SnakePosition.push_back(newPart);
					PreviousPosition.push_back(newPart);
					snakeLength++;
					GetNewPart = false;
				}

			}

			//Collision with apple
			if (collision(SnakePosition[0], SNAKE_SIZE, ApplePosition, APPLE_SIZE)) {
				GetNewPart = true;
				newPart.X = SnakePosition[SnakePosition.size() - 1].X;
				newPart.Y = SnakePosition[SnakePosition.size() - 1].Y;
				
				ApplePosition.X = APPLE_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * APPLE_SIZE);
				ApplePosition.Y = APPLE_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * APPLE_SIZE);
			}

			AppleSprite.setPosition(ApplePosition.X, ApplePosition.Y);
			
			//DRAWING
			window.clear();
			window.draw(MainGameBackgroundSprite);
			window.draw(AppleSprite);
			for (int i = 0; i < Snake.size(); i++) {
				if (!isSnakeDead) {
					Snake[i].setPosition(SnakePosition[i].X, SnakePosition[i].Y);
					window.draw(Snake[i]);
					PreviousPosition[i] = { SnakePosition[i].X, SnakePosition[i].Y };
				}
				else{
					window.close();
				}
				
			}
			window.display();
		}
		else if (gameState == GameState::MainMenu) {
			MainMenuMainLoop(window, mainMenu, gameState);
		}

		//EVENT
	}

	return 0;
}
