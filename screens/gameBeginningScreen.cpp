//
// Created by rached on 11/11/2020.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameBeginningScreen.h"
#include "../game/tilemap.h"

#define ECART_DE_PIXEL_COLLISION_FENETRE 25

gameBeginningScreen::gameBeginningScreen(Player &player) : cScreen(player) {}

int gameBeginningScreen::Run(sf::RenderWindow &App) {
    const int level[] =
    {
            2, 20, 45, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            2, 11, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            2, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
            2, 11, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            2, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            2, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map("./assets/duengon2.png", sf::Vector2u(16, 16), level, 16, 8);

    sf::Event event;
    sf::View view;
    sf::CircleShape circle(100);
    bool Running = true;

    player.currentPosition.setPosition(120, 20);
    circle.setPosition(100, 90);

    player.move_up();
    player.update();

    while (Running) {
        bool animPlayer = true;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move_up();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move_down();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move_on_left();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move_on_right();

        else
            animPlayer = false;

        if (animPlayer)
            player.update();

        handleOutOfWindow(App);
        App.draw(player);
        App.draw(map);
        App.display();
        App.clear();
    }

    return (-1);
}
