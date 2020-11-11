//
// Created by rached on 11/11/2020.
//

#include <string>
#include "SFML/Graphics.hpp"
#include "stopwatch.h"

#define FONT_PATH "../assets/LiberationSerif-Regular.ttf"

StopWatch createStopWatch(int seconds, int minutes) {
    if (!(seconds < 60 && seconds >= 0) || !(minutes > 0 && minutes < 60))
        throw;

    return StopWatch {seconds, minutes};
}

sf::Text stopWatchToText(StopWatch stopWatch) {
    sf::Text stopWatchText;
    stopWatchText.setString(std::to_string(stopWatch.minutes) + " : " + std::to_string(stopWatch.seconds));
    stopWatchText.setCharacterSize(24);
    stopWatchText.setColor(sf::Color::White);
    stopWatchText.setPosition(200, 200);
    stopWatchText.setStyle(sf::Text::Bold);

    return stopWatchText;
}

sf::Text decreaseSecond(StopWatch *stopWatch) {
    stopWatch->seconds -= 1;
    return stopWatchToText(*stopWatch);
}


