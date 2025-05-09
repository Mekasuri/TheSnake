#include "Restart.h"
namespace TheSnake {
	bool operator<(const Players& a, const Players& b) {
		return a.score > b.score;
	}

	void RestartInitalization(Restart& restart, Score& score) {
		RestartBackgroundInitialization(restart.RestartBackground);
		restart.RestartText.resize(2);
		restart.RestartText[0].color = sf::Color::White;
		restart.RestartText[0].message = "PRESS \"ESC\" GO TO MAIN MENU";
		restart.RestartText[0].position = { 20, SCREEN_HEIGHT - 50 };
		restart.RestartText[0].textSize = 30;
		LabelInitialization(restart.RestartText[0]);

		restart.RestartText[1].color = sf::Color::White;
		restart.RestartText[1].message = "PRESS \"SPACE\" PLAY AGAIN";
		restart.RestartText[1].position = { 20, SCREEN_HEIGHT - 80 };
		restart.RestartText[1].textSize = 30;
		LabelInitialization(restart.RestartText[1]);

		restart.players = {
		{static_cast<int>(rand() / (float)RAND_MAX * restart.maxPlayersScore), "Lily"},
		{static_cast<int>(rand() / (float)RAND_MAX * restart.maxPlayersScore), "William"},
		{static_cast<int>(rand() / (float)RAND_MAX * restart.maxPlayersScore), "Ava"},
		{static_cast<int>(rand() / (float)RAND_MAX * restart.maxPlayersScore), "James"},
		{score.score, "YOU"}
		};

		restart.PlayersText = {
		restart.Isabella,
		restart.William,
		restart.Bella,
		restart.James,
		restart.YOU
		};

		restart.players[restart.PlayerPosition].score = score.score;
		std::sort(restart.players.begin(), restart.players.end());
		for (int i = 0; i != restart.PlayersText.size(); ++i) {
			if (restart.players[i].name == "YOU") {
				restart.PlayerPosition = i;
			}
			restart.PlayersText[i].message = (std::to_string(restart.players[i].score) + " " + restart.players[i].name);
			restart.PlayersText[i].position.X = 30;
			restart.PlayersText[i].position.Y = 40.f + restart.distance;
			restart.PlayersText[i].textSize = 70;
			LabelInitialization(restart.PlayersText[i]);
			restart.distance += 70.f;
		}

		SoundInitialization(restart.ClickSound, "klick.wav");
	}

	void RestartLoop(Restart& restart, sf::RenderWindow& window, GameState& gameState, Score& score, GameLoop& gameLoop) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			restart.ClickSound.sound.play();
			gameState = GameState::MainMenu;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			UpdateState(gameLoop);
			restart.ClickSound.sound.play();
			gameState = GameState::MainGame;
		}
		restart.distance = 0.f;
		restart.players[restart.PlayerPosition].score = score.score;
		std::sort(restart.players.begin(), restart.players.end());
		for (int i = 0; i != restart.PlayersText.size(); ++i) {
			if (restart.players[i].name == "YOU") {
				restart.PlayerPosition = i;
			}
			restart.PlayersText[i].message = (std::to_string(restart.players[i].score) + " " + restart.players[i].name);
			restart.PlayersText[i].position.X = 30;
			restart.PlayersText[i].position.Y = 40.f + restart.distance;
			restart.PlayersText[i].textSize = 70;
			LabelInitialization(restart.PlayersText[i]);
			restart.distance += 70.f;
		}

		window.clear();
		window.draw(restart.RestartBackground.BackgroundSprite);
		window.draw(restart.RestartText[0].text);
		window.draw(restart.RestartText[1].text);
		for (int i = 0; i != restart.PlayersText.size(); ++i) {
			window.draw(restart.PlayersText[i].text);
		}
		window.display();
	}
}