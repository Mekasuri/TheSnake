#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Settings.h"
#include <vector>
namespace TheSnake {
	struct Portal {
		std::vector <sf::Texture> PortalTexture;
		std::vector <sf::Sprite> PortalSprite;
		std::vector <Position2D> PortalPosition;
		float ratation = 0;
		bool isTeleported = false;
		float timer = PORTAL_TIMER;
		bool isVizible = true;
	};
	void PortalInitialization(Portal& portal, int UpperFrame, int SideFrame, int LowerFrame);
	void PortalPrint(Portal& portal, sf::RenderWindow& window, float& Timer, float Timer2, float delta, int UpperFrame, int SideFrame, int LowerFrame);
}