//
// Created by rached on 16/11/2020.
//

#include "scene2Screen.h"
#include "../game/entities.h"
#include <iostream>

#define SCENE2_MAP "./"
#define SCENE2_DETAILS "./"

scene2Screen::scene2Screen(Player &player) : cScreen(player) {}

int scene2Screen::Run(sf::RenderWindow &App) {
    library library(0, 0);
    money money(0, 0);
    key key(0, 0);
    table(0, 0);

    sf::Image details;
    bool animPlayer = true;

     //if (!details.loadFromFile(SCENE2_DETAILS))
        //throw;

    //background background(SCENE2_MAP, 0, 0);
    sf::Event event;

    player.move_up();
    player.update();

    while (is_running) {
        while (App.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
                is_running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            handleUp(details);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            handleDown(details);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            handleLeft(details);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            handleRight(details);

        else
            animPlayer = false;

        if (animPlayer)
            player.update();

        App.clear();
        App.display();
    }

    return -1;
}