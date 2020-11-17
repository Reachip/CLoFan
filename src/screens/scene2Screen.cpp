#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene2Screen.h"
#include "../game/entities.h"
#include "../ui/messageBox.h"
#include "iostream"
#define FULLSTEP 6

#define MAP "../assets/scene2.png"
#define DETAILS "../assets/scene2_details.png"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;
using namespace std;

scene2Screen::scene2Screen(Player &player) : cScreen(player) {}

int scene2Screen::Run(sf::RenderWindow &App) {
    bool chairIsTouched = false;
    bool bedIsTouched = false;
    bool keyIsFound = false;

    timer timer(80);
    bed bed(530, 560);
    chair chair(45, 300);

    messageBox message("");

    sf::Event event;

    player.currentPosition.setPosition(452, 604);
    player.move_up();
    player.update();

    background background(MAP, 0, 0);

    sf::Image details;
    details.loadFromFile(DETAILS);

    while (is_running) {
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (!message.animationIsFinish()) {
            message.animate();
        }

        if (timer.isFinish()) {
            // Game over
        }

        else {
            timer.update();
        }

        bool animPlayer = true;

        if (chair.is_touched(player.currentPosition) && !chairIsTouched && !keyIsFound) {
            message.update("Vous trouvez une cle sous la chaise. Appuyez sur S pour saisir cette cle. ");
            chairIsTouched = true;
        }

        if (chair.is_touched(player.currentPosition) && !chairIsTouched && keyIsFound) {
            message.update("Rien par ici, sauf une toile d'arraignee sous la chaise.\nVous aviez ramasse une cle par ici non ?");
            chairIsTouched = true;
        }

        if (chair.is_touched(player.currentPosition) && !keyIsFound && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            message.update("Vous venez de vous munir de la cle.");
            timer.restart();
            keyIsFound = true;
        }

        if (!chair.is_touched(player.currentPosition)) {
            chairIsTouched = false;
        }

        if (bed.is_touched(player.currentPosition) && !bedIsTouched) {
            message.update("Dormir ou coder ?");
            bedIsTouched = true;
        }

        if (!bed.is_touched(player.currentPosition)) {
            bedIsTouched = false;
        }

        if (!bed.is_touched(player.currentPosition) && !chair.is_touched(player.currentPosition)) {
            message.clear();
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
        App.draw(bed);
        App.draw(chair);
        App.draw(player);
        App.display();
    }

    return (-1);
}
