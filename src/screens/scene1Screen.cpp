//
// Created by rached on 12/11/2020.
//

#include "scene1Screen.h"

scene1Screen::scene1Screen(Player &player) : cScreen(player) {}

int scene1Screen::Run(sf::RenderWindow &App) {
    sf::Event event;

    while (is_running) {
        while (App.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
                is_running = false;
        }

        App.clear();
        App.display();
    }

    return 0; // Va au menu principal
}