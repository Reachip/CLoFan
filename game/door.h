//
// Created by rached on 14/11/2020.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include <SFML/Graphics.hpp>
#include "entitie.h"

class door : public entitie {
public:
    door(void);
    void open();
    void close();

private:
    sf::Texture openedDoor;
    sf::Texture closedDoor;

};


#endif //GAME_DOOR_H
