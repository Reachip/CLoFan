//
// Created by rached on 11/11/2020.
//

#ifndef GAME_CSCREEN_H
#define GAME_CSCREEN_H

#include <SFML/Graphics.hpp>
#include "../game/player.h"

class cScreen {
public:
    cScreen(Player &player);
    virtual int Run(sf::RenderWindow &App) = 0;
    void handleOutOfBackground(sf::RenderWindow &App);

protected:
    Player player;
    bool is_running;
};


#endif //GAME_CSCREEN_H
