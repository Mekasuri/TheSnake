#include "Apple.h"
#include "Settings.h"
#include "Math.h"
#include <cassert>
namespace TheSnake {
	void AppleInitialization(Apple& apple, int UpperFrame, int SideFrame, int LowerFrame) {
		apple.ApplePosition.X = APPLE_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * APPLE_SIZE);
		apple.ApplePosition.Y = APPLE_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * APPLE_SIZE);
		assert(apple.AppleTexture.loadFromFile(RESOURCES_PATH + "/Apple.png"));
		apple.AppleSprite.setTexture(apple.AppleTexture);
		SetSpriteSize(apple.AppleSprite, APPLE_SIZE / (float)apple.AppleTexture.getSize().x, APPLE_SIZE / (float)apple.AppleTexture.getSize().y);
		SetSpriteOrigin(apple.AppleSprite, 0.5, 0.5);
		apple.AppleSprite.setPosition(apple.ApplePosition.X, apple.ApplePosition.Y);
	}
	void ApplePrint(Apple& apple, sf::RenderWindow& window) {
		window.draw(apple.AppleSprite);
	}
}