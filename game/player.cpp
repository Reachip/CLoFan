//
// Created by rached on 10/11/2020.
//

#include "player.h"

#define STEP 6

Player::Player(std::string name, std::string spritePath) {
    this->name = name;
    this->animation = sf::Vector2i(1, 1);
    this->clock = sf::Clock();

    sf::Texture texture;

    if (!texture.loadFromFile(spritePath))
        throw;

    this->texture = texture;
}

void Player::_addSprite(sf::IntRect spritePosition) {
    this->currentPosition.setTexture(this->texture);
    this->currentPosition.setTextureRect(spritePosition);
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

void Player::update() {
    // Affiche une nouvelle texture toutes les 50 millisecondes.
    if (clock.getElapsedTime().asMilliseconds() >= 100) {
        if (this->animation.x * 24 > (5 * 24))
            this->animation.x = 0;

        this->animation.x += 1;
        _addSprite(sf::IntRect(animation.x * 24, animation.y * 32, 24, 32));
        clock.restart();
    }
}