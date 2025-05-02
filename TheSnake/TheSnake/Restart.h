#pragma once
#include "Backgrounds.h"
#include "Settings.h"
#include <vector>
#include "Text.h"
#include "GameData.h"
#include "Score.h"
namespace TheSnake {
	struct Players {
		int score;
		std::string name;
	};
	bool operator<(const Players& a, const Players& b);
	struct Restart {
		Background RestartBackground;
		std::vector<Label>RestartText;


		int maxPlayersScore = 70;
		std::vector<Players>players;

		Label Isabella;
		Label William;
		Label Bella;
		Label James;
		Label YOU;

		std::vector<Label>PlayersText;

		float distance = 0;
		int PlayerPosition = 4;

	};
	void RestartInitalization(Restart& restart, Score& score);
	void RestartLoop(Restart& restart, sf::RenderWindow& window, GameState& gameState, Score& score);
	
}