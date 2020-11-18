#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene4Screen.h"
#include "../game/background.h"
#include "../game/entities.h"

#include "../ui/messageBox.h"
#include "../game/bed.h"
#include"../game/pnj.h"

#define WIDTH 24
#define HEIGHT 32

using namespace sf;


scene4Screen::scene4Screen(Player &player, int screenPosition) : baseScreen(player, screenPosition) {}

int scene4Screen::Run(sf::RenderWindow &App) {
    saveProgression();

//Initialisation des variables propres � la sc�ne================================================================================================================================
    bool statueIsTouched = false;
    bool biblioIsTouched = false;
    bool litIsTouched = false;
    bool chaiseIsTouched = false;
    bool oldManIsTouched = false;
    bool porteIsTouched = false;

    bool pauseTimer = false;

    std::string taskList = "NULL";
//Initialisation des variables propres � la sc�ne================================================================================================================================


//Initialisation des entit�s=====================================================================================================================================================
    pnj statue("../assets/statue1.png", 445, 550);
    bed lit(174, 280);
    messageBox message("Bienvenue dans la scene 4");
    library biblio(30, 185);
    chair chaise(30, 530);
    door porte(425, 32);
    porte.close();
    pnj oldMan("../assets/old_man.png", 530, 530);
    timer countdown(6000);

    sf::Clock clock;
    clock.restart();
//Initialisation des entit�s=====================================================================================================================================================

    sf::Event event;

    background background("../assets/scene4.png", 0, 0);

    sf::Image details;
    details.loadFromFile("../assets/scene4_details.png");

    player.currentPosition.setPosition(450, 606);
    player.move_up();
    player.update();

    while (is_running) {

        int nbTouch = 0;


        if (!message.animationIsFinish()) {
            message.animate();
        }
//Prise en charge des cheats code==============================================================================================================

//CHEAT Placement du joueur à la position de la souris======================================================================================
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player.currentPosition.setPosition(sf::Mouse::getPosition().x - 490, sf::Mouse::getPosition().y - 200);
        }*/
//CHEAT Placement du joueur à la position de la souris======================================================================================

        bool animPlayer = true;

//Prise en charge de la fermeture de la console==================================================================================================================================
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }
//Prise en charge de la fermeture de la console==================================================================================================================================



//Prise en charge du retour � l'�cran titre======================================================================================================================================
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;
//Prise en charge du retour � l'�cran titre======================================================================================================================================




//Prise en charge du d�placement du joueur=======================================================================================================================================
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
//Prise en charge du d�placement du joueur=======================================================================================================================================



//Liste des différentes tâches à réaliser========================================================================================================================================
        if (statue.is_touched(player.currentPosition) && !statueIsTouched) {

            if (taskList == "NULL") {
                message.update("Le temps est au repos, vivez une journee normale.");
                taskList = "S";
            }

            if (taskList == "S") {
                message.update("Le temps est au repos, vivez une journee normale.");
            }

            if (taskList == "SB") {
                message.update("Prendre le temps de s'instruire est capital.");
            }

            if (taskList == "SBL") {
                message.update("Prenons une pause, trouvons un endroit pour s'asseoir.");
            }

            if (taskList == "SBLT") {
                message.update("Comment faisiez-vous pour ramasser un objet avant?");
                taskList = "SBLTh";
            }

            if (taskList == "SBLTP") {
                message.update("Ce vieux monsieur a l'air dans une situation plus que misereuse.");
                //taskList="SBLTh";
            }

            if (taskList == "SBLTPC") {
                message.update("Une clef, a quoi cela peut bien servir?");
                //taskList="SBLTh";
            }


            statueIsTouched = true;
        }


        if (taskList == 'S') {
            if (lit.is_touched(player.currentPosition) && !litIsTouched) {
                message.update("Vous dormez longtemps et le temps passe");
                countdown.restart(70 - clock.getElapsedTime().asSeconds());
                taskList = "SB";
                litIsTouched = true;
            }
        }

        if (taskList == "SB") {
            if (biblio.is_touched(player.currentPosition) && !biblioIsTouched) {
                message.update("Le savoir est la plus grande des armes. Vous lisez pendant un moment.");
                countdown.restart(60 - clock.getElapsedTime().asSeconds());
                biblioIsTouched = true;
                taskList = "SBL";
            }
        }

        if (taskList == "SBL") {
            if (chaise.is_touched(player.currentPosition) && !chaiseIsTouched) {
                message.update("Quelque chose brille sous la chaise.");
                chaiseIsTouched = true;
                taskList = "SBLT";
            }
        }


        if (taskList == "SBLT") {
            if (chaise.is_touched(player.currentPosition) && !chaiseIsTouched) {
                message.update("Quelque chose brille sous la chaise.");
                chaiseIsTouched = true;
            }

            if (chaise.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
                message.update("Oh, une piece, c'est votre jour de chance.");
                taskList = "SBLTP";
            }
        }

        if (taskList == "SBLTh") {
            if (chaise.is_touched(player.currentPosition) && !chaiseIsTouched) {
                message.update("Quelque chose brille sous la chaise. Appuyez sur J pour le ramasser.");
                chaiseIsTouched = true;
            }

            if (chaise.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
                message.update("Oh, une piece, c'est votre jour de chance.");
                taskList = "SBLTP";
            }
        }

        if (taskList == "SBLTP") {
            if (oldMan.is_touched(player.currentPosition) && !oldManIsTouched) {
                oldManIsTouched = true;
                message.update(" \"Oh c'est une jolie piece, je vous l'echange contre cette clef que j'ai trouve.\" ");
            }

            if (oldMan.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
                message.update("Vous avez obtenu une clef.");
                taskList = "SBLTPC";
            }
        }

        if (taskList == "SBLTPC") {
            if (porte.is_touched(player.currentPosition) && !porteIsTouched) {
                porteIsTouched = true;
                message.update("Tenter d'ouvrir la porte?");
            }

            if (porte.is_touched(player.currentPosition) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
                porte.open();
                App.draw(porte);
                App.draw(player);
                App.display();
                sleep(milliseconds(500));
                return 4;
            }
        }
//Liste des différentes tâches à réaliser========================================================================================================================================


//Animation du personnage qui dort lorqu'il touche le lit ===========================================================================================================================================
        if (lit.is_touched(player.currentPosition)) {
            player.sleep();
        }
//Animation du personnage qui dort lorqu'il touche le lit ===========================================================================================================================================


        if (!statue.is_touched(player.currentPosition) && !biblio.is_touched(player.currentPosition) &&
            !lit.is_touched(player.currentPosition) && !chaise.is_touched(player.currentPosition) &&
            !oldMan.is_touched(player.currentPosition) && !porte.is_touched(player.currentPosition)) {
            statueIsTouched = false;
            biblioIsTouched = false;
            litIsTouched = false;
            chaiseIsTouched = false;
            oldManIsTouched = false;
            porteIsTouched = false;
            message.clear();
        }

        countdown.update();

        if (countdown.isFinish()) {
            return 5;
        }


        App.clear();
        App.draw(background);
        App.draw(message);
        App.draw(countdown);
        App.draw(lit);
        App.draw(biblio);
        App.draw(statue);
        App.draw(chaise);
        App.draw(porte);
        App.draw(oldMan);
        App.draw(player);
        App.display();



//Prise en charge des cheats code==============================================================================================================
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)) {
            return 4;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::SemiColon)) {
            return 2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) {
            if (!pauseTimer) {
                countdown.pause();
            } else {
                countdown.unpause();
            }
        }
//Prise en charge des cheats code==============================================================================================================


    }


    return (-1);
}
