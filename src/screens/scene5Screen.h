#ifndef GAME_SCENE5SCREEN_H
#define GAME_SCENE5SCREEN_H

#include "../game/player.h"
#include "cScreen.h"

class scene5Screen : public cScreen {
public:
    scene5Screen(Player &player);
    virtual int Run(sf::RenderWindow &App);
};

#endif //GAME_SCENE5SCREEN_H
