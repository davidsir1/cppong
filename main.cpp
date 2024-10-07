#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping-Pong");
    Player p;

    window.setPosition(sf::Vector2i(100,50));
    window.setFramerateLimit(60);

    sf::Clock clock;

    while(window.isOpen()){
        sf::Event event;
        sf::Time elapsed = clock.restart();

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        p.playerMove(window);
        p.PlayerLog();

        std::cout << "Resolução: " << window.getSize().x << 'x' << window.getSize().y << '\n';

        window.clear(sf::Color::Black);
        window.draw(p.player);
        window.display();
    }


    return 0;
}
