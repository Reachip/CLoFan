//
// Created by rached on 10/11/2020.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

sf::Text createButton(std::string text);
sf::Text quitMenuButton();
sf::Text startMenuButton();
int buttonIsTouched(sf::Text button, sf::RenderWindow &window);

#endif //GAME_BUTTON_H
