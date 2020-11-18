//
// Created by rached on 18/11/2020.
//

#ifndef GAME_GAMEOVER_H
#define GAME_GAMEOVER_H

#include "baseScreen.h"

class gameOver : public baseScreen {
public:
    gameOver(Player &player, int screenPosition);

    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_GAMEOVER_H
