#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene5Screen.h"
#include "../game/background.h"
#include "../game/entities.h"

#include "../ui/messageBox.h"
#include "../game/bed.h"
#include"../game/pnj.h"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;


scene5Screen::scene5Screen(Player &player) : cScreen(player) {}


int scene5Screen::Run(sf::RenderWindow &App) {

    bool statueIsTouched;
    bool biblioIsTouched;
    bool litIsTouched;

    pnj statue("../assets/statue1.png", 445, 550);
    bed lit(174, 280);
    messageBox message("Bienvenue dans la scene 4");
    library biblio(30, 185);

    sf::Event event;

    background background("../assets/scene4.png", 0, 0);

    sf::Image details;
    details.loadFromFile("../assets/scene4_details.png");

    player.currentPosition.setPosition(350, 500);
    player.move_up();
    player.update();

    while (is_running) {

            int nbTouch = 0;


        if (!message.animationIsFinish()) {
            message.animate();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player.currentPosition.setPosition(sf::Mouse::getPosition().x - 490, sf::Mouse::getPosition().y - 200);
        }

        bool animPlayer = true;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            handleUp(details);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            handleDown(details);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            handleLeft(details);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            handleRight(details);
        } else
            animPlayer = false;

        if (animPlayer)
            player.update();



        if (statue.is_touched(player.currentPosition) && !statueIsTouched) {
            message.update("Le temps est au repos, vivez une journée normale.");
            statueIsTouched = true;
        }

        if (biblio.is_touched(player.currentPosition) && !biblioIsTouched) {
            message.update("Le savoir est la plus grande des armes.");
            biblioIsTouched = true;
        }

        if (lit.is_touched(player.currentPosition) && !litIsTouched) {
            message.update("ZZZZzzzzz...");

            if(lit.is_touched(player.currentPosition)){
            player.sleep();
            }
        }

        if (!statue.is_touched(player.currentPosition) && !biblio.is_touched(player.currentPosition) && !lit.is_touched(player.currentPosition)) {
        statueIsTouched = false;
        biblioIsTouched = false;
        litIsTouched = false;
        message.clear();
        }


        App.clear();
        App.draw(background);
        App.draw(message);
        App.draw(lit);
        App.draw(biblio);
        App.draw(statue);
        App.draw(player);
        App.display();
    }


    return (-1);
}
