//
// Created by rached on 13/11/2020.
//

#define WIN_HEIGHT 683
#define WIN_WIDTH 960

#define WIDTH 24
#define HEIGHT 32
#define FULLSTEP 6

#define SAVEFILE "./sauvegarde"


#include "baseScreen.h"

#define ECART_DE_PIXEL_COLLISION_FENETRE 25

void baseScreen::handleOutOfBackground(sf::RenderWindow &App) {
    sf::Vector2f playerPosition = player.getSprite().getPosition();
    sf::Vector2i windowPosition = sf::Vector2i(WIN_WIDTH, WIN_HEIGHT);

    if (playerPosition.x < 0) {
        player.currentPosition.setPosition(0, playerPosition.y);
    }

    if (playerPosition.y < 0) {
        player.currentPosition.setPosition(playerPosition.x, 0);
    }

    if (playerPosition.y > windowPosition.y - ECART_DE_PIXEL_COLLISION_FENETRE) {
        player.currentPosition.setPosition(playerPosition.x, (windowPosition.y - ECART_DE_PIXEL_COLLISION_FENETRE));
    }

    if (playerPosition.x > windowPosition.x - ECART_DE_PIXEL_COLLISION_FENETRE) {
        player.currentPosition.setPosition(windowPosition.x - ECART_DE_PIXEL_COLLISION_FENETRE, playerPosition.y);
    }
}


baseScreen::baseScreen(Player &player, int screenPosition) : player(player) {
    player = player;
    is_running = true;
    this->screenPosition = screenPosition;
}

/*
 * y = height
 * x = width
 */

void baseScreen::handleUp(sf::Image details) {
    bool collision = false;
    for (int i = 0; i < FULLSTEP; i++) {
        for (int i = 0; i <= WIDTH; i++) {
            int joueurx = player.currentPosition.getPosition().x;
            int joueury = player.currentPosition.getPosition().y + HEIGHT / 2;

            if (details.getPixel(joueurx + i, joueury) == sf::Color::Red) {
                collision = true;
            }
        }

        if (!collision) {
            player.move_up();
        }
    }
}

void baseScreen::handleDown(sf::Image details) {
    bool collision = false;

    for (int i = 0; i < FULLSTEP; i++) {
        for (int i = 0; i <= WIDTH; i++) {
            int joueurx = player.currentPosition.getPosition().x;
            int joueury = player.currentPosition.getPosition().y + HEIGHT;

            if (details.getPixel(joueurx + i, joueury) == sf::Color::Red) {
                collision = true;
            }
        }

        if (!collision) {
            player.move_down();
        }
    }
}

void baseScreen::handleLeft(sf::Image details) {
    bool collision = false;

    for (int i = 0; i < FULLSTEP; i++) {
        for (int i = 2; i <= HEIGHT / 2 - 2; i++) {
            int joueurx = player.currentPosition.getPosition().x - 1;
            int joueury = player.currentPosition.getPosition().y + HEIGHT / 2;

            if (details.getPixel(joueurx, joueury + i) == sf::Color::Red) {
                collision = true;
            }
        }

        if (!collision) {
            player.move_on_left();
        }
    }
}

void baseScreen::saveProgression() {
    std::ofstream saveFile;
    saveFile.open(SAVEFILE);
    saveFile << std::to_string(screenPosition);
    saveFile.close();
}

int baseScreen::getProgression() {
    std::string progression;
    std::ifstream saveFile(SAVEFILE);

    if (saveFile.is_open())
        getline(saveFile, progression);

    try {
        return std::stoi(progression);
    } catch (const std::invalid_argument &e) {
        return 0;
    }
}

void baseScreen::handleRight(sf::Image details) {
    bool collision = false;

    for (int i = 0; i < FULLSTEP; i++) {
        for (int i = 2; i <= HEIGHT / 2 - 2; i++) {
            int joueurx = player.currentPosition.getPosition().x + WIDTH + 1;
            int joueury = player.currentPosition.getPosition().y + HEIGHT / 2;

            if (details.getPixel(joueurx, joueury + i) == sf::Color::Red) {
                collision = true;
            }
        }

        if (!collision) {
            player.move_on_right();
        }
    }
}
