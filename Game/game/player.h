//
// Created by rached on 10/11/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

typedef struct {
    char *name[10];
} Player;

Player create_player(char name[20]);
void move_on_the_left(Player *player);

#endif //GAME_PLAYER_H
