#include "Snake.h"
#include "Math.h"
#include "GameData.h"
#include <cassert>
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

		assert(snake.snakeHeadTexture.loadFromFile(RESOURCES_PATH + "/SnakeHead.png"));
		snake.snakeHeadSprite.setTexture(snake.snakeHeadTexture);
		SetSpriteSize(snake.snakeHeadSprite, SNAKE_HEAD_SIZE / (float)snake.snakeHeadTexture.getSize().x, SNAKE_HEAD_SIZE / (float)snake.snakeHeadTexture.getSize().y);
		SetSpriteOrigin(snake.snakeHeadSprite, 0.5, 0.5);

		SoundInitialization(snake.AppleEatSound, "EatApple.wav");
		SoundInitialization(snake.TeleportSound, "Teleport.wav");
		SoundInitialization(snake.GameOver, "GameOver.wav");
	}	

	void SnakeMove(Snake& snake, float deltaTime, DifficultyLevel difficultyLevel) {
		if (difficultyLevel == DifficultyLevel::FifthLevel) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (snake.SnakeDirection != Direction::Left) {
					snake.SnakeDirection = Direction::Right;
					snake.SnakeHeadRotation = -90;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (snake.SnakeDirection != Direction::Down) {
					snake.SnakeDirection = Direction::Up;
					snake.SnakeHeadRotation = 180;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (snake.SnakeDirection != Direction::Right) {
					snake.SnakeDirection = Direction::Left;
					snake.SnakeHeadRotation = 90;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (snake.SnakeDirection != Direction::Up) {
					snake.SnakeDirection = Direction::Down;
					snake.SnakeHeadRotation = 0;
				}
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (snake.SnakeDirection != Direction::Left) {
					snake.SnakeDirection = Direction::Right;
					snake.SnakeHeadRotation = -90;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (snake.SnakeDirection != Direction::Down) {
					snake.SnakeDirection = Direction::Up;
					snake.SnakeHeadRotation = 180;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (snake.SnakeDirection != Direction::Right) {
					snake.SnakeDirection = Direction::Left;
					snake.SnakeHeadRotation = 90;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (snake.SnakeDirection != Direction::Up) {
					snake.SnakeDirection = Direction::Down;
					snake.SnakeHeadRotation = 0;
				}
			}
		}

		snake.previousPositions = snake.SnakePosition;

		if (snake.SnakeDirection == Direction::Right) {
			snake.SnakePosition[0].X += snake.SnakeSpeed * deltaTime;

			snake.snakeHeadPosition.X = snake.SnakePosition[0].X + snake.fromFirstCircle;
			snake.snakeHeadPosition.Y = snake.SnakePosition[0].Y;
		}
		else if (snake.SnakeDirection == Direction::Up) {
			snake.SnakePosition[0].Y -= snake.SnakeSpeed * deltaTime;

			snake.snakeHeadPosition.X = snake.SnakePosition[0].X;
			snake.snakeHeadPosition.Y = snake.SnakePosition[0].Y - snake.fromFirstCircle;
		}
		else if (snake.SnakeDirection == Direction::Left) {
			snake.SnakePosition[0].X -= snake.SnakeSpeed * deltaTime;

			snake.snakeHeadPosition.X = snake.SnakePosition[0].X - snake.fromFirstCircle;
			snake.snakeHeadPosition.Y = snake.SnakePosition[0].Y;
		}
		else if (snake.SnakeDirection == Direction::Down) {
			snake.SnakePosition[0].Y += snake.SnakeSpeed * deltaTime;

			snake.snakeHeadPosition.X = snake.SnakePosition[0].X;
			snake.snakeHeadPosition.Y = snake.SnakePosition[0].Y + snake.fromFirstCircle;
		}

	}

	void SnakeCollisions(Snake& snake, Position2D& ApplePosition,sf::Sprite& AppleSprite, Portal& portal, int UpperFrame, int SideFrame, int LowerFrame, Score& score, DifficultyLevel difficultyLevel, float deltaTime) {
		//Collision with walls
		if (snake.SnakePosition[0].X + SNAKE_SIZE / 2 >= SCREEN_WIDTH - 45 || snake.SnakePosition[0].Y - SNAKE_SIZE / 2 <= 120 || snake.SnakePosition[0].X - SNAKE_SIZE / 2 <= 45 || snake.SnakePosition[0].Y + SNAKE_SIZE / 2 >= SCREEN_HEIGHT - 33) {//Right
			snake.GameOver.sound.play();
			snake.isSnakeDead = true;
		}

		//Collision with snake
		if (snake.ignoreCollision > 0) {
			--snake.ignoreCollision;
		}
		else {
			for (int i = 4; i < snake.snakeLength; ++i) {
				if (difficultyLevel == DifficultyLevel::FirstLevel || difficultyLevel == DifficultyLevel::SecondLevel) {
					if (collision(snake.snakeHeadPosition, SNAKE_SIZE, snake.SnakePosition[i], SNAKE_SIZE)) {
						if (!snake.isInvisible) {
							snake.isInvisible = true;
							snake.invulnerabilityTimer = INVULNERABILITY_DURATION;
							snake.alpha = 0.5f;
						}
					}
				}
				else{
					if (collision(snake.snakeHeadPosition, SNAKE_SIZE, snake.SnakePosition[i], SNAKE_SIZE)) {
						snake.GameOver.sound.play();
						snake.isSnakeDead = true;
					}
				}

				if (snake.isInvisible) {
					snake.invulnerabilityTimer -= deltaTime;
					if (snake.invulnerabilityTimer <= 0) {
						snake.isInvisible = false;
						snake.alpha = 1.0f;
					}
				}
			}
		}

		//COLLISION WITH APPLE
		if (collision(snake.snakeHeadPosition, SNAKE_SIZE, ApplePosition, APPLE_SIZE)) {
			snake.AppleEatSound.sound.play();
			snake.GetNewPart = true;
			score.score++;
			snake.newPart.X = snake.SnakePosition[snake.SnakePosition.size() - 1].X;
			snake.newPart.Y = snake.SnakePosition[snake.SnakePosition.size() - 1].Y;

			for (int i = 0; i < 50; ++i) {
				for (int j = 0; j < snake.Snake.size(); ++j) {
					ApplePosition.X = APPLE_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * APPLE_SIZE);
					ApplePosition.Y = APPLE_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * APPLE_SIZE);
					if (!collision(snake.SnakePosition[j], SNAKE_SIZE + 10, ApplePosition, APPLE_SIZE)) {
						i = 50;
						break;
					}
				}
			}
		}

		//COLLISION WITH TELEPORT
		if (!portal.isTeleported) {
			if (collision(snake.snakeHeadPosition, 20, portal.PortalPosition[0], 20)) {
				snake.SnakePosition[0] = portal.PortalPosition[1];
				portal.isTeleported = true;
				snake.TeleportSound.sound.play();
			}
			else if (collision(snake.snakeHeadPosition, 20, portal.PortalPosition[1], 20)) {
				snake.SnakePosition[0] = portal.PortalPosition[0];
				portal.isTeleported = true;
				snake.TeleportSound.sound.play();
			}
		}
		else {
			portal.timer -= deltaTime;
			if (portal.timer <= 0) {
				portal.timer = PORTAL_TIMER;
				portal.isTeleported = false;
			}
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

	void SnakePrint(Snake& snake, sf::RenderWindow& window, GameState& gameState) {
		if (!snake.isSnakeDead) {
			//window.clear();
			for (int i = 0; i < snake.Snake.size(); i++) {
				snake.Snake[i].setPosition(snake.SnakePosition[i].X, snake.SnakePosition[i].Y);
				window.draw(snake.Snake[i]);
				snake.PreviousPosition[i] = { snake.SnakePosition[i].X, snake.SnakePosition[i].Y };
			}
			snake.snakeHeadSprite.setRotation(snake.SnakeHeadRotation);
			snake.snakeHeadSprite.setPosition(snake.snakeHeadPosition.X, snake.snakeHeadPosition.Y);
			snake.snakeHeadSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(snake.alpha * 255)));
			window.draw(snake.snakeHeadSprite);
			//window.display();
		}
		else {
			gameState = GameState::Records;
		}
	}
}