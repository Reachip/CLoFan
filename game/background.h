//
// Created by rached on 14/11/2020.
//

#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H

#include "entitie.h"

class background : public entitie {
public:
    background(std::string spritePath);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //GAME_BACKGROUND_H
