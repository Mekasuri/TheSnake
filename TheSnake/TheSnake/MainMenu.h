#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
#include "Backgrounds.h"
#include "Text.h"
#include "GameLoop.h"
#include <vector>
#include "Sound.h"
namespace TheSnake {
	struct TextsForMainMenu {
		Label labelName;
		std::vector<Label>mainMenuTexts;
		Sound ClickSound;
	};
	enum class Choice {
		StartGame = 0,
		DifficultyLevel,
		Records,
		Settings,
		Exit
	};
	void MainMenuInitialization(Background& mainMenuBackground, TextsForMainMenu& texts, Choice& choice);
	void MainMenuMainLoop(sf::RenderWindow& window, Background& mainMenuBackground, GameState& gameState, TextsForMainMenu& texts, Choice& choice, GameLoop& gameLoop);
	void ListMenuDown(Choice& choice);
	void ListMenuUp(Choice& choice);
}