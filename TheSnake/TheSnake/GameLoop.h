#pragma once
#include "Snake.h"
#include "Backgrounds.h"
#include "Apple.h"
#include "Score.h"
namespace TheSnake {
	struct GameLoop {
		int UpperFrame = 120;
		int SideFrame = 45;
		int LowerFrame = 33;
		Background gameBackGround;
		Apple apple;
		Snake snake;
		Score score;
	};
	void GameLoopInitialization(GameLoop& gameLoop);
	void GameLoopDisplay(GameLoop& gameLoop, sf::RenderWindow& window, GameState& gameState);
	void GameLoopLogic(GameLoop& gameLoop, float deltaTime, sf::RenderWindow& window, GameState& gameState);
}