#pragma once
#include <SFML/Graphics.hpp>
namespace TheSnake {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteOrigin(sf::Sprite& sprite, float originX, float originY);
}