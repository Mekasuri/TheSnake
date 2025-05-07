#include "DifficultLevel.h"
#include <cassert>
#include "Math.h"
namespace TheSnake {
	void DifficultLevelInitialization(DifficultLevelStruct& difficultLevelStruct, ChoiceSettings& choiceSettings) {
		SettingsBackgroundInitialization(difficultLevelStruct.SettingsBackground);
		choiceSettings = static_cast<ChoiceSettings>(difficultLevelStruct.difficultyLevel);
		difficultLevelStruct.DifficultyLevelText.resize(5);
		difficultLevelStruct.DifficultyLevelText[0].message = "First Level";
		difficultLevelStruct.DifficultyLevelText[1].message = "Second Level";
		difficultLevelStruct.DifficultyLevelText[2].message = "Third Level";
		difficultLevelStruct.DifficultyLevelText[3].message = "Fourth Level";
		difficultLevelStruct.DifficultyLevelText[4].message = "Fifth Level";
		for (int i = 0; i < difficultLevelStruct.DifficultyLevelText.size(); ++i) {
			difficultLevelStruct.DifficultyLevelText[i].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[i].position = { SCREEN_WIDTH / 2 - 110, 200 + difficultLevelStruct.distance};
			difficultLevelStruct.DifficultyLevelText[i].textSize = 60;
			LabelInitialization(difficultLevelStruct.DifficultyLevelText[i]);
			difficultLevelStruct.distance += 60;
		}

		difficultLevelStruct.DifficultyText.resize(3);
		difficultLevelStruct.DifficultyText[0].message = "Difficulty Level";
		difficultLevelStruct.DifficultyText[0].position = { SCREEN_WIDTH / 2 - 290, 10};
		difficultLevelStruct.DifficultyText[0].textSize = 100;

		difficultLevelStruct.DifficultyText[1].message = "make your choice";
		difficultLevelStruct.DifficultyText[1].position = { SCREEN_WIDTH / 2 - 160, 100};
		difficultLevelStruct.DifficultyText[1].textSize = 20;

		difficultLevelStruct.DifficultyText[2].message = "Press \"ESC\" for back to MainMenu";
		difficultLevelStruct.DifficultyText[2].position = { SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT - 100 };
		difficultLevelStruct.DifficultyText[1].textSize = 50;

		for (int i = 0; i < difficultLevelStruct.DifficultyText.size(); ++i) {
			difficultLevelStruct.DifficultyText[i].color = sf::Color::Red;
			LabelInitialization(difficultLevelStruct.DifficultyText[i]);
		}

		difficultLevelStruct.BloodsSprites.resize(4);
		difficultLevelStruct.BloodsTextures.resize(4);
		difficultLevelStruct.BloodsPostitons.resize(4);
		difficultLevelStruct.BloodsSize.resize(4);

		assert(difficultLevelStruct.BloodsTextures[0].loadFromFile(RESOURCES_PATH + "/BloodPart1.png"));
		assert(difficultLevelStruct.BloodsTextures[1].loadFromFile(RESOURCES_PATH + "/BloodPart2.png"));
		assert(difficultLevelStruct.BloodsTextures[2].loadFromFile(RESOURCES_PATH + "/BloodPart3.png"));
		assert(difficultLevelStruct.BloodsTextures[3].loadFromFile(RESOURCES_PATH + "/BloodPart4.png"));

		difficultLevelStruct.BloodsSprites[0].setTexture(difficultLevelStruct.BloodsTextures[0]);
		difficultLevelStruct.BloodsSprites[1].setTexture(difficultLevelStruct.BloodsTextures[1]);
		difficultLevelStruct.BloodsSprites[1].setRotation(30);
		difficultLevelStruct.BloodsSprites[2].setTexture(difficultLevelStruct.BloodsTextures[2]);
		difficultLevelStruct.BloodsSprites[3].setTexture(difficultLevelStruct.BloodsTextures[3]);
		difficultLevelStruct.BloodsSprites[3].setRotation(-20);

		difficultLevelStruct.BloodsPostitons[0] = { SCREEN_WIDTH / 2 + 50 ,490 };
		difficultLevelStruct.BloodsPostitons[1] = { SCREEN_WIDTH - 200,350 };
		difficultLevelStruct.BloodsPostitons[2] = { 150,600 };
		difficultLevelStruct.BloodsPostitons[3] = { 200,200 };

		difficultLevelStruct.BloodsSize[0] = 0.4;
		difficultLevelStruct.BloodsSize[1] = 0.7;
		difficultLevelStruct.BloodsSize[2] = 0.5;
		difficultLevelStruct.BloodsSize[3] = 0.4;

		for (int i = 0; i < difficultLevelStruct.BloodsSprites.size(); ++i) {
			difficultLevelStruct.BloodsSprites[i].setPosition(difficultLevelStruct.BloodsPostitons[i].X, difficultLevelStruct.BloodsPostitons[i].Y);
			SetSpriteSize(difficultLevelStruct.BloodsSprites[i], difficultLevelStruct.BloodsSize[i], difficultLevelStruct.BloodsSize[i]);
			SetSpriteOrigin(difficultLevelStruct.BloodsSprites[i],0.5f, 0.5f);
		}
	}
	void DifficultLevelLoop(DifficultLevelStruct& difficultLevelStruct, ChoiceSettings& choiceSettings, sf::RenderWindow& window, GameState& gameState, float deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gameState = GameState::MainMenu;
		}

