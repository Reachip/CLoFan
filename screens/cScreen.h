//
// Created by rached on 11/11/2020.
//

#ifndef GAME_CSCREEN_H
#define GAME_CSCREEN_H

#include <SFML/Graphics.hpp>
#include "../game/player.h"

class cScreen {
public:
    virtual int Run(sf::RenderWindow &App) = 0;
    static void handleOutOfWindow(sf::RenderWindow &App, Player &player);
};


#endif //GAME_CSCREEN_H
