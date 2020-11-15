//
// Created by rached on 14/11/2020.
//

#include "background.h"

background::background(std::string backgroundPath) : entitie(backgroundPath) {
    sprite.setPosition(0, 0);
}

void background::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}