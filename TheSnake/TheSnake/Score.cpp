#include "Score.h"
namespace TheSnake {
	void scoreInitialization(Score& score) {
		score.scoreLabel.color = sf::Color::Green;
		score.scoreLabel.message = "Score: " + std::to_string(score.score);
		score.scoreLabel.position.X = 10;
		score.scoreLabel.position.Y = 15;
		score.scoreLabel.textSize = 40;
		LabelInitialization(score.scoreLabel);
	}
}