//
// Created by rached on 10/11/2020.
//

#include "stdio.h"
#include "player.h"

Player create_player(char name[20]) {
    Player player = {name};
    return player;
}

void move_on_the_left(Player *player) {
    printf("Hello World");
}