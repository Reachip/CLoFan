//
// Created by rached on 11/11/2020.
//

#ifndef GAME_MAINMENUSCREEN_H
#define GAME_MAINMENUSCREEN_H

#include "baseScreen.h"
#include "../game/player.h"

class mainMenuScreen : public baseScreen {
public:
    mainMenuScreen(Player &player);

    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_MAINMENUSCREEN_H
