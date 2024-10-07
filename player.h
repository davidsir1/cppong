#ifndef PLAYER_H 
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Player{
    public:
        Player();
        ~Player();

    sf::RectangleShape player;			
	void PlayerLog();
	void playerMove(sf::Window& window);

    private:
    float speed = 0;
    const float accel = 0.5f; // aceleração
    const float decel = 0.8f; // desaceleração
	const float maxSpeed = 15.f; // Velocidade máxima
    const float minSpeed = 0.1f; // Velocidade mínima parar o movimento
};


#endif // PLAYER_H
