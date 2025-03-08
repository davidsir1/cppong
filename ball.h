#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "gamescore.h"

class Ball {
public:
	Ball();
	~Ball();
    sf::RectangleShape ball;
	GameScore gs;

    void moveBall(sf::Window& w, sf::RectangleShape& p1, sf::RectangleShape& p2, sf::Sprite& s1, sf::Sprite& s2);
	void displayBall(sf::Window& w);
private:
    const float speed = 10.f;
    float speedX = speed, speedY = speed;
};

#endif // !BALL_H
