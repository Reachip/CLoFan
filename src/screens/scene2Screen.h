//
// Created by rached on 16/11/2020.
//

#ifndef GAME_SCENE2SCREEN_H
#define GAME_SCENE2SCREEN_H


#include "cScreen.h"

class scene2Screen : public cScreen {
public:
    scene2Screen(Player &player);
    virtual int Run(sf::RenderWindow &App) = 0;
};


#endif //GAME_SCENE2SCREEN_H
