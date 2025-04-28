#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GameData.h"
namespace TheSnake {
	struct Label {
		Position2D position{};
		std::string message = "";
		sf::Text text;
		sf::Font textFont;
		sf::Color color = sf::Color::White;
		unsigned textSize = 30;
	};
	void LabelInitialization(Label& label);
}