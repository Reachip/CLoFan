#ifndef GAME_SCENE5SCREEN_H
#define GAME_SCENE5SCREEN_H

#include "../game/player.h"
#include "baseScreen.h"

class scene4Screen : public baseScreen {
public:
    scene4Screen(Player &player);

    virtual int Run(sf::RenderWindow &App);
};

#endif //GAME_SCENE5SCREEN_H
