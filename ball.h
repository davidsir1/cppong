#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Ball {
public:
	Ball();
	~Ball();
    sf::RectangleShape ball;

    void moveBall(sf::Window& w, sf::RectangleShape& player);
private:
    const float speed = 10.f;
    float speedX = speed, speedY = speed;
};

#endif // !BALL_H
