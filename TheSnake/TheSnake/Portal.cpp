#include "Portal.h"
#include "Math.h"
#include <cassert>
namespace TheSnake {
	void PortalInitialization(Portal& portal, int UpperFrame, int SideFrame, int LowerFrame) {
		portal.PortalPosition.resize(2);
		portal.PortalSprite.resize(2);
		portal.PortalTexture.resize(2);
		for (int i = 0; i < portal.PortalSprite.size(); i++) {
			portal.PortalPosition[i].X = PORTAL_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * PORTAL_SIZE);
			portal.PortalPosition[i].Y = PORTAL_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * PORTAL_SIZE);
			assert(portal.PortalTexture[i].loadFromFile(RESOURCES_PATH + "/Portal.png"));
			portal.PortalSprite[i].setTexture(portal.PortalTexture[i]);
			SetSpriteSize(portal.PortalSprite[i], PORTAL_SIZE / (float)portal.PortalTexture[i].getSize().x, PORTAL_SIZE / (float)portal.PortalTexture[i].getSize().y);
			SetSpriteOrigin(portal.PortalSprite[i], 0.5, 0.5);
			portal.PortalSprite[i].setPosition(portal.PortalPosition[i].X, portal.PortalPosition[i].Y);
		}
	}
	void PortalPrint(Portal& portal, sf::RenderWindow& window, float& Timer, float Timer2, float delta, int UpperFrame, int SideFrame, int LowerFrame) {
		if (portal.isVizible) {
			for (int i = 0; i < portal.PortalSprite.size(); i++) {
				portal.ratation += SPEED_OF_PORTAL_ROTATION;
				if (portal.ratation >= 360) {
					portal.ratation = 0;
				}
				portal.PortalSprite[i].setRotation(portal.ratation);
				window.draw(portal.PortalSprite[i]);
			}
		}

		if (Timer <= 0) {
			if(portal.isVizible){
				portal.isVizible = false;
			}
			else {
				portal.isVizible = true;
			}
			Timer = Timer2;
			for (int i = 0; i < portal.PortalSprite.size(); i++) {
				portal.PortalPosition[i].X = PORTAL_SIZE + SideFrame + rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * SideFrame - 2 * PORTAL_SIZE);
				portal.PortalPosition[i].Y = PORTAL_SIZE + UpperFrame + rand() / (float)RAND_MAX * (SCREEN_HEIGHT - UpperFrame - LowerFrame - 2 * PORTAL_SIZE);
				portal.PortalSprite[i].setPosition(portal.PortalPosition[i].X, portal.PortalPosition[i].Y);
			}
		}
		else {
			Timer -= delta;
		}
	}
}