#include "ball.h"

Ball::Ball(){
    ball.setSize(sf::Vector2f(20.f,20.f));
    ball.setPosition(sf::Vector2f(400.f,300.f));
    ball.setFillColor(sf::Color(sf::Color::Green));
}

Ball::~Ball(){}

void Ball::moveBall(sf::Window& w, sf::RectangleShape& player){

    ball.move(sf::Vector2f(speedX, speedY));

    sf::FloatRect ballBounds = ball.getGlobalBounds();
    sf::FloatRect playerBounds = player.getGlobalBounds();

    // Variáveis que pega o centro da tela
    float meioX = (w.getSize().x / 2.f);
    float meioY = (w.getSize().y / 2.f);

    // A bola não sai da tela
    if(ball.getPosition().y < 0){
        speedY = speed;
    }else if ((ball.getPosition().y + ball.getSize().y) > w.getSize().y){
        speedY = -(speed);
    }

    if(ballBounds.intersects(playerBounds)){
        speedX = speed;
    }
    if(ball.getPosition().x < 0){
        ball.setPosition(sf::Vector2f(meioX, meioY));
        speedX = speed;
    }
    if((ball.getPosition().x + ball.getSize().x) > w.getSize().x){
        ball.setPosition(sf::Vector2f(meioX, meioY));
        speedX = -(speed);
    }
}
