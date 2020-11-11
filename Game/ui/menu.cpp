//
// Created by rached on 10/11/2020.
//
#define FONT_PATH "../assets/LiberationSerif-Regular.ttf"
#include <SFML/Graphics.hpp>
#include "button.h"
#include "menu.h"
#include "../game/game.h"


/*
 * Affiche le menu sur la fenêtre du jeu.
 */
void mainMenu(sf::RenderWindow &window) {
    sf::Text quitButton = quitMenuButton();
    sf::Text startButton = startMenuButton();

    sf::Font font;
    font.loadFromFile(FONT_PATH);

    startButton.setFont(font);
    quitButton.setFont(font);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();// choix de la police à utiliser

        }

        handlingButtonEvent(window, startButton, quitButton);
        window.clear();
        window.draw(startButton);
        window.draw(quitButton);
        window.display();
    }
}

/*
 * Gère les l'appuie sur le bouton quitté et le bouton commencer.
 * Si le bouton commencé est appuier, on lance la boucle de jeu principal.
 * Si le bouton quitter est appuier, on ferme la fenetre.
 *
 * Prend en paramètre une référence de la fenetre,
 * le bouton commencer de type sf::Text et le bouton quitter de type sf::Text.
 */
void handlingButtonEvent(sf::RenderWindow &window, sf::Text startButton, sf::Text quitButton) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (buttonIsTouched(startButton, window))
            launchGame(window);

        if (buttonIsTouched(quitButton, window))
            window.close();
    }
}

