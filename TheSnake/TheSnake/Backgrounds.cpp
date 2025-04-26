#include "Backgrounds.h"
#include "cassert"
#include "Math.h"
namespace TheSnake {
	void GameBackgroundInitialization(Background& gameBackground) {
		assert(gameBackground.BackgroundTexture.loadFromFile(RESOURCES_PATH + "/MainGameBackground.png"));
		gameBackground.BackgroundSprite.setTexture(gameBackground.BackgroundTexture);
		SetSpriteSize(gameBackground.BackgroundSprite, SCREEN_WIDTH / (float)gameBackground.BackgroundTexture.getSize().x, SCREEN_HEIGHT / (float)gameBackground.BackgroundTexture.getSize().y);
		SetSpriteOrigin(gameBackground.BackgroundSprite, 0.5, 0.5);
		gameBackground.BackgroundSprite.setPosition(gameBackground.BackgroundPosition.X, gameBackground.BackgroundPosition.Y);
	}

	void MainMenuBackgroundInitialization(Background& mainMenuBackground) {
		assert(mainMenuBackground.BackgroundTexture.loadFromFile(RESOURCES_PATH + "/MainMenuBackground.png"));
		mainMenuBackground.BackgroundSprite.setTexture(mainMenuBackground.BackgroundTexture);
		SetSpriteSize(mainMenuBackground.BackgroundSprite, SCREEN_WIDTH / (float)mainMenuBackground.BackgroundTexture.getSize().x + 0.3f, SCREEN_HEIGHT / (float)mainMenuBackground.BackgroundTexture.getSize().y);
		SetSpriteOrigin(mainMenuBackground.BackgroundSprite, 0.5, 0.5);
		mainMenuBackground.BackgroundSprite.setPosition(mainMenuBackground.BackgroundPosition.X, mainMenuBackground.BackgroundPosition.Y);
	}
}