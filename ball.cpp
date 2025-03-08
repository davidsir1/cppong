#include "ball.h"

Ball::Ball(){
    ball.setSize(sf::Vector2f(20.f,20.f));
    ball.setFillColor(sf::Color(sf::Color::Green));
}

Ball::~Ball(){}

void Ball::displayBall(sf::Window& w){
    ball.setPosition(sf::Vector2f(w.getSize().x/2.f, w.getSize().y/2.f));
}

void Ball::moveBall(sf::Window& w, sf::RectangleShape& p1, sf::RectangleShape& p2, sf::Sprite& s1, sf::Sprite& s2){

    ball.move(sf::Vector2f(speedX, speedY));

    sf::FloatRect ballBounds = ball.getGlobalBounds();
    sf::FloatRect p1Bounds = p1.getGlobalBounds();
	sf::FloatRect p2Bounds = p2.getGlobalBounds();
	sf::IntRect rectP1 = s1.getTextureRect();
	sf::IntRect rectP2 = s2.getTextureRect();

    // Variáveis que pega o centro da tela
    float meioX = (w.getSize().x / 2.f);
    float meioY = (w.getSize().y / 2.f);

    // A bola não sai da tela
    if(ball.getPosition().y < 0){
        speedY = speed;
    }else if ((ball.getPosition().y + ball.getSize().y) > w.getSize().y){
        speedY = -(speed);
    }

	// A bola ricocheteia no jogador e muda de direção
	// Verifica a colisão da bola com player 1
    if(ballBounds.intersects(p1Bounds)){
        speedX += speed;
    }
	// Verifica a colisão da bola com player 2
	if(ballBounds.intersects(p2Bounds)){
		speedX = -speed;
	}

	// A bola volta para o meio após ultrapassar a tela
	// Tela esquerda
    if(ball.getPosition().x < 0){
		gs.updateScore(s2, rectP2);
        ball.setPosition(sf::Vector2f(meioX, meioY));
        speedX = speed;
    }
	// Tela Direita
	if((ball.getPosition().x + ball.getSize().x) > w.getSize().x){
		gs.updateScore(s1, rectP1);
        speedX = -(speed);
        ball.setPosition(sf::Vector2f(meioX, meioY));
	}
}
