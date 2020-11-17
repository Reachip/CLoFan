//
// Created by rached on 10/11/2020.
//

#include "player.h"
#include "entitie.h"

#define STEP 1
#define WIDTH 24
#define HEIGHT 32
#define PLAYER_SPRIT_PATH "../assets/fumiko.png"


Player::Player(std::string name) : entitie(PLAYER_SPRIT_PATH, 0, 0) {
    this->name = name;
    this->animation = sf::Vector2i(1, 1);
    this->clock = sf::Clock();
}

void Player::_addSprite(sf::IntRect spritePosition) {
    this->currentPosition.setTexture(this->texture);
    this->currentPosition.setTextureRect(spritePosition);
}

sf::Sprite Player::getSprite() {
    return currentPosition;
}

void Player::move_up() {
    this->currentPosition.move(0, -STEP);
    this->animation.y = 4;
}

void Player::move_down() {
    this->currentPosition.move(0, STEP);
    this->animation.y = 2;
}

void Player::move_on_left() {
    this->currentPosition.move(-STEP, 0);
    this->animation.y = 3;
}

void Player::move_on_right() {
    this->currentPosition.move(STEP, 0);
    this->animation.y = 1;
}

void Player::sleep(){
    this->animation.y = 1;
if (clock.getElapsedTime().asMilliseconds() >= 1000) {
        if (this->animation.x * WIDTH > (2 * WIDTH))
            this->animation.x = 0;

        this->animation.x += 1;
        _addSprite(sf::IntRect(animation.x * WIDTH + 5*WIDTH, animation.y * HEIGHT, WIDTH, HEIGHT));
        clock.restart();
    }
}

void Player::update() {
    // Affiche une nouvelle texture toutes les 50 millisecondes.
    if (clock.getElapsedTime().asMilliseconds() >= 100) {
        if (this->animation.x * WIDTH > (4 * WIDTH))
            this->animation.x = 0;

        this->animation.x += 1;
        _addSprite(sf::IntRect(animation.x * WIDTH, animation.y * 32, WIDTH, HEIGHT));
        clock.restart();
    }
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(currentPosition, states);
}
