//
// Created by rached on 13/11/2020.
//

#include "cScreen.h"
#define ECART_DE_PIXEL_COLLISION_FENETRE 25

void cScreen::handleOutOfWindow(sf::RenderWindow &App, Player &player) {
    sf::Vector2f playerPosition = player.currentPosition.getPosition();
    auto windowPosition = App.getSize();

    if (playerPosition.x < 0) {
        player.currentPosition.setPosition(0, playerPosition.y);
    }

    if (playerPosition.y < 0) {
        player.currentPosition.setPosition(playerPosition.x, 0);
    }

    if (playerPosition.y > windowPosition.y-ECART_DE_PIXEL_COLLISION_FENETRE) {
        player.currentPosition.setPosition(playerPosition.x, (windowPosition.y-ECART_DE_PIXEL_COLLISION_FENETRE));
    }

    if (playerPosition.x > windowPosition.x-ECART_DE_PIXEL_COLLISION_FENETRE) {
        player.currentPosition.setPosition(windowPosition.x-ECART_DE_PIXEL_COLLISION_FENETRE, playerPosition.y);
    }
}