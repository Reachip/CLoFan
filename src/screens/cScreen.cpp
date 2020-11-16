//
// Created by rached on 13/11/2020.
//

#define WIN_HEIGHT 683
#define WIN_WIDTH 960

#define WIDTH 24
#define HEIGHT 32

#include "cScreen.h"
#define ECART_DE_PIXEL_COLLISION_FENETRE 25

void cScreen::handleOutOfBackground(sf::RenderWindow &App) {
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


cScreen::cScreen(Player &player) : player(player)  {
    player = player;
    is_running = true;
}

/*
 * y = height
 * x = width
 */

void cScreen::handleUp(sf::Image details)  {
    bool collision = false;

    for(int i=0; i<=WIDTH; i++)
    {
        int joueurx = player.currentPosition.getPosition().x;
        int joueury = player.currentPosition.getPosition().y+HEIGHT/2;

        if(details.getPixel(joueurx+i, joueury) == sf::Color::Red)
        {
            collision = true;
        }
    }

    if(!collision){
        player.move_up();
    }
}

void cScreen::handleDown(sf::Image details) {
    bool collision = false;

    for(int i=0; i<=WIDTH; i++)
    {
        int joueurx = player.currentPosition.getPosition().x;
        int joueury = player.currentPosition.getPosition().y+HEIGHT;

        if(details.getPixel(joueurx+i, joueury) == sf::Color::Red)
        {
            collision = true;
        }
    }

    if(!collision){
        player.move_down();
    }
}

void cScreen::handleLeft(sf::Image details) {
    bool collision = false;
    for(int i=2; i<=HEIGHT/2-2; i++)
    {
        int joueurx = player.currentPosition.getPosition().x-1;
        int joueury = player.currentPosition.getPosition().y+HEIGHT/2;

        if(details.getPixel(joueurx, joueury+i) == sf::Color::Red)
        {
            collision = true;
        }
    }

    if(!collision){
        player.move_on_left();
    }
}

void cScreen::handleRight(sf::Image details) {
    bool collision = false;

    for(int i=2; i<=HEIGHT/2-2; i++)
    {
        int joueurx = player.currentPosition.getPosition().x+WIDTH+1;
        int joueury = player.currentPosition.getPosition().y+HEIGHT/2;

        if(details.getPixel(joueurx, joueury+i) == sf::Color::Red)
        {
            collision = true;
        }
    }

    if(!collision){
        player.move_on_right();
    }
}
