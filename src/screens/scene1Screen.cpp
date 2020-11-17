#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene1Screen.h"
#include "../game/background.h"
#include "../game/entities.h"

#include "../game/table.h"
#include "../ui/messageBox.h"
#include "../game/bed.h"
#include"../game/pnj.h"
#include "../game/door.h"
#include "../game/chair.h"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;


scene1Screen::scene1Screen(Player &player) : cScreen(player) {}


int scene1Screen::Run(sf::RenderWindow &App) {

    bool tableisTouched = false;
    bool chaiseisTouched= false;
    bool litisTouched= false;
    bool porteisTouched= false;

    chair chaise(490,516);
    bed lit(530, 570);
    door porte(425,30);
    table table(380,516);

    messageBox message("Bon reveil aventurier ");


    sf::Event event;

    background background("../assets/scene1.png", 0, 0);

    sf::Image details;
    details.loadFromFile("../assets/scene1_details.png");

    player.currentPosition.setPosition(500, 570);
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



        if (chaise.is_touched(player.currentPosition) && !chaiseisTouched) {
            message.update("Pas eu le temps de coder ça.");
            chaiseisTouched = true;
        }
        if (table.is_touched(player.currentPosition) && !tableisTouched) {
            message.update("On t'a jamais dis de pas mettre tes pieds sur la table?.");
            tableisTouched = true;
        }
        if (porte.is_touched(player.currentPosition) && !porteisTouched) {
            message.update("Appuie sur J pour continuer");
            porteisTouched = true;
        }

        if (lit.is_touched(player.currentPosition) && !litisTouched) {
            message.update("Rompiche");
            litisTouched = true;


        }

        if(lit.is_touched(player.currentPosition)){
            player.sleep();

            }
        if (porte.is_touched(player.currentPosition) && (sf::Keyboard::isKeyPressed(sf::Keyboard::J)))
        {
            return 2;
        }

        if (!table.is_touched(player.currentPosition)&&!porte.is_touched(player.currentPosition) && !chaise.is_touched(player.currentPosition) && !lit.is_touched(player.currentPosition)) {
        porteisTouched = false;
        chaiseisTouched = false;
        litisTouched = false;
        tableisTouched = false;
        message.clear();
        }


        App.clear();
        App.draw(background);
        App.draw(message);
        App.draw(lit);
        App.draw(chaise);
        App.draw(porte);
        App.draw(table);
        App.draw(player);
        App.display();
    }


    return (-1);
}

