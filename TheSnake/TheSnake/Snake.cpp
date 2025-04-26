#include "Snake.h"
#include "Math.h"
namespace TheSnake {
	void SnakeInitialization(Snake& snake) {
		snake.Snake.resize(snake.snakeLength);
		snake.SnakePosition.resize(snake.snakeLength);
		snake.PreviousPosition.resize(snake.snakeLength);

		for (int i = 0; i < snake.SnakePosition.size(); ++i) {
			snake.SnakePosition[i].X = SCREEN_WIDTH / 2;
			snake.SnakePosition[i].Y = SCREEN_HEIGHT / 2 + snake.distance;
			snake.distance += DISTANCE;
		}
		for (int i = 0; i < snake.Snake.size(); i++) {
			snake.Snake[i].setFillColor(sf::Color::Green);
			snake.Snake[i].setPosition(snake.SnakePosition[i].X, snake.SnakePosition[i].Y);
			snake.Snake[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
			snake.Snake[i].setRadius(SNAKE_SIZE / 2);
		}
	}	

	void SnakeMove(Snake& snake, float deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (snake.SnakeDirection != Direction::Left) {
				snake.SnakeDirection = Direction::Right;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (snake.SnakeDirection != Direction::Down) {
				snake.SnakeDirection = Direction::Up;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (snake.SnakeDirection != Direction::Right) {
				snake.SnakeDirection = Direction::Left;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (snake.SnakeDirection != Direction::Up) {
				snake.SnakeDirection = Direction::Down;
			}
		}

		snake.previousPositions = snake.SnakePosition;

		if (snake.SnakeDirection == Direction::Right) {
			snake.SnakePosition[0].X += snake.SnakeSpeed * deltaTime;
		}
		else if (snake.SnakeDirection == Direction::Up) {
			snake.SnakePosition[0].Y -= snake.SnakeSpeed * deltaTime;
		}
		else if (snake.SnakeDirection == Direction::Left) {
			snake.SnakePosition[0].X -= snake.SnakeSpeed * deltaTime;
		}
		else if (snake.SnakeDirection == Direction::Down) {
			snake.SnakePosition[0].Y += snake.SnakeSpeed * deltaTime;
		}

	}

	void SnakeCollisions(Snake& snake, Position2D& ApplePosition,sf::Sprite& AppleSprite, int UpperFrame, int SideFrame, int LowerFrame) {
		//Collision with walls
		if (snake.SnakePosition[0].X + SNAKE_SIZE / 2 >= SCREEN_WIDTH - 45 || snake.SnakePosition[0].Y - SNAKE_SIZE / 2 <= 120 || snake.SnakePosition[0].X - SNAKE_SIZE / 2 <= 45 || snake.SnakePosition[0].Y + SNAKE_SIZE / 2 >= SCREEN_HEIGHT - 33) {//Right
			snake.isSnakeDead = true;
		}

		//Collision with snake
		if (snake.ignoreCollision > 0) {
			--snake.ignoreCollision;
		}
		else {
			for (int i = 4; i < snake.snakeLength; ++i) {
				if (collision(snake.SnakePosition[0], SNAKE_SIZE, snake.SnakePosition[i], SNAKE_SIZE)) {
					snake.isSnakeDead = true;
				}
			}
		}

		if (collision(snake.SnakePosition[0], SNAKE_SIZE, ApplePosition, APPLE_SIZE)) {
			snake.GetNewPart = true;
			snake.newPart.X = snake.SnakePosition[snake.SnakePosition.size() - 1].X;
			snake.newPart.Y = snake.SnakePosition[snake.SnakePosition.size() - 1].Y;

			ApplePosition.X = APPLE_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * APPLE_SIZE);
			ApplePosition.Y = APPLE_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * APPLE_SIZE);
		}
		AppleSprite.setPosition(ApplePosition.X, ApplePosition.Y);
	}

	void UpdateSnakePosition(Snake& snake, float deltaTime) {
		snake.counter += deltaTime;
		if (snake.counter > 1.0f / 20.0f)
		{
			snake.counter = 0.0f;
			for (int i = 1; i < snake.snakeLength; i++) {
				snake.SnakePosition[i] = snake.PreviousPosition[i - 1];
			}

			if (snake.GetNewPart) {
				sf::CircleShape newPartCircle;
				newPartCircle.setFillColor(sf::Color::Green);
				newPartCircle.setPosition(snake.newPart.X, snake.newPart.Y);
				newPartCircle.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
				newPartCircle.setRadius(SNAKE_SIZE / 2);
				snake.Snake.push_back(newPartCircle);
				snake.SnakePosition.push_back(snake.newPart);
				snake.PreviousPosition.push_back(snake.newPart);
				snake.snakeLength++;
				snake.GetNewPart = false;
			}

		}
	}

	void SnakePrint(Snake& snake, sf::RenderWindow& window) {
		for (int i = 0; i < snake.Snake.size(); i++) {
			if (!snake.isSnakeDead) {
				snake.Snake[i].setPosition(snake.SnakePosition[i].X, snake.SnakePosition[i].Y);
				window.draw(snake.Snake[i]);
				snake.PreviousPosition[i] = { snake.SnakePosition[i].X, snake.SnakePosition[i].Y };
			}
			else {
				window.close();
			}

		}
	}
}