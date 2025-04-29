#include "Restart.h"
namespace TheSnake {
	void RestartInitalization(Restart& restart) {
		RestartBackgroundInitialization(restart.RestartBackground);
	}
	void RestartLoop(Restart& restart, sf::RenderWindow& window) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		window.clear();
		window.draw(restart.RestartBackground.BackgroundSprite);
		window.display();
	}
}