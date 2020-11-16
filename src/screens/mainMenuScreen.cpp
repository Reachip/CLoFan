//
// Created by rached on 11/11/2020.
//

#define FONT_PATH "../assets/LiberationSerif-Regular.ttf"
#define MENU_BG "../assets/menu_sfml.png"

#include <iostream>

#include "../game/entities.h"
#include "mainMenuScreen.h"
#include "../ui/button.h"

mainMenuScreen::mainMenuScreen(Player &player) : cScreen(player) {
    this->player = player;
}

int mainMenuScreen::Run(sf::RenderWindow &App) {
    player.currentPosition.setPosition(0, 530);

    sf::Event Event;
    sf::Text quitButton = quitMenuButton();
    sf::Text startButton = startMenuButton();
    sf::Font font;

    background background(MENU_BG);

    if (!font.loadFromFile(FONT_PATH))
        throw;

    startButton.setFont(font);
    quitButton.setFont(font);

    while (is_running) {
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                is_running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            return 1;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (buttonIsTouched(startButton, App)) {
                return 1;
            }

            if (buttonIsTouched(quitButton, App))
                is_running = false;
        }

        player.move_on_right();
        player.update();
        App.clear();
        App.draw(background);
        App.draw(quitButton);
        App.draw(startButton);
        App.draw(player);
        App.display();
    }

    return -1;
}

