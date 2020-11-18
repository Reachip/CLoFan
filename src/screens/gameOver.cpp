//
// Created by rached on 18/11/2020.
//

#include "gameOver.h"
#include "../game/background.h"

#define GAMEOVER "../assets/GAME_OVER.png"

gameOver::gameOver(Player &player, int screenPosition) : baseScreen(player, screenPosition) {}
int gameOver::Run(sf::RenderWindow &App) {
    saveProgression();
    sf::Event event;
    background background(GAMEOVER, 0, 0);

    while (is_running) {
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;

        App.clear();
        App.draw(background);
        App.display();
    }

    return -1;
}

