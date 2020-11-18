//
// Created by rached on 17/11/2020.
//

#include "timer.h"

#define FONT "../assets/LiberationSerif-Regular.ttf"

timer::timer(float _time) {
    if (!font.loadFromFile(FONT))
        throw;

    time = _time;
    text.setPosition(0, 0);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
}

void timer::update() {
    if (!is_paused) {
        int elapsedTime = clock.getElapsedTime().asSeconds();

        if (elapsedTime >= 1) {
            this->time--;
            text.setString(std::to_string(time));
            clock.restart();
        }
    }
}

bool timer::isFinish() {
    if (time <= 0)
        return true;

    return false;
}

void timer::pause() {
    text.setString(std::to_string(time));
    is_paused = true;
}

void timer::unpause() {
    is_paused = false;
}

void timer::restart() {
    text.setString("");
    time = 60;
}

void timer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
}


