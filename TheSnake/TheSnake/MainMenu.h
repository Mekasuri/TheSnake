#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
namespace TheSnake {
	struct MainMenu {
		sf::Texture MainMenuBackgroundTexture;
		sf::Sprite MainMenuBackgroundSprite;
		Position2D MainMenuBackgroundPosition{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	};

	void MainMenuInitialization(MainMenu& mainMenu);
	void MainMenuMainLoop(sf::RenderWindow& window, MainMenu& mainMenu, GameState& gameState);
}