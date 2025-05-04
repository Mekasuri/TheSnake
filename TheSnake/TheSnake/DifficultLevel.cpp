#include "DifficultLevel.h"
namespace TheSnake {
	void DifficultLevelInitialization(DifficultLevelStruct& difficultLevelStruct, ChoiceSettings& choiceSettings) {
		SettingsBackgroundInitialization(difficultLevelStruct.SettingsBackground);
		choiceSettings = static_cast<ChoiceSettings>(difficultLevelStruct.difficultLevel);
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
	}
	void DifficultLevelLoop(DifficultLevelStruct& difficultLevelStruct, ChoiceSettings& choiceSettings, sf::RenderWindow& window, GameState& gameState) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gameState = GameState::MainMenu;
		}

		if (choiceSettings == ChoiceSettings::FirstLevel) {
			difficultLevelStruct.DifficultyLevelText[0].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[0 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultLevel = DifficultyLevel::FirstLevel;
		}
		else if (choiceSettings == ChoiceSettings::SecondLevel) {
			difficultLevelStruct.DifficultyLevelText[1 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[1].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[1 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultLevel = DifficultyLevel::SecondLevel;
		}
		else if (choiceSettings == ChoiceSettings::ThirdLevel) {
			difficultLevelStruct.DifficultyLevelText[2 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[2].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[2 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultLevel = DifficultyLevel::ThirdLevel;
		}
		else if (choiceSettings == ChoiceSettings::FourthLevel) {
			difficultLevelStruct.DifficultyLevelText[3 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[3].color = sf::Color::Red;
			difficultLevelStruct.DifficultyLevelText[3 + 1].color = sf::Color::Black;
			difficultLevelStruct.difficultLevel = DifficultyLevel::FourthLevel;
		}
		else if (choiceSettings == ChoiceSettings::FifthLevel) {
			difficultLevelStruct.DifficultyLevelText[4 - 1].color = sf::Color::Black;
			difficultLevelStruct.DifficultyLevelText[4].color = sf::Color::Red;
			difficultLevelStruct.difficultLevel = DifficultyLevel::FifthLevel;
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