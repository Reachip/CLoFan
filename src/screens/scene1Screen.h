//
// Created by rached on 12/11/2020.
//

#ifndef GAME_SCENE1SCREEN_H
#define GAME_SCENE1SCREEN_H

#include "baseScreen.h"


class scene1Screen : public baseScreen {
public:
    scene1Screen(Player &player, int screenPosition);

    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_SCENE1SCREEN_H
