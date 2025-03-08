#include "player.h"

Player::Player(sf::Window& w, int p){
    player.setSize(sf::Vector2f(20.f, 120.f));
    player.setFillColor(sf::Color::White);

	if(p == 1){
		player.setPosition(sf::Vector2f(5.f, 5.f));
	}else if(p == 2){
		float x = w.getSize().x;
		player.setPosition(sf::Vector2f(x-25.f, 5.f));
	}
}

Player::~Player(){}

void Player::playerMove(sf::RectangleShape& player, sf::Window& window, sf::Keyboard::Key up, sf::Keyboard::Key down){

	if(sf::Keyboard::isKeyPressed(up)){
		speed -= accel;
	}else if(sf::Keyboard::isKeyPressed(down)){
		speed += accel;
	}
	else{
        // Quando a tecla deixa de ser pressionada, o jogador perde velocidade
		if(speed > 0){
			speed -= decel;
			if(speed < minSpeed) speed = 0;
		}else if(speed < 0){
			speed += decel;
			if(speed > minSpeed) speed = 0;
		}
	}

    //Aqui onde o jogador se move
    player.move(sf::Vector2f(0, speed));
    
    //limita o movimento do jogador na tela
    if(player.getPosition().y < 5){
        player.setPosition(player.getPosition().x, 5);
	}else if((player.getPosition().y + player.getSize().y) > window.getSize().y-5){
		player.setPosition(player.getPosition().x, ((window.getSize().y-5) - player.getSize().y));
	}
	
	if(speed > maxSpeed) speed = maxSpeed;
	if(speed < -maxSpeed) speed = -maxSpeed;
}
