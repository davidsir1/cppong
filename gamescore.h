#ifndef  GAMESCORE_H
#define GAMESCORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameScore {
    public:
        GameScore();
        ~GameScore();
        sf::Texture numbers;
        sf::Sprite pOne_score, pTwo_score;
		sf::IntRect rectSourceSprite;

		void updateScore(sf::Sprite& s, sf::IntRect& r);
		void displayScore(sf::Window &window);
		bool verifyVictory(sf::IntRect r);
		bool loadTexture();
    private:
};

#endif // ! GAMESCORE_H
