//
// Created by rached on 10/11/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    std::string name;
    void _addSprite(sf::IntRect);

public:
    Player(std::string name, std::string spritePath);
    sf::Sprite currentPosition;
    void move_on_left();
    void move_on_right();
    void move_up();
    void move_down();
};

#endif //GAME_PLAYER_H
