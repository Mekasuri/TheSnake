#include "Math.h"
namespace TheSnake {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		float originalWidth = spriteRect.width;
		float scaleFactor = desiredWidth / originalWidth;
		sf::Vector2f scale = { scaleFactor, scaleFactor };
		sprite.setScale(scale);
	}

	void SetSpriteOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}