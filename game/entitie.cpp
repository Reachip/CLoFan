//
// Created by rached on 14/11/2020.
//

#include "entitie.h"

entitie::entitie(std::string spritePath) {
    if (!texture.loadFromFile(spritePath))
        throw;

    texture = texture;
    sprite.setTexture(texture);
}

void entitie::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}