//
// Created by rached on 11/11/2020.
//

#define FONT_PATH "./assets/LiberationSerif-Regular.ttf"

#include "mainMenuScreen.h"
#include "../ui/button.h"

mainMenuScreen::mainMenuScreen(void) {

}

int mainMenuScreen::Run(sf::RenderWindow &App) {
    bool Running = true;

    sf::Event Event;
    sf::Text quitButton = quitMenuButton();
    sf::Text startButton = startMenuButton();

    sf::Font font;

    if (!font.loadFromFile(FONT_PATH)) {
        throw;
    }

    startButton.setFont(font);
    quitButton.setFont(font);

    while (Running) {
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                Running = false;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                return 1;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (buttonIsTouched(startButton, App)) {
                    return 1;
                }

                if (buttonIsTouched(quitButton, App))
                    Running = false;
            }

            App.clear();
            App.draw(quitButton);
            App.draw(startButton);
            App.display();
        }
    }

    return -1;
}

