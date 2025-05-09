#pragma once
#include <SFML/Audio.hpp>
#include <string>
namespace TheSnake {
	struct Sound {
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};
	void SoundInitialization(Sound& sound, std::string soundName);
}