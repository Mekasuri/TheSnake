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

using namespace TheSnake;

int main()
{
	int seed = time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TheSnake");

	//Game
	GameState gameState = GameState::MainMenu;

	//Restart init
	Restart restart;
	RestartInitalization(restart);

	//Main menu initialisaton
	Choice choice;
	TextsForMainMenu textsForMainMenu;
	Background mainMenuBackground;
	MainMenuInitialization(mainMenuBackground, textsForMainMenu, choice);

	GameLoop gameLoop;
	GameLoopInitialization(gameLoop);

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
					ListMenuUp(choice);
				}
				else if (event.key.code == sf::Keyboard::Down) {
					ListMenuDown(choice);
				}
			}
		}

		//SO IMPORTANT CHECK
		if (gameState == GameState::MainGame) {
			GameLoopLogic(gameLoop, deltaTime, window, gameState);

		}
		else if (gameState == GameState::MainMenu) {
			MainMenuMainLoop(window, mainMenuBackground, gameState, textsForMainMenu, choice);
		}
		else if (gameState == GameState::Records) {
			RestartLoop(restart, window);
		}

		//EVENT
	}

	return 0;
}
