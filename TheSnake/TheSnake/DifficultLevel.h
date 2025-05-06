#pragma once
#include "Backgrounds.h"
#include "GameData.h"
#include "Text.h"
#include <vector>
#include <SFML/Graphics.hpp>
namespace TheSnake {
	struct DifficultLevelStruct {
		DifficultyLevel difficultyLevel = DifficultyLevel::FirstLevel;
		Background SettingsBackground;
		std::vector<Label>DifficultyText;
		std::vector<Label>DifficultyLevelText;
		float distance = 0;

		std::vector<sf::Texture>BloodsTextures;
		std::vector<sf::Sprite>BloodsSprites;
		std::vector<Position2D>BloodsPostitons;
		std::vector<float>BloodsSize;
		bool isBlodeVisible{false};
		int blink = 0;
	};
	enum class ChoiceSettings {
		FirstLevel = 0,
		SecondLevel,
		ThirdLevel,
		FourthLevel,
		FifthLevel
	};
	void DifficultLevelInitialization(DifficultLevelStruct& settingsLoopStruct, ChoiceSettings& choiceSettings);
	void DifficultLevelLoop(DifficultLevelStruct& settingsLoopStruct, ChoiceSettings& choiceSettings, sf::RenderWindow& window, GameState& gameState);
	void ListChoiceSettingsDown(ChoiceSettings& choiceSettings);
	void ListChoiceSettingsUp(ChoiceSettings& choiceSettings);
}