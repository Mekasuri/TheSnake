#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
#include "Backgrounds.h"
namespace TheSnake {
	void MainMenuInitialization(Background& mainMenuBackground);
	void MainMenuMainLoop(sf::RenderWindow& window, Background& mainMenuBackground, GameState& gameState);
}