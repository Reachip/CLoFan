//
// Created by rached on 18/11/2020.
//

#ifndef GAME_GAMEOVER_H
#define GAME_GAMEOVER_H

#include "cScreen.h"

class gameOver : public cScreen {
public:
    gameOver(Player &player);
    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_GAMEOVER_H
