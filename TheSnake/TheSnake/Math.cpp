#include "Math.h"
namespace TheSnake {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();

		float originalWidth = spriteRect.width;
		float originalHeight = spriteRect.height;

		float scaleFactorX = originalWidth * desiredWidth;
		float scaleFactorY = originalHeight * desiredHeight;

		sf::Vector2f scale = { desiredWidth, desiredHeight };
		sprite.setScale(scale);
	}

	void SetSpriteOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(spriteRect.width * originX, spriteRect.height * originY);
	}

	bool collision(Position2D First, const float size1, Position2D Second, const float size2) {
		float squareDistance = (First.X - Second.X) * (First.X - Second.X) + (First.Y - Second.Y) * (First.Y - Second.Y);
		float squareRadiusSum = (size1 + size2) * (size1 + size2) / 4;
		if (squareDistance <= squareRadiusSum) {
			return true;
		}
		else {
			return false;
		}
	}
}