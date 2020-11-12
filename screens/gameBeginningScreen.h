//
// Created by rached on 11/11/2020.
//

#ifndef GAME_GAMEBEGINNINGSCREEN_H
#define GAME_GAMEBEGINNINGSCREEN_H

#include "../game/player.h"
#include "cScreen.h"

class gameBeginningScreen : public cScreen {
private:
    Player player;

public:
    gameBeginningScreen(Player &player);
    virtual int Run(sf::RenderWindow &App);
};

#endif //GAME_GAMEBEGINNINGSCREEN_H
