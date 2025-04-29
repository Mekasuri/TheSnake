#pragma once
#include "Backgrounds.h"
namespace TheSnake {
	struct Restart {
		Background RestartBackground;
	};
	void RestartInitalization(Restart& restart);
	void RestartLoop(Restart& restart, sf::RenderWindow& window);
}