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
    this->move_up();
}

void Player::_addSprite(sf::IntRect spritePosition) {
    this->currentPosition.setTexture(this->texture);
    this->currentPosition.setTextureRect(spritePosition);
}

void Player::move_up() {
    _addSprite(sf::IntRect(0, 0, 64, 64));
    this->currentPosition.move(0, -STEP);
}

void Player::move_down() {
    _addSprite(sf::IntRect(0, 64 * 2, 64, 64));
    this->currentPosition.move(0, STEP);
}

void Player::move_on_left() {
    _addSprite(sf::IntRect(0, 64 * 1, 64, 64));
    this->currentPosition.move(-STEP, 0);
}

void Player::move_on_right() {
    _addSprite(sf::IntRect(0, 64 * 3, 64, 64));
    this->currentPosition.move(STEP, 0);
}

void Player::update(sf::RenderWindow &window) {
    window.draw(this->currentPosition);
}