//
// Created by rached on 11/11/2020.
//

#ifndef GAME_CSCREEN_H
#define GAME_CSCREEN_H

#include <SFML/Graphics.hpp>
#include "../game/player.h"

class cScreen {
public:
    Player player;
    cScreen(Player &player);
    virtual int Run(sf::RenderWindow &App) = 0;
    void handleOutOfWindow(sf::RenderWindow &App);
};


#endif //GAME_CSCREEN_H
