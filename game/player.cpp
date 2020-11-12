//
// Created by rached on 10/11/2020.
//

#include "player.h"

#define STEP 6

Player::Player(std::string name, std::string spritePath) {
    this->name = name;

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
    _addSprite(sf::IntRect(0, 0, 64, 64));
}

void Player::move_down() {
    this->currentPosition.move(0, STEP);
    _addSprite(sf::IntRect(0, 64 * 2, 64, 64));
}

void Player::move_on_left() {
    this->currentPosition.move(-STEP, 0);
    _addSprite(sf::IntRect(0, 64 * 1, 64, 64));
}

void Player::move_on_right() {
    this->currentPosition.move(STEP, 0);
    _addSprite(sf::IntRect(0, 64 * 3, 64, 64));
}