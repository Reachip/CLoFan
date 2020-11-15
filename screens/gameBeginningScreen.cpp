//
// Created by rached on 11/11/2020.
//

#include <SFML/Graphics.hpp>
#include "gameBeginningScreen.h"

#define ECART_DE_PIXEL_COLLISION_FENETRE 25
#define BACKGROUND_PATH "./assets/map_bois.png"

gameBeginningScreen::gameBeginningScreen(Player &player) : cScreen(player) {}

int gameBeginningScreen::Run(sf::RenderWindow &App) {
    sf::Event event;
    sf::View view;
    background bg(BACKGROUND_PATH);
    door d;
    d.setPosition(120, 120);
    player.currentPosition.setPosition(0, 0);
    player.move_up();
    player.update();

    while (is_running) {
        bool animPlayer = true;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            d.open();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
            d.close();

        if (animPlayer)
            player.update();

        handleOutOfWindow(App);
        App.draw(bg);
        App.draw(player);
        App.draw(d);
        App.display();
        App.clear();
    }

    return (-1);
}
