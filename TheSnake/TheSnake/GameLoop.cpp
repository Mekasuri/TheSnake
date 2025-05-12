#include "GameLoop.h"
namespace TheSnake {
	void GameLoopInitialization(GameLoop& gameLoop) {
		AppleInitialization(gameLoop.apple, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
		SnakeInitialization(gameLoop.snake);
		GameBackgroundInitialization(gameLoop.gameBackGround);
		scoreInitialization(gameLoop.score);
		PortalInitialization(gameLoop.portal, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
	}
	void GameLoopDisplay(GameLoop& gameLoop, sf::RenderWindow& window, GameState& gameState, float deltaTime) {
		window.clear();
		window.draw(gameLoop.gameBackGround.BackgroundSprite);
		PortalPrint(gameLoop.portal, window, gameLoop.UpdetePortal, gameLoop.UpdetePortal2, deltaTime, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
		ApplePrint(gameLoop.apple, window);
		SnakePrint(gameLoop.snake, window, gameState);
		window.draw(gameLoop.score.scoreLabel.text);
		window.display();
	}
	void GameLoopLogic(GameLoop& gameLoop, float deltaTime, sf::RenderWindow& window, GameState& gameState, DifficultyLevel difficultyLevel, bool isSound) {

		SnakeMove(gameLoop.snake, deltaTime, difficultyLevel);

		SnakeCollisions(gameLoop.snake, gameLoop.apple.ApplePosition, gameLoop.apple.AppleSprite, gameLoop.portal, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame, gameLoop.score, difficultyLevel, deltaTime, isSound);

		UpdateSnakePosition(gameLoop.snake, deltaTime);
		gameLoop.score.scoreLabel.message = "Score: " + std::to_string(gameLoop.score.score);
		gameLoop.score.scoreLabel.text.setString(gameLoop.score.scoreLabel.message);

		GameLoopDisplay(gameLoop, window, gameState, deltaTime);
	}
	void UpdateState(GameLoop& gameLoop) {
		gameLoop.snake.SnakeDirection = Direction::Up;
		gameLoop.snake.SnakeHeadRotation = 180;
		gameLoop.snake.snakeLength = 10;
		gameLoop.snake.distance = 0;
		gameLoop.score.score = 0;
		AppleInitialization(gameLoop.apple, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
		SnakeInitialization(gameLoop.snake);
		gameLoop.snake.isSnakeDead = false;
	}
}