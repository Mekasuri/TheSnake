#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cassert>
#include "Settings.h"
#include "Math.h"
#include "GameData.h"
#include "MainMenu.h"//include BackGround
#include "Snake.h"
#include "Apple.h"

using namespace TheSnake;

int main()
{
	int seed = time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TheSnake");

	//Game
	GameState gameState = GameState::MainMenu;

	//Main menu initialisaton 
	Background mainMenuBackground;
	MainMenuInitialization(mainMenuBackground);

	//Game Background Initialization
	Background gameBackGround;
	GameBackgroundInitialization(gameBackGround);
	
	int UpperFrame = 120;
	int SideFrame = 45;
	int LowerFrame = 33;

	//ApplesInitialization
	Apple apple;
	AppleInitialization(apple, UpperFrame, SideFrame, LowerFrame);
	Snake snake;
	SnakeInitialization(snake);

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
		}

		//SO IMPORTANT CHECK
		if (gameState == GameState::MainGame) {
			
			SnakeMove(snake, deltaTime);

			SnakeCollisions(snake, apple.ApplePosition,apple.AppleSprite, UpperFrame, SideFrame, LowerFrame);

			UpdateSnakePosition(snake, deltaTime);
			
			//DRAWING
			window.clear();
			window.draw(gameBackGround.BackgroundSprite);
			ApplePrint(apple, window);
			SnakePrint(snake, window);
			window.display();
		}
		else if (gameState == GameState::MainMenu) {
			MainMenuMainLoop(window, mainMenuBackground, gameState);
		}

		//EVENT
	}

	return 0;
}
