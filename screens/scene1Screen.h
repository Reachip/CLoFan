//
// Created by rached on 12/11/2020.
//

#ifndef GAME_SCENE1SCREEN_H
#define GAME_SCENE1SCREEN_H

#include "cScreen.h"


class scene1Screen : public cScreen {
public:
        scene1Screen(void);
        virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_SCENE1SCREEN_H
