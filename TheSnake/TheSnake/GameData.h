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
		MainMenu,
		Options,
		GameOptions,
		Records
	};
}