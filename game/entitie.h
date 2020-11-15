//
// Created by rached on 14/11/2020.
//

#ifndef GAME_ENTITIE_H
#define GAME_ENTITIE_H

#include <SFML/Graphics.hpp>

class entitie : public sf::Drawable, public sf::Transformable {
public:
    entitie(std::string spritePath);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
    sf::Texture texture;
    sf::Sprite sprite;

private:
    std::string spritePath;
};

#endif //GAME_ENTITIE_H
