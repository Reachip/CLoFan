//
// Created by rached on 11/11/2020.
//


#include <SFML/Graphics.hpp>
#include "../ui/stopwatch.h"
#include "game.h"

#define FONT_PATH "../assets/LiberationSerif-Regular.ttf"

void launchGame(sf::RenderWindow &window) {
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // Boucle de jeu principal, elle fait le lien entre les différentes maps
        // Quand on appuie sur echap, on sort de la boucle et retourne dans le menu principal
    }
}