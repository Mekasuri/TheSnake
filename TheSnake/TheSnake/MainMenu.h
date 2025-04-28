#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
#include "Backgrounds.h"
#include "Text.h"
#include <vector>
namespace TheSnake {
	struct TextsForMainMenu {
		Label labelName;
		std::vector<Label>mainMenuTexts;
	};
	enum class Choice {
		StartGame = 0,
		DifficultyLevel,
		Records,
		Settings,
		Exit
	};
	void MainMenuInitialization(Background& mainMenuBackground, TextsForMainMenu& texts, Choice& choice);
	void MainMenuMainLoop(sf::RenderWindow& window, Background& mainMenuBackground, GameState& gameState, TextsForMainMenu& texts, Choice& choice);
}