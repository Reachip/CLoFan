//
// Created by rached on 16/11/2020.
//

#ifndef GAME_PNJ_H
#define GAME_PNJ_H

#include "entitie.h"

/*
 * Cette classe représente un PNJ.
 * Le joueur, dans le contexte du jeu, sera capable
 * de l'approcher pour lui afin qu'il lui
 * fournisse dess indices.
 *
 * Le constructeur réclame le chemin vers le sprite du PNJ ainsi que sa position initiale.
 *
 * Cette classe est en fait une copie conforme de sa classe mère car elle n'implémente
 * aucune autre fonctionnalitée, bien qu'elle ait été créee pour faciliter la compréhension du code.
 */
class pnj : public entitie {
    public:
    pnj(std::string spritePath, int x, int y);
};


#endif //GAME_PNJ_H
