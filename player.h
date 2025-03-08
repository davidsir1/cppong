#ifndef PLAYER_H 
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Player{
    public:
		Player(sf::Window& w, int p);
        ~Player();

		sf::RectangleShape player;
		void playerMove(sf::RectangleShape& player, sf::Window& window, sf::Keyboard::Key up, sf::Keyboard::Key down);

    private:
		float speed = 0;
		const float accel = 0.6f; // aceleração
		const float decel = 0.9f; // desaceleração
		const float maxSpeed = 15.f; // Velocidade máxima
		const float minSpeed = 0.1f; // Velocidade mínima parar o movimento
};


#endif // PLAYER_H
