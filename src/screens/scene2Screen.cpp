#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene2Screen.h"
#include "../game/background.h"
#include "../ui/messageBox.h"
#include "../game/bed.h"

#define FULLSTEP 6

#define MAP "../assets/scene2.png"
#define DETAILS "../assets/scene2_details.png"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;

scene2Screen::scene2Screen(Player &player) : cScreen(player) {}

int scene2Screen::Run(sf::RenderWindow &App) {
    bed lit(530, 560);
    messageBox message("truc");

    sf::Event event;

    player.currentPosition.setPosition(530, 500);
    player.move_up();
    player.update();

    background background(MAP, 0, 0);

    sf::Image details;
    details.loadFromFile(DETAILS);

    while (is_running) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player.currentPosition.setPosition(sf::Mouse::getPosition().x - 490, sf::Mouse::getPosition().y - 200);
        }

        if (!message.animationIsFinish()) {
            message.animate();
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

        App.clear();
        App.draw(background);
        App.draw(message);
        App.draw(lit);
        App.draw(player);
        App.display();
    }

    return (-1);
}