		if (choiceSettings == ChoiceSettings::FirstLevel) {
			difficultLevelStruct.DifficultyLevelText[0].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[0 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultyLevel = DifficultyLevel::FirstLevel;
			difficultLevelStruct.isBlodeVisible = false;
		}
		else if (choiceSettings == ChoiceSettings::SecondLevel) {
			difficultLevelStruct.DifficultyLevelText[1 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[1].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[1 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultyLevel = DifficultyLevel::SecondLevel;
			difficultLevelStruct.isBlodeVisible = false;
		}
		else if (choiceSettings == ChoiceSettings::ThirdLevel) {
			difficultLevelStruct.DifficultyLevelText[2 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[2].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[2 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultyLevel = DifficultyLevel::ThirdLevel;
			difficultLevelStruct.isBlodeVisible = false;
		}
		else if (choiceSettings == ChoiceSettings::FourthLevel) {
			difficultLevelStruct.DifficultyLevelText[3 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[3].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[3 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultyLevel = DifficultyLevel::FourthLevel;
			difficultLevelStruct.isBlodeVisible = false;
		}
		else if (choiceSettings == ChoiceSettings::FifthLevel) {
			difficultLevelStruct.DifficultyLevelText[4 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[4].color = sf::Color::Red;
			difficultLevelStruct.difficultyLevel = DifficultyLevel::FifthLevel;
			difficultLevelStruct.isBlodeVisible = true;
		}
		window.clear();
		window.draw(difficultLevelStruct.SettingsBackground.BackgroundSprite);
		for (int i = 0; i < difficultLevelStruct.DifficultyLevelText.size(); ++i) {
			difficultLevelStruct.DifficultyLevelText[i].text.setFillColor(difficultLevelStruct.DifficultyLevelText[i].color);
			window.draw(difficultLevelStruct.DifficultyLevelText[i].text);
		}
		for (int i = 0; i < difficultLevelStruct.DifficultyText.size(); ++i) {
			window.draw(difficultLevelStruct.DifficultyText[i].text);
		}
		if (difficultLevelStruct.isBlodeVisible) {//SCREEEEAAAAM
			if (difficultLevelStruct.blink < 550) {
				for (int i = 1; i < difficultLevelStruct.BloodsSprites.size(); ++i) {
					window.draw(difficultLevelStruct.BloodsSprites[i]);
				}
				difficultLevelStruct.blink++;
			}
			else {
				difficultLevelStruct.blink++;
				if (difficultLevelStruct.blink == 600) {
					difficultLevelStruct.blink = 0;
				}
			}
			
		}
		else {
			window.draw(difficultLevelStruct.BloodsSprites[0]);
		}
		window.display();
	}
	void ListChoiceSettingsDown(ChoiceSettings& choiceSettings) {
		if (choiceSettings != ChoiceSettings::FifthLevel) {
			choiceSettings = static_cast<ChoiceSettings>(static_cast<int>(choiceSettings) + 1);
		}
	}
	void ListChoiceSettingsUp(ChoiceSettings& choiceSettings) {
		if (choiceSettings != ChoiceSettings::FirstLevel) {
			choiceSettings = static_cast<ChoiceSettings>(static_cast<int>(choiceSettings) - 1);
		}
	}
}