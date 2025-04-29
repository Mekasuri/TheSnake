#include "GameLoop.h"
namespace TheSnake {
	void GameLoopInitialization(GameLoop& gameLoop) {
		AppleInitialization(gameLoop.apple, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame);
		SnakeInitialization(gameLoop.snake);
		GameBackgroundInitialization(gameLoop.gameBackGround);
		scoreInitialization(gameLoop.score);
	}
	void GameLoopDisplay(GameLoop& gameLoop, sf::RenderWindow& window, GameState& gameState) {
		window.clear();
		window.draw(gameLoop.gameBackGround.BackgroundSprite);
		ApplePrint(gameLoop.apple, window);
		SnakePrint(gameLoop.snake, window, gameState);
		window.draw(gameLoop.score.scoreLabel.text);
		window.display();
	}
	void GameLoopLogic(GameLoop& gameLoop, float deltaTime, sf::RenderWindow& window, GameState& gameState) {
		SnakeMove(gameLoop.snake, deltaTime);

		SnakeCollisions(gameLoop.snake, gameLoop.apple.ApplePosition, gameLoop.apple.AppleSprite, gameLoop.UpperFrame, gameLoop.SideFrame, gameLoop.LowerFrame, gameLoop.score);

		UpdateSnakePosition(gameLoop.snake, deltaTime);

		gameLoop.score.scoreLabel.message = "Score: " + std::to_string(gameLoop.score.score);
		gameLoop.score.scoreLabel.text.setString(gameLoop.score.scoreLabel.message);

		GameLoopDisplay(gameLoop, window, gameState);
	}
}