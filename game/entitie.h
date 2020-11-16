//
// Created by rached on 14/11/2020.
//

#ifndef GAME_ENTITIE_H
#define GAME_ENTITIE_H

#include <SFML/Graphics.hpp>
/*
 * entitie est la classe mère de toutes les entitées du jeu (porte, joueur, fond, PNJ etc.)
 * Elle hérite des comportements des classes sf::Drawable et sf::Transformable.
 *
 * https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Transformable.php
 * https://www.sfml-dev.org/documentation/2.0-fr/classsf_1_1Drawable.php
 *
 * Dans son constructeur, on demande le chemin vers le sprite et la position initiale de l'entitée.
 */
class entitie : public sf::Drawable, public sf::Transformable {
public:
    entitie(std::string spritePath, int x, int y);

    /*
     * Permet d'appliquer la méthode draw sur l'objet.
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /*
     * Renvoie true si un sprite touche l'objet, sinon, false.
     */
    bool is_touched(sf::Sprite obj);

protected:
    /*
     * Texture de l'entitée.
     */
    sf::Texture texture;

    /*
     * Sprite de l'entitée.
     */
    sf::Sprite sprite;

private:
    std::string spritePath;
};

#endif //GAME_ENTITIE_H
