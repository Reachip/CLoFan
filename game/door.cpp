//
// Created by rached on 14/11/2020.
//

#define DOOR_SPRITE_PATH "./assets/portef.png"
#define DOOR_SPRITE_IS_OPEN_PATH "./assets/porteo.png"

#include "door.h"

door::door() : entitie(DOOR_SPRITE_PATH) {
    openedDoor = texture;
}

void door::open() {
    if (!openedDoor.loadFromFile(DOOR_SPRITE_IS_OPEN_PATH))
        throw;

    sprite.setTexture(openedDoor);
}

void door::close() {
    if (!closedDoor.loadFromFile(DOOR_SPRITE_PATH))
        throw;

    sprite.setTexture(closedDoor);
}