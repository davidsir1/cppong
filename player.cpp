#include "player.h"

Player::Player(){
    raquete.setSize(sf::Vector2f(20.f, 50.f));
    raquete.setFillColor(sf::Color::Cyan);
    raquete.setOrigin(sf::Vector2f(0.f,0.f));
}

Player::~Player(){
}
