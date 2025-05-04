#pragma once
namespace TheSnake {

	struct Position2D {
		float X;
		float Y;
	};

	enum class Direction {
		Right = 0,
		Up,
		Left,
		Down
	};

	enum class GameState {
		MainGame,
		GameOptions,
		Records,
		Options,
		MainMenu
	};

	enum class DifficultyLevel {
		FirstLevel = 0,
		SecondLevel,
		ThirdLevel,
		FourthLevel,
		FifthLevel
	};
}
