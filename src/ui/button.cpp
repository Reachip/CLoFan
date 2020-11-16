//
// Created by rached on 10/11/2020.
//

#define TAILLE_BOUTON 40
#define POSITION_X 520
#define POSITION_Y 290
#define ECART_BOUTON 200

#include <SFML/Graphics.hpp>
#include "button.h"

/*
 * Créer un bouton quelquonque, blanc de taille définis par
 * la constante TAILLE_BOUTON affichant la chaîne de caractère
 * text passé en paramètre.
 *
 * Retourne un objet de type Text
 */
sf::Text createButton(std::string text) {
    sf::Text textObj;
    textObj.setString(text);
    textObj.setStyle(sf::Text::Bold);
    textObj.setFillColor(sf::Color::White);
    textObj.setCharacterSize(TAILLE_BOUTON);

    return textObj;
}

/*
 * Créer un bouton "Quitter"
 * Retourne un objet de type Text
 */
sf::Text quitMenuButton() {
    sf::Text quit = createButton("Quitter");
    quit.setPosition(POSITION_X - ECART_BOUTON, POSITION_Y);

    return quit;
}

/*
 * Créer un bouton "Commencer"
 * Retourne un objet de type Text
 */
sf::Text startMenuButton() {
    sf::Text start = createButton("Commencer");
    start.setPosition(POSITION_X, POSITION_Y);

    return start;
}

/*
 * Vérifie si un bouton a été touché par la souris.
 *
 * La fonction prend en paramètre un objet sf::Text
 * ainsi qu'un objet sf::Mouse et retourne un boolean.
 */
int buttonIsTouched(sf::Text button, sf::RenderWindow &window) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds = button.getGlobalBounds();

    return bounds.contains(mouse);
}