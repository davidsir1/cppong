#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#include "player.h"
#include "ball.h"
#include "gamescore.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping-Pong");
	
	window.setPosition(sf::Vector2i(100,50));
    window.setFramerateLimit(60);
	sf::Clock clock;
	bool gameover = false;

	Player p1(window, 1);
	Player p2(window, 2);
    Ball b;
    GameScore gs;

	// Display
	b.displayBall(window);
	gs.displayScore(window);

	// Texto de Vitoria
	sf::Font font;
	if(!font.loadFromFile("./font/Comic_Sans_MS.ttf")){
		std::cout << "Erro ao abrir arquivo!\n";
		return -1;
	}
	
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setPosition((window.getSize().x/2)-220, 100);

    while(window.isOpen()){
		float deltaTime = clock.restart().asSeconds();
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

		if(!gameover){
			//std::system("clear");
			// Movimento do jogador
			p1.playerMove(p1.player, window, sf::Keyboard::Up, sf::Keyboard::Down);
			p2.playerMove(p2.player, window, sf::Keyboard::W, sf::Keyboard::S);
			
			// Movimento da bola
			b.moveBall(window, p1.player, p2.player, gs.pOne_score, gs.pTwo_score);
			
			// Verifica se um dos jogadores atingiu
			// a pontuação máxima
			if(gs.verifyVictory(gs.pOne_score.getTextureRect())){
				gameover = true;
				text.setString("Jogador 1 Venceu!");
			}else if(gs.verifyVictory(gs.pTwo_score.getTextureRect())){
				gameover = true;
				text.setString("Jogador 2 Venceu!");
			}
		}
		
        window.clear(sf::Color::Black);
        window.draw(p1.player);
		window.draw(p2.player);
        window.draw(b.ball);
		window.draw(text);
		window.draw(gs.pOne_score);
		window.draw(gs.pTwo_score);
        window.display();
    }


    return 0;
}
