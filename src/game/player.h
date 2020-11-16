//
// Created by rached on 10/11/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "entitie.h"

/*
 * Classe qui représente le/les joueur(s) du jeu.
 * Elle est souvent passé par références aux différents screens du jeu afin
 * d'effectuer des modifications sur l'objet tout en le transferant.
 */
class Player :  public entitie {
private:
    std::string name;
    sf::Clock clock;
    /*
     * Vecteur qui permet de jouer l'animation en fonction de la touche pressé.
     */
    sf::Vector2i animation;
    /*
     * Change la texture du sprite afin de jouer une animation.
     */
    void _addSprite(sf::IntRect);

public:
    Player(std::string name);
    /*
     * Position courante du personnage.
     * Techniquement parlant, il s'agit du sprite courant de l'objet,
     * qui change en fonction des animations.
     */
    sf::Sprite currentPosition;

    /*
     * Voir entite.h pour en savoir plus.
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /*
     * Fais bouger le joueur à gauche, à droite, en haut ou en bas avec un animation.
     */
    void move_on_left();
    void move_on_right();
    void move_up();
    void move_down();

    /*
     * Met à jour le sprite pour produire l'animation.
     */
    void update();

    /*
     * Retourne une copie du sprite du joueur.
     */
    sf::Sprite getSprite();
};

#endif //GAME_PLAYER_H
