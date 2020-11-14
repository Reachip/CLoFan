//
// Created by rached on 14/11/2020.
//

#include "door.h"
#define DOOR_SPRITE_PATH ""

door::door(void) {}
void door::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}