#pragma once
#include "Backgrounds.h"
#include "GameData.h"
#include "Text.h"
#include "Sound.h"
#include <vector>
#include <SFML/Graphics.hpp>
namespace TheSnake {
	struct GameSettings {
		bool isSoundOn = true;
		Background GameSettingsBackGround;
		sf::RectangleShape SoundOff;
		Label GameSettingssLabel;
	};
	void GameSettingsInitialization(GameSettings& gameSettings);
	void GameSettingsLoop(GameSettings& gameSettings, sf::RenderWindow& window, GameState& gameState);
	void EnterPressed(GameSettings& gameSettings);
}
