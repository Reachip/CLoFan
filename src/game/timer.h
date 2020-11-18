//
// Created by rached on 17/11/2020.
//

#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <string>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class timer : public sf::Drawable, public sf::Transformable {
public:
    timer(float _time);

    bool isFinish();

    void update();

    void restart();

    void pause();

    void unpause();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    int time;
    bool is_paused;
};


#endif //GAME_TIMER_H
