#include "Sound.h"
#include "Settings.h"
#include <cassert>
namespace TheSnake {
	void SoundInitialization(Sound& sound, std::string soundName) {
		assert(sound.buffer.loadFromFile(RESOURCES_PATH + soundName));
		sound.sound.setBuffer(sound.buffer);
		sound.sound.setVolume(SOUND_VOLUME);
	}
}