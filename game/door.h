//
// Created by rached on 14/11/2020.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H


#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>

class door : public sf::Drawable, public sf::Transformable {
public:
    door(void);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_DOOR_H
