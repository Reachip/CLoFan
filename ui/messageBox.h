//
// Created by rached on 15/11/2020.
//

#ifndef GAME_MESSAGEBOX_H
#define GAME_MESSAGEBOX_H

#include <SFML/Graphics.hpp>

class messageBox : public sf::Drawable, sf::Transformable {
public:
    messageBox(std::string text);
    void animate();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    bool animationIsFinish();
    void update(std::string newText);
    void clear();

private:
    sf::Text message;
    sf::Font font;
    sf::Clock clock;
};


#endif //GAME_MESSAGEBOX_H
