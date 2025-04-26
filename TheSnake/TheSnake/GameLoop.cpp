#include "GameLoop.h"
namespace TheSnake {
	void GameLoopInitialization(GameLoop& gameLoop) {
		AppleInitialization(gameLoop.apple, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
		SnakeInitialization(gameLoop.snake);
		GameBackgroundInitialization(gameLoop.gameBackGround);
	}
	void GameLoopDisplay(GameLoop& gameLoop, sf::RenderWindow& window) {
		window.clear();
		window.draw(gameLoop.gameBackGround.BackgroundSprite);
		ApplePrint(gameLoop.apple, window);
		SnakePrint(gameLoop.snake, window);
		window.display();
	}
	void GameLoopLogic(GameLoop& gameLoop, float deltaTime, sf::RenderWindow& window) {
		SnakeMove(gameLoop.snake, deltaTime);

		SnakeCollisions(gameLoop.snake, gameLoop.apple.ApplePosition, gameLoop.apple.AppleSprite, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);

		UpdateSnakePosition(gameLoop.snake, deltaTime);

		GameLoopDisplay(gameLoop, window);
	}
}