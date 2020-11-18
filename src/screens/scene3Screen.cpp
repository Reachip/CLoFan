//
// Created by rached on 16/11/2020.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene3Screen.h"
#include "../game/background.h"
#include "../game/entities.h"
#include "../ui/messageBox.h"
#define WIDTH 24
#define HEIGHT 32

#define MAP "../assets/scene_finale.png"
#define DETAILS "../assets/scene_finale_details.png"
#define ENIGME_1 "../assets/enigme1.png"
#define ENIGME_2 "../assets/enigme2.png"
#define AFFICHE_1 "../assets/affiche1.png"
#define AFFICHE_2 "../assets/affiche2.png"
#define PNJ_1 "../assets/ange.png"
#define PNJ_2 "../assets/demon.png"
#define PNJ_3 "../assets/panc.png"
#define PNJ_4 "../assets/panc.png"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;
scene3Screen::scene3Screen(Player &player) : cScreen(player) {}

int scene3Screen::Run(sf::RenderWindow &App) {
    bool pnj1IsTouched = false;
    bool pnj2IsTouched = false;
    bool pnj3IsTouched = false;
    bool pnj4IsTouched = false;

    sf::Texture affiche1Texture;
    if (!affiche1Texture.loadFromFile(AFFICHE_1)) {
        throw;
    }
    sf::Sprite affiche1;
    affiche1.setTexture(affiche1Texture);

    sf::Texture affiche2Texture;
    if (!affiche2Texture.loadFromFile(AFFICHE_2)) {
        throw;
    }
    sf::Sprite affiche2;
    affiche2.setTexture(affiche2Texture);

    sf::Texture enigme2Texture;
    if (!enigme2Texture.loadFromFile(ENIGME_2)) {
        throw;
    }
    sf::Sprite enigme2;
    enigme2.setTexture(enigme2Texture);

    sf::Texture enigme1Texture;

    if (!enigme1Texture.loadFromFile(ENIGME_1)) {
        throw;
    }

    sf::Sprite enigme1;
    enigme1.setTexture(enigme1Texture);

    timer timer(80);
    pnj pnj1(PNJ_1, 750, 540);
    pnj pnj2(PNJ_2, 100, 540);
    pnj pnj3(PNJ_3, 445,530);
    pnj pnj4(PNJ_4, 445,140);

    messageBox message("");

    sf::Event event;

    player.currentPosition.setPosition(452, 604);
    player.move_up();
    player.update();

    background background(MAP, 0, 0);

    sf::Image details;
    details.loadFromFile(DETAILS);

    while (is_running) {
        bool displayenigme1 = false;
        bool displayenigme2 = false;
        bool displayaffiche1 = false;
        bool displayaffiche2 = false;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (!message.animationIsFinish()) {
            message.animate();
        }

        if (timer.isFinish()) {
            // Game over
        } else {
            timer.update();
        }

        bool animPlayer = true;

        // CHAISE 1

        if (pnj3.is_touched(player.currentPosition) && !pnj3IsTouched ) {
            message.update("Appuie sur J pour lire le contenus de la pancarte ");
            pnj3IsTouched = true;
        }
        if (pnj3.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayaffiche1 = true;
        }

        if (pnj4.is_touched(player.currentPosition) && !pnj4IsTouched ) {
            message.update("Appuie sur J pour lire le contenus de la pancarte ");
            pnj4IsTouched = true;
        }
        if (pnj4.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayaffiche2 = true;
        }


        if (pnj1.is_touched(player.currentPosition) && !pnj1IsTouched ) {
            message.update("Vous ? Vous m'avez l'air I D I O T , résolvez cette enigme simple");
            pnj1IsTouched = true;
        }

        if (pnj2.is_touched(player.currentPosition) && !pnj2IsTouched) {
            message.update("Excusez moi mais je dois vous tester jeune aventurier ");
            pnj2IsTouched = true;
        }

        if (pnj2.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayenigme2 = true;
        }

        if (pnj1.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayenigme1 = true;
        }

        if (!pnj1.is_touched(player.currentPosition)) {
            pnj1IsTouched = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            player.currentPosition.setPosition(452, 200);
            player.update();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
        {
            player.currentPosition.setPosition(452, 200);
            player.update();
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

        App.clear();
        App.draw(background);
        App.draw(timer);
        App.draw(message);
        App.draw(pnj1);
        App.draw(pnj2);
        App.draw(pnj3);
        App.draw(pnj4);
        App.draw(player);

        if (displayaffiche1)
            App.draw(affiche1);

        if (displayaffiche2)
            App.draw(affiche2);

        if (displayenigme2)
            App.draw(enigme2);

        if (displayenigme1)
            App.draw(enigme1);

        App.display();
    }

    return (-1);
}
