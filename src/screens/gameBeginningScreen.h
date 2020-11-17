//
// Created by rached on 11/11/2020.
//

#ifndef GAME_GAMEBEGINNINGSCREEN_H
#define GAME_GAMEBEGINNINGSCREEN_H

#include "../game/entities.h"
#include "cScreen.h"

class gameBeginningScreen : public cScreen {
public:
    gameBeginningScreen(Player &player);

    virtual int Run(sf::RenderWindow &App);
};

#endif //GAME_GAMEBEGINNINGSCREEN_H
