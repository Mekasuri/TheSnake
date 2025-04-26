#include "MainMenu.h"
#include "Math.h"
#include <cassert>
namespace TheSnake {
	void MainMenuInitialization(Background& mainMenuBackground) {
		MainMenuBackgroundInitialization(mainMenuBackground);
	}
	void MainMenuMainLoop(sf::RenderWindow& window, Background& mainMenuBackground, GameState& gameState) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			gameState = GameState::MainGame;
		}
		window.clear();
		window.draw(mainMenuBackground.BackgroundSprite);
		window.display();
	}
}