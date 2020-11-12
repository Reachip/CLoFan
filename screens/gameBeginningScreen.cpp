//
// Created by rached on 11/11/2020.
//

#include <SFML/Graphics.hpp>
#include "gameBeginningScreen.h"
#include "../game/player.h"

gameBeginningScreen::gameBeginningScreen(Player &player) : player(player) {
    this->player = player;
}

int gameBeginningScreen::Run(sf::RenderWindow &App) {
    sf::Event event;
    bool Running = true;

    player.move_up();
    player.currentPosition.setPosition(120, 20);

    while (Running) {
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Running = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return 0;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                player.move_up();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                player.move_down();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player.move_on_left();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player.move_on_right();

            App.clear();
            App.draw(player.currentPosition);
            App.display();
        }
    }

    return (-1);
}
