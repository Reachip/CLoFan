//
// Created by rached on 14/11/2020.
//


#include "background.h"
#define BACKGROUND_POSITION_X 341
#define BACKGROUND_POSITION_Y 480

background::background(std::string spritePath) : entitie(spritePath, 250, 100) {}
void background::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}