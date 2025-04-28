#include "Text.h"
#include "Settings.h"
#include <cassert>
namespace TheSnake {
    void LabelInitialization(Label& label) {
        assert(label.textFont.loadFromFile(RESOURCES_PATH + "/font.ttf"));
        label.text.setFont(label.textFont);
        label.text.setCharacterSize(label.textSize);
        label.text.setString(label.message);
        label.text.setPosition(label.position.X, label.position.Y);
        label.text.setFillColor(label.color);
    }
}