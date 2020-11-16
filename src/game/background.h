//
// Created by rached on 14/11/2020.
//

#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H

#include "entitie.h"

/*
 * La classe background sert à appliquer une image de fond à une scène.
 * Son constructeur prend en paramètre le chemin vers l'image de fond
 * qui doit correspondre et la même hauteur et largeur que la fenetre SFML.
 */
class background : public entitie {
public:
    background(std::string spritePath, int x, int y);
    sf::Vector2u getSize();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //GAME_BACKGROUND_H
