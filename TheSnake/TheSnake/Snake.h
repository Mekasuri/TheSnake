#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
namespace TheSnake {
	struct Snake {
		int SnakeSpeed = SPEED_OF_SNAKE;
		int snakeLength = 10;

		std::vector<sf::CircleShape> Snake;
		Position2D newPart;
		float distance = 0;
		bool isSnakeDead = false;
		bool GetNewPart = false;
		int ignoreCollision = 300;

		sf::Texture snakeHeadTexture;
		sf::Sprite snakeHeadSprite;
		Position2D snakeHeadPosition;
		int SnakeHeadRotation = 180;
		int fromFirstCircle = 10;

		std::vector<Position2D> previousPositions;
		std::vector<Position2D> SnakePosition;
		std::vector<Position2D> PreviousPosition;
		Direction SnakeDirection = Direction::Up;

		float counter = 0;
	};
	void SnakeInitialization(Snake& snake);
	void SnakeMove(Snake& snake, float deltaTime);
	void SnakeCollisions(Snake& snake, Position2D& ApplePosition, sf::Sprite& AppleSprite, int UpperFrame, int SideFrame, int LowerFrame);
	void UpdateSnakePosition(Snake& snake, float deltaTime);
	void SnakePrint(Snake& snake, sf::RenderWindow& window);
}