#pragma once
#include "Text.h"
namespace TheSnake {
	struct Score {
		int score = 0;
		Label scoreLabel;
	};
	void scoreInitialization(Score& score);
}