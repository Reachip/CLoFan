//
// Created by rached on 11/11/2020.
//

#ifndef GAME_CSCREEN_H
#define GAME_CSCREEN_H

#include <SFML/Graphics.hpp>

class cScreen {
public:
    virtual int Run(sf::RenderWindow &App) = 0;
};


#endif //GAME_CSCREEN_H
