#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "player.h"

int main(){
    Player p;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

    window.setFramerateLimit(30);

    window.setPosition(sf::Vector2i(100,50));
    window.setTitle("Ping-Pong");

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
       }

        window.clear(sf::Color::Black);
        window.draw(p.raquete);
        window.display();
    }


    return 0;
}
