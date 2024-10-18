#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#include "player.h"
#include "ball.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping-Pong");
    Player p;
    Ball b;

    window.setPosition(sf::Vector2i(100,50));
    window.setFramerateLimit(60);

    sf::Clock clock;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        /*std::system("clear");*/
        // MOvimento do jogador
        p.playerMove(window);

        // Movimento da bola
        b.moveBall(window, p.player);

        window.clear(sf::Color::Black);
        window.draw(p.player);
        window.draw(b.ball);
        window.display();
    }


    return 0;
}
