#include "MainMenu.h"
#include "Math.h"
#include <cassert>

namespace TheSnake {
	void MainMenuInitialization(Background& mainMenuBackground, TextsForMainMenu& texts, Choice& choice) {
		choice = Choice::StartGame;
		MainMenuBackgroundInitialization(mainMenuBackground);
		texts.labelName.message = "THE SNAKE";
		texts.labelName.position.X = SCREEN_WIDTH / 2 - 160;
		texts.labelName.position.Y = 10.f;
		texts.labelName.textSize = 70;
		texts.labelName.color = sf::Color::Green;
		LabelInitialization(texts.labelName);

		texts.mainMenuTexts.resize(5);
		texts.mainMenuTexts[0].message = "START GAME";
		texts.mainMenuTexts[1].message = "DIFFICULTY LEVEL";
		texts.mainMenuTexts[2].message = "RECORDS";
		texts.mainMenuTexts[3].message = "SETTINGS";
		texts.mainMenuTexts[4].message = "EXIT";
		int distance = 0;

		for (int i = 0; i < texts.mainMenuTexts.size(); ++i) {
			texts.mainMenuTexts[i].color = sf::Color::Green;
			texts.mainMenuTexts[i].position.X = 10;
			texts.mainMenuTexts[i].position.Y = 120 + distance;
			distance += 45;
			texts.mainMenuTexts[i].textSize = 40;
			LabelInitialization(texts.mainMenuTexts[i]);
		}

		SoundInitialization(texts.ClickSound, "klick.wav");

		texts.Clock.color = sf::Color::White;
		texts.Clock.message = "3";
		texts.Clock.position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 30 };
		texts.Clock.textSize = 30;
		LabelInitialization(texts.Clock);


	}
	void MainMenuMainLoop(sf::RenderWindow& window, Background& mainMenuBackground, GameState& gameState, TextsForMainMenu& texts, Choice& choice, GameLoop& gameLoop, bool isSound, float deltaTime) {

		if (choice == Choice::StartGame) {
			texts.mainMenuTexts[static_cast<int>(choice)].text.setFillColor(sf::Color::Red);
			texts.mainMenuTexts[static_cast<int>(choice) + 1].text.setFillColor(sf::Color::Green);

		}
		else if (choice == Choice::DifficultyLevel) {
			texts.mainMenuTexts[static_cast<int>(choice) - 1].text.setFillColor(sf::Color::Green);
			texts.mainMenuTexts[static_cast<int>(choice)].text.setFillColor(sf::Color::Red);
			texts.mainMenuTexts[static_cast<int>(choice) + 1].text.setFillColor(sf::Color::Green);
		}
		else if (choice == Choice::Records) {
			texts.mainMenuTexts[static_cast<int>(choice) - 1].text.setFillColor(sf::Color::Green);
			texts.mainMenuTexts[static_cast<int>(choice)].text.setFillColor(sf::Color::Red);
			texts.mainMenuTexts[static_cast<int>(choice) + 1].text.setFillColor(sf::Color::Green);
		}
		else if (choice == Choice::Settings) {
			texts.mainMenuTexts[static_cast<int>(choice) - 1].text.setFillColor(sf::Color::Green);
			texts.mainMenuTexts[static_cast<int>(choice)].text.setFillColor(sf::Color::Red);
			texts.mainMenuTexts[static_cast<int>(choice) + 1].text.setFillColor(sf::Color::Green);
		}
		else if (choice == Choice::Exit) {
			texts.mainMenuTexts[static_cast<int>(choice) - 1].text.setFillColor(sf::Color::Green);
			texts.mainMenuTexts[static_cast<int>(choice)].text.setFillColor(sf::Color::Red);
		}

		if (choice == Choice::StartGame && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (isSound && !texts.GameStart) {
				texts.ClickSound.sound.play();
			}
			texts.GameStart = true;
		}
		else if (choice == Choice::DifficultyLevel && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (isSound) {
				texts.ClickSound.sound.play();
			}
			gameState = GameState::Options;
		}
		else if (choice == Choice::Records && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (isSound) {
				texts.ClickSound.sound.play();
			}
			gameState = GameState::Records;
		}
		else if (choice == Choice::Settings && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (isSound) {
				texts.ClickSound.sound.play();
			}
			gameState = GameState::GameOptions;
		}
		else if (choice == Choice::Exit && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (isSound) {
				texts.ClickSound.sound.play();
			}
			window.close();
		}
		if (texts.GameStart) {
			texts.isVizible = true;
			UpdateState(gameLoop);
			if (texts.clockNum <= 3) {
				texts.Clock.message = "3";
				texts.Clock.text.setString(texts.Clock.message);
			}
			if (texts.clockNum <= 2) {
				texts.Clock.message = "2";
				texts.Clock.text.setString(texts.Clock.message);
			}
			if (texts.clockNum <= 1) {
				texts.Clock.message = "1";
				texts.Clock.text.setString(texts.Clock.message);
			}

			texts.clockNum -= deltaTime;
			if (texts.clockNum <= 0) {
				gameState = GameState::MainGame;
				texts.isVizible = false;
				texts.clockNum = 3;
				texts.GameStart = false;
			}
		}

		window.clear();
		window.draw(mainMenuBackground.BackgroundSprite);
		for (int i = 0; i < texts.mainMenuTexts.size(); ++i) {
			window.draw(texts.mainMenuTexts[i].text);
		}
		window.draw(texts.labelName.text);
		if (texts.isVizible) {
			window.draw(texts.Clock.text);
		}
		window.display();
	}

	void ListMenuDown(Choice& choice) {
		if (choice != Choice::Exit) {
			choice = static_cast<Choice>(static_cast<int>(choice) + 1);
		}
	}

	void ListMenuUp(Choice& choice) {
		if (choice != Choice::StartGame) {
			choice = static_cast<Choice>(static_cast<int>(choice) - 1);
		}
	}
}