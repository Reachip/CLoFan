//
// Created by rached on 11/11/2020.
//

#include <SFML/Graphics.hpp>
#include "gameBeginningScreen.h"
#include "../ui/messageBox.h"

#define ECART_DE_PIXEL_COLLISION_FENETRE 25
#define BACKGROUND_PATH "./assets/Map_Scene_base_1.png"

gameBeginningScreen::gameBeginningScreen(Player &player) : cScreen(player) {}

int gameBeginningScreen::Run(sf::RenderWindow &App) {
    sf::Event event;

    background bg(BACKGROUND_PATH);
    messageBox message("Lorem ipsum");
    door door1(490, 500);

    player.move_on_right();
    player.currentPosition.setPosition(490, 480);
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

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            message.clear();
            player.move_on_right();
        }

        else
            animPlayer = false;

        if (!message.animationIsFinish())
            message.animate();

        if (animPlayer)
            player.update();

        handleOutOfWindow(App);

        App.draw(bg);
        App.draw(door1);
        App.draw(message);
        App.draw(player);
        App.display();
        App.clear();
    }

    return (-1);
}
