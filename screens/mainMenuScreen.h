//
// Created by rached on 11/11/2020.
//

#ifndef GAME_MAINMENUSCREEN_H
#define GAME_MAINMENUSCREEN_H

#include "cScreen.h"


class mainMenuScreen : public cScreen {
private:
    sf::Event Event;
    sf::Text quitButton;
    sf::Text startButton;
    sf::Font font;

public:
    mainMenuScreen(void);

    virtual int Run(sf::RenderWindow &App);
};


#endif //GAME_MAINMENUSCREEN_H
