#pragma once
#include "Snake.h"
#include "Backgrounds.h"
#include "Apple.h"
#include "Score.h"
#include "Portal.h"
namespace TheSnake {
	struct GameLoop {
		float UpdetePortal = 10;
		float UpdetePortal2 = UpdetePortal;
		int UpperFrame = 120;
		int SideFrame = 45;
		int LowerFrame = 33;
		Background gameBackGround;
		Apple apple;
		Snake snake;
		Score score;
		Portal portal;
	};
	void GameLoopInitialization(GameLoop& gameLoop);
	void GameLoopDisplay(GameLoop& gameLoop, sf::RenderWindow& window, GameState& gameState, float deltaTime);
	void GameLoopLogic(GameLoop& gameLoop, float deltaTime, sf::RenderWindow& window, GameState& gameState, DifficultyLevel difficultyLevel, bool isSound);
	void UpdateState(GameLoop& gameLoop);
}