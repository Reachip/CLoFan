//
// Created by rached on 16/11/2020.
//

#ifndef GAME_SCENE2SCREEN_H
#define GAME_SCENE2SCREEN_H


#include "baseScreen.h"

class scene2Screen : public baseScreen {
public:
    scene2Screen(Player &player);

    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_SCENE2SCREEN_H
