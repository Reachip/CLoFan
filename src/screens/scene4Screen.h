#ifndef GAME_SCENE5SCREEN_H
#define GAME_SCENE5SCREEN_H

#include "../game/player.h"
#include "cScreen.h"

class scene4Screen : public cScreen {
public:
    scene4Screen(Player &player);

    virtual int Run(sf::RenderWindow &App);
};

#endif //GAME_SCENE5SCREEN_H
