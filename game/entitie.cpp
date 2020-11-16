//
// Created by rached on 14/11/2020.
//

#include "entitie.h"

entitie::entitie(std::string spritePath, int x, int y) {
    if (!texture.loadFromFile(spritePath))
        throw;

    texture = texture;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void entitie::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite, states);
}

bool entitie::is_touched(sf::Sprite obj) {
    return sprite.getGlobalBounds().intersects(obj.getGlobalBounds());
}