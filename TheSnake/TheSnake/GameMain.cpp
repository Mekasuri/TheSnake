#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cassert>
#include "Settings.h"
#include "Math.h"
#include "GameData.h"
#include "MainMenu.h"//include BackGround
#include "GameLoop.h"
#include "Restart.h"
#include "DifficultLevel.h"
#include "GameSettings.h"

using namespace TheSnake;

int main()
{
	int seed = time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TheSnake");

	//Game
	GameState gameState = GameState::MainMenu;


	//Main menu initialisaton
	Choice choice;
	TextsForMainMenu textsForMainMenu;
	Background mainMenuBackground;
	MainMenuInitialization(mainMenuBackground, textsForMainMenu, choice);

	GameLoop gameLoop;
	GameLoopInitialization(gameLoop);

	//Restart initialization
	Restart restart;
	RestartInitalization(restart, gameLoop.score);

	//Settings initialization
	DifficultLevelStruct difficultyLevelStruct;
	ChoiceSettings choiceSettings;
	DifficultLevelInitialization(difficultyLevelStruct, choiceSettings);

	GameSettings gameSettings;
	GameSettingsInitialization(gameSettings);

	//TIME
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		//SOME GAME STUFF
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					if (gameState == GameState::MainMenu && !textsForMainMenu.isVizible) {
						ListMenuUp(choice);
					}
					else if (gameState == GameState::Options) {
						ListChoiceSettingsUp(choiceSettings);
					}
					if (gameSettings.isSoundOn) {
						difficultyLevelStruct.ClickSound.sound.play();
					}
				}
				else if (event.key.code == sf::Keyboard::Down) {
					if (gameState == GameState::MainMenu && !textsForMainMenu.isVizible) {
						ListMenuDown(choice);
					}
					else if (gameState == GameState::Options) {
						ListChoiceSettingsDown(choiceSettings);
					}
					if (gameSettings.isSoundOn) {
						difficultyLevelStruct.ClickSound.sound.play();
					}
				}
				else if (event.key.code == sf::Keyboard::Enter && gameState == GameState::GameOptions) {
					EnterPressed(gameSettings);
				}
			}
		}

		//SO IMPORTANT CHECK
		if (gameState == GameState::MainGame) {
			GameLoopLogic(gameLoop, deltaTime, window, gameState, difficultyLevelStruct.difficultyLevel, gameSettings.isSoundOn);

		}
		else if (gameState == GameState::MainMenu) {
			MainMenuMainLoop(window, mainMenuBackground, gameState, textsForMainMenu, choice, gameLoop, gameSettings.isSoundOn, deltaTime);
		}
		else if (gameState == GameState::Records) {
			RestartLoop(restart, window, gameState, gameLoop.score, gameLoop, gameSettings.isSoundOn);
		}
		else if (gameState == GameState::Options) {
			DifficultLevelLoop(difficultyLevelStruct,choiceSettings,window,gameState, deltaTime);
		}
		else if (gameState == GameState::GameOptions) {
			GameSettingsLoop(gameSettings, window, gameState);
		}

		//EVENT
	}

	return 0;
}
