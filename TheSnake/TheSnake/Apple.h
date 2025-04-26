#pragma once
#include "GameData.h"
#include <SFML/Graphics.hpp>
namespace TheSnake {
	struct Apple {
		bool isAppleEaten = false;
		sf::Texture AppleTexture;
		sf::Sprite AppleSprite;
		Position2D ApplePosition;
	};
	void AppleInitialization(Apple& apple, int UpperFrame, int SideFrame, int LowerFrame);
	void ApplePrint(Apple& apple, sf::RenderWindow& window);
}
