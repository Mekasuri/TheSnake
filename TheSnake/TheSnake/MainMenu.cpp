#include "MainMenu.h"
#include "Math.h"
#include <cassert>
namespace TheSnake {
	void MainMenuInitialization(MainMenu& mainMenu) {
		assert(mainMenu.MainMenuBackgroundTexture.loadFromFile(RESOURCES_PATH + "/MainMenuBackground.png"));
		mainMenu.MainMenuBackgroundSprite.setTexture(mainMenu.MainMenuBackgroundTexture);
		SetSpriteSize(mainMenu.MainMenuBackgroundSprite, SCREEN_WIDTH / (float)mainMenu.MainMenuBackgroundTexture.getSize().x + 0.3f, SCREEN_HEIGHT / (float)mainMenu.MainMenuBackgroundTexture.getSize().y);
		SetSpriteOrigin(mainMenu.MainMenuBackgroundSprite, 0.5, 0.5);
		mainMenu.MainMenuBackgroundSprite.setPosition(mainMenu.MainMenuBackgroundPosition.X, mainMenu.MainMenuBackgroundPosition.Y);
	}

	void MainMenuMainLoop(sf::RenderWindow& window, MainMenu& mainMenu, GameState& gameState) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			gameState = GameState::MainGame;
		}
		window.clear();
		window.draw(mainMenu.MainMenuBackgroundSprite);
		window.display();
	}
}