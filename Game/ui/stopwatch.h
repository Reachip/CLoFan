//
// Created by rached on 11/11/2020.
//

#ifndef GAME_STOPWATCH_H
#define GAME_STOPWATCH_H

typedef struct {
    int seconds;
    int minutes;
} StopWatch;

StopWatch createStopWatch(int seconds, int minutes);
sf::Text stopWatchToText(StopWatch stopWatch);
sf::Text decreaseSecond(StopWatch *stopWatch);

#endif //GAME_STOPWATCH_H
