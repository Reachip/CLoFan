//
// Created by rached on 16/11/2020.
//

#ifndef GAME_SCENE3SCREEN_H
#define GAME_SCENE3SCREEN_H


#include "baseScreen.h"

class scene3Screen : public baseScreen {
public:
    scene3Screen(Player &player);
    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_SCENE3SCREEN_H
