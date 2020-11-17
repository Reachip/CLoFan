//
// Created by rached on 14/11/2020.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include <SFML/Graphics.hpp>
#include "entitie.h"

/*
 * La classe door représente une porte dans le jeu.
 * Son constructeur réclame la position initiale
 * en x et en y de l'objet.
 */
class door : public entitie {
public:
    door(int x, int y);

    /*
     * La méthode open permet de changer le sprite d'une
     * porte fermée par un sprite d'une porte ouverte.
     */
    void open();

    /*
    * La méthode close permet de changer le sprite d'une
    * porte ouverte par un sprite d'une porte fermée.
    */
    void close();

private:
    sf::Texture openedDoor;
    sf::Texture closedDoor;

};


#endif //GAME_DOOR_H
