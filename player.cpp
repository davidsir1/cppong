#include "player.h"

Player::Player(){
    player.setSize(sf::Vector2f(30.f, 150.f));
    player.setFillColor(sf::Color::White);
    player.setOrigin(sf::Vector2f(0,0));
    player.setPosition(sf::Vector2f(5,0));
}

Player::~Player(){}

void Player::playerMove(sf::Window& window){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        speed -= accel;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        speed += accel;
    }else{
        // Quando a tecla deixa de ser pressionada, o jogador perde velocidade
        if(speed > 0){
            speed -= decel;
            if(speed < minSpeed) speed = 0;
        }else if(speed < 0){
            speed += decel;
            if(speed > minSpeed) speed = 0;
        }
    }

    // Aqui onde o jogador se move
    player.move(sf::Vector2f(0, speed));
    
    // limita o movimento do jogador na tela
    if(player.getPosition().y < 0){
        player.setPosition(player.getPosition().x, 0);
    }else if((player.getPosition().y + player.getSize().y) > window.getSize().y){
        player.setPosition(player.getPosition().x, (window.getSize().y - player.getSize().y));
    }

    if(speed > maxSpeed) speed = maxSpeed;
    if(speed < -maxSpeed) speed = -maxSpeed;

}

void Player::PlayerLog(){
	std::cout << "Velocidade: " << speed << '\n';
    std::cout << "Posição: " << player.getPosition().x << ' ' << player.getPosition().y << '\n';
}
