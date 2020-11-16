//
// Created by rached on 14/11/2020.
//


#include "background.h"
#define BACKGROUND_POSITION_X 341
#define BACKGROUND_POSITION_Y 480

background::background(std::string spritePath, int x, int y) : entitie(spritePath, x, y) {}
void background::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}

sf::Vector2u background::getSize() {
    return texture.getSize();
}