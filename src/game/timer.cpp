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
    int elapsedTime = clock.getElapsedTime().asSeconds();

    if (elapsedTime >= 1) {
        this->time--;
        text.setString(std::to_string(time));
        clock.restart();
    }
}

bool timer::isFinish() {
    if (time <= 0)
        return true;

    return false;
}

void timer::destroy() {
    text.setString("");
    time = 0;
}

void timer::restart() {
    text.setString("");
    time = 60;
}

void timer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
}


