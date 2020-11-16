//
// Created by rached on 15/11/2020.
//

#define FONT_PATH ""
#define TAILLE 20
#define POSITION_X 300
#define POSITION_Y -30
#define FONT_PATH "./assets/LiberationSerif-Regular.ttf"
#define ANIMATION_SPEED 2

#include <iostream>
#include "messageBox.h"


messageBox::messageBox(std::string text) {
    message.setFillColor(sf::Color::White);
    message.setCharacterSize(TAILLE);

    if (!font.loadFromFile(FONT_PATH)) {
        throw;
    }

    message.setFont(font);
    message.setPosition(POSITION_X, POSITION_Y);
    message.setString(text);
}

void messageBox::update(std::string newText) {
    message.setPosition(POSITION_X, POSITION_Y);
    message.setString(newText);
}

void messageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(message, states);
}

void messageBox::animate() {
    float new_x_position =  message.getPosition().y + ANIMATION_SPEED;
    message.setPosition(POSITION_X, new_x_position);
}

void messageBox::clear() {
    message.setString("");
}

bool messageBox::animationIsFinish() {
    if (message.getPosition().y >= 2)
        return true;

    return false;
}