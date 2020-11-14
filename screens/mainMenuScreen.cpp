//
// Created by rached on 11/11/2020.
//

#define FONT_PATH "./assets/LiberationSerif-Regular.ttf"
#define MENU_BG "./assets/menu_sfml.png"

#include <iostream>

#include "../game/player.h"
#include "mainMenuScreen.h"
#include "../ui/button.h"

mainMenuScreen::mainMenuScreen(Player &player) : cScreen(player) {
    this->player = player;
}

int mainMenuScreen::Run(sf::RenderWindow &App) {
    bool Running = true;
    bool stopUpdatingPlayer = false;

    sf::Texture bg;
    sf::Event Event;
    sf::Sprite bgSprite;
    sf::Text quitButton = quitMenuButton();
    sf::Text startButton = startMenuButton();
    sf::Font font;
    player.currentPosition.setPosition(0, 530);

    if (!bg.loadFromFile(MENU_BG) || !font.loadFromFile(FONT_PATH)) {
        throw;
    }

    bgSprite.setTexture(bg);
    startButton.setFont(font);
    quitButton.setFont(font);

    while (Running) {
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                Running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            return 1;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (buttonIsTouched(startButton, App)) {
                return 1;
            }

            if (buttonIsTouched(quitButton, App))
                Running = false;
        }


        player.move_on_right();
        player.update();

        App.clear();
        App.draw(bgSprite);
        App.draw(quitButton);
        App.draw(startButton);
        App.draw(player);
        App.display();
    }

    return -1;
}

