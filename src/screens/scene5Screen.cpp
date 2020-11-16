#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene5Screen.h"
#include "../game/background.h"

#define FULLSTEP 6

#define WIDTH 24
#define HEIGHT 32

using namespace sf;


scene5Screen::scene5Screen(Player &player) : cScreen(player) {}



int scene5Screen::Run(sf::RenderWindow &App)
{
    bool collision = false;
    sf::Event event;

    player.currentPosition.setPosition(270, 350);
    player.move_up();
    player.update();

    background background("../assets/scene2.png", 0, 0);

    sf::Image details;
    details.loadFromFile("../assets/scene2_details.png");

    while (is_running)
    {
        bool animPlayer = true;

        while (App.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                is_running = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            for(int i=0; i<FULLSTEP; i++)
            {
                handleUp(details);
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            for(int i=0; i<FULLSTEP; i++)
            {
                handleDown(details);
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            for(int i=0; i<FULLSTEP; i++)
            {
                handleLeft(details);
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            for(int i=0; i<FULLSTEP; i++)
            {
                handleRight(details);
            }
        }

        else
            animPlayer = false;

        if(animPlayer)
            player.update();


        App.clear();
        App.draw(background);
        App.draw(player);
        App.display();
    }



    return (-1);
}
