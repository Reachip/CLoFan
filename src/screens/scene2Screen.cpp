#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene2Screen.h"
#include "../game/entities.h"
#include "../ui/messageBox.h"
#include "iostream"

#define FULLSTEP 6

#define MAP "../assets/scene2.png"
#define DETAILS "../assets/scene2_details.png"
#define PARCHEMIN_CHAISE_2 "../assets/parchemin_chaise.png"
#define PARCHEMIN_STATUE_1 "../assets/parchemin_statue.png"
#define PNJ "../assets/statue1.png"
#define WIDTH 24
#define HEIGHT 32

using namespace sf;
using namespace std;

scene2Screen::scene2Screen(Player &player, int screenPosition) : baseScreen(player, screenPosition) {}

int scene2Screen::Run(sf::RenderWindow &App) {
    saveProgression();
    sf::Clock clock;

    bool chairIsTouched1 = false;
    bool chairIsTouched2 = false;
    bool keyIsFound = false;
    bool doorIsTouched = false;
    bool pnj1IsTouched = false;
    bool pnj2IsTouched = false;
    bool levelUnlocked = false;

    bool pauseTimer = false;


    sf::Texture parcheminChaise2Texture;
    if (!parcheminChaise2Texture.loadFromFile(PARCHEMIN_CHAISE_2)) {
        throw;
    }
    sf::Sprite parcheminChaise2;
    parcheminChaise2.setTexture(parcheminChaise2Texture);

    sf::Texture parcheminStatue1Texture;

    if (!parcheminStatue1Texture.loadFromFile(PARCHEMIN_STATUE_1)) {
        throw;
    }

    sf::Sprite parcheminStatue1;
    parcheminStatue1.setTexture(parcheminStatue1Texture);

    timer timer(80);
    pnj pnj1(PNJ, 98, 300);
    pnj pnj2(PNJ, 792, 300);
    chair chair(45, 350);
    library library1(320, 70);
    library library2(350, 70);

    door door(425, 30);
    door.close();

    library library3(380, 70);
    class chair chair2(320, 100);

    messageBox message("");

    sf::Event event;

    player.currentPosition.setPosition(452, 604);
    player.move_up();
    player.update();

    background background(MAP, 0, 0);

    sf::Image details;
    details.loadFromFile(DETAILS);

    while (is_running) {
        bool displayParcheminStatue1 = false;
        bool displayParcheminChaise2 = false;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (!message.animationIsFinish()) {
            message.animate();
        }

        if (timer.isFinish()) {
            return 5;
        } else {
            timer.update();
        }

        bool animPlayer = true;

        // CHAISE 1
        if (chair.is_touched(player.currentPosition) && !chairIsTouched1 && !keyIsFound) {
            message.update("Vous trouvez une cle sous la chaise. Appuyez sur J pour saisir cette cle. ");
            chairIsTouched1 = true;
        }

        if (chair.is_touched(player.currentPosition) && !chairIsTouched1 && keyIsFound) {
            message.update(
                    "Rien par ici, sauf une toile d'arraignee sous la chaise.\nVous aviez ramasse une cle par ici non ?");
            chairIsTouched1 = true;
        }

        if (chair.is_touched(player.currentPosition) && !keyIsFound && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            message.update("Vous venez de vous munir de la cle.");
            timer.restart(35);
            chairIsTouched1 = true;
            keyIsFound = true;
        }

        if (!chair.is_touched(player.currentPosition)) {
            chairIsTouched1 = false;
        }


        // CHAISE 2
        if (chair2.is_touched(player.currentPosition) && !chairIsTouched2) {
            message.update("Vous venez de trouver un parchemin. Maintenez la touche J pour l'ouvrir.");
            chairIsTouched2 = true;
        }

        if (chair2.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayParcheminChaise2 = true;
        }

        if (!chair2.is_touched(player.currentPosition)) {
            chairIsTouched2 = false;
        }

        // PNJ 1
        if (pnj1.is_touched(player.currentPosition) && !pnj1IsTouched) {
            message.update("Vous venez de trouver un parchemin. Maintenez la touche J pour l'ouvrir.");
            pnj1IsTouched = true;
        }

        if (pnj1.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            displayParcheminStatue1 = true;
            pnj1IsTouched = true;
        }


        // PORTE
        if (door.is_touched(player.currentPosition) && !doorIsTouched) {
            message.update("Appuyer sur la touche J pour essayer d'ouvrir la porte");
            doorIsTouched = true;
        }

        if (door.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && keyIsFound) {
            message.update("Entrez !");
            levelUnlocked = true;
            doorIsTouched = true;
        }

        if (door.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !keyIsFound) {
            message.update("Impossible d'ouvrir la porte ...");
            doorIsTouched = true;
        }

        if (!door.is_touched(player.currentPosition)) {
            doorIsTouched = false;
        }

        if (!door.is_touched(player.currentPosition) && !pnj1.is_touched(player.currentPosition) &&
            !chair2.is_touched(player.currentPosition) && !chair.is_touched(player.currentPosition)
                )
            message.clear();

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
        App.draw(chair);
        App.draw(pnj1);
        App.draw(pnj2);
        App.draw(chair2);
        App.draw(library1);
        App.draw(library2);
        App.draw(library3);


        if (displayParcheminChaise2)
            App.draw(parcheminChaise2);

        if (displayParcheminStatue1)
            App.draw(parcheminStatue1);

        if (levelUnlocked) {
            door.open();

            if (clock.getElapsedTime().asSeconds() >= 1) {
                return 3;
            }
        }

        App.draw(door);
        App.draw(player);
        App.display();


//Prise en charge des cheats code==============================================================================================================
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)) {
            return 3;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::SemiColon)) {
            return 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) {
            if (!pauseTimer) {
                timer.pause();
            } else {
                timer.unpause();
            }
        }
//Prise en charge des cheats code==============================================================================================================

    }

    return (-1);
}
