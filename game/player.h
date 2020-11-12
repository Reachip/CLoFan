//
// Created by rached on 10/11/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>

class Player {
private:
    std::string name;
    sf::Texture texture;
    sf::Sprite currentPosition;
    sf::Sprite leftPosition;
    sf::Sprite rightPosition;
    sf::Sprite downPosition;
    sf::Sprite upPosition;

    void _addSprite(sf::IntRect);

public:
    Player(std::string name, std::string spitePath);

    void move_on_left();

    void move_on_right();

    void move_up();

    void move_down();

    void update(sf::RenderWindow &window);

};

#endif //GAME_PLAYER_H
