//
// Created by rached on 15/11/2020.
//

#ifndef GAME_MESSAGEBOX_H
#define GAME_MESSAGEBOX_H

#include <SFML/Graphics.hpp>

/*
 * Messagebox est l'objet qui permet d'afficher du texte à l'écran de façon animée.
 * L'objet peut être mis ç jour afin de changer ou vider son contenu.
 */
class messageBox : public sf::Drawable, sf::Transformable {
public:
    messageBox(std::string text);
    /*
     * Méthode qui déroule progressivement le texte.
     * Elle est conventionnellement appelée quand animationIsFinish
     * vaut true.
     */
    void animate();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /*
     * Vérifie si l'animation de déroulement du texte est terminée.
     */
    bool animationIsFinish();

    /*
     * Change le texte de la messageBox et la remet à son état initial.
     */
    void update(std::string newText);

    /*
     * Vide le contenu de la messageBox.
     */
    void clear();

private:
    sf::Text message;
    sf::Font font;
    sf::Clock clock;
};


#endif //GAME_MESSAGEBOX_H
