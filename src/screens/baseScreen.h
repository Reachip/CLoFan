//
// Created by rached on 11/11/2020.
//

#ifndef GAME_BASESCREEN_H
#define GAME_BASESCREEN_H
#define SAVEFILE "./sauvegarde.txt"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "../game/player.h"

class baseScreen {
public:
    baseScreen(Player &player, int screenPosition);

    virtual int Run(sf::RenderWindow &App) = 0;

    void handleOutOfBackground(sf::RenderWindow &App);

    void handleLeft(sf::Image details);

    void handleRight(sf::Image details);

    void handleUp(sf::Image details);

    void handleDown(sf::Image details);

    void saveProgression();

    int getProgression();

protected:
    int screenPosition;
    Player player;
    bool is_running;
};


#endif //GAME_BASESCREEN_H
