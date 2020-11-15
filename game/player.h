//
// Created by rached on 10/11/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "entitie.h"

class Player :  public entitie {
private:
    std::string name;
    sf::Clock clock;
    sf::Vector2i animation;
    void _addSprite(sf::IntRect);

public:
    Player(std::string name);
    sf::Sprite currentPosition;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void move_on_left();
    void move_on_right();
    void move_up();
    void move_down();
    void update();
};

#endif //GAME_PLAYER_H
