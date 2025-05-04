#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
namespace TheSnake {
	struct Background {
		sf::Texture BackgroundTexture;
		sf::Sprite BackgroundSprite;
		Position2D BackgroundPosition{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	};
	void GameBackgroundInitialization(Background& gameBackground);
	void MainMenuBackgroundInitialization(Background& mainMenuBackground);
	void RestartBackgroundInitialization(Background& RestartBackground);
	void SettingsBackgroundInitialization(Background& SettingsBackground);
}