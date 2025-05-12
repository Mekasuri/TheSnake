#include "GameSettings.h"
namespace TheSnake {
	void GameSettingsInitialization(GameSettings& gameSettings) {
		RestartBackgroundInitialization(gameSettings.GameSettingsBackGround);
		gameSettings.GameSettingssLabel.color = sf::Color::White;
		gameSettings.GameSettingssLabel.message = "Sound is on";
		gameSettings.GameSettingssLabel.position = { 40, 30 };
		gameSettings.GameSettingssLabel.textSize = 50;
		LabelInitialization(gameSettings.GameSettingssLabel);
	}
	void GameSettingsLoop(GameSettings& gameSettings, sf::RenderWindow& window, GameState& gameState) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gameState = GameState::MainMenu;
		}
		if (!gameSettings.isSoundOn) {
			gameSettings.GameSettingssLabel.color = sf::Color::Black;
			gameSettings.GameSettingssLabel.message = "Sound is off";
		}
		else {
			gameSettings.GameSettingssLabel.color = sf::Color::White;
			gameSettings.GameSettingssLabel.message = "Sound is on";
		}
		gameSettings.GameSettingssLabel.text.setFillColor(gameSettings.GameSettingssLabel.color);
		gameSettings.GameSettingssLabel.text.setString(gameSettings.GameSettingssLabel.message);
		window.clear();
		window.draw(gameSettings.GameSettingsBackGround.BackgroundSprite);
		window.draw(gameSettings.GameSettingssLabel.text);
		window.display();
	}
	void EnterPressed(GameSettings& gameSettings) {
		if (gameSettings.isSoundOn) {
			gameSettings.isSoundOn = false;
		}
		else {
			gameSettings.isSoundOn = true;
		}
	}
}