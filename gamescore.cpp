#include "gamescore.h"

GameScore::GameScore(){
}

GameScore::~GameScore(){
}

void GameScore::displayScore(sf::Window &window){
    if(!loadTexture()){
        std::cout << "Failed to open file...\n";
    }else{
        rectSourceSprite.top = 0;
        rectSourceSprite.left = 0;
		rectSourceSprite.height = (numbers.getSize().y)/1;
        rectSourceSprite.width = (numbers.getSize().x)/10;
		
		pOne_score.setTexture(numbers);
		pOne_score.setScale(sf::Vector2f(10.f, 10.f));
		pOne_score.setPosition((window.getSize().x/2.f)-80.f,5.f);
		pOne_score.setTextureRect(rectSourceSprite);

		pTwo_score.setTexture(numbers);
		pTwo_score.setScale(sf::Vector2f(10.f, 10.f));
		pTwo_score.setPosition((window.getSize().x/2.f),5.f);
		pTwo_score.setTextureRect(rectSourceSprite);
	}
}

void GameScore::updateScore(sf::Sprite& s, sf::IntRect& r){
	//std::cout << rect->left << '\n';
	if(r.left < 63){
		r.left += 70/10; // 70px -> Resolução da imagem na horizontal;
		s.setTextureRect(r);
	}
}

bool GameScore::verifyVictory(sf::IntRect r){
	bool isVictory = false;
	if(r.left == 63){
		isVictory = true;
	}
	return isVictory;
}

bool GameScore::loadTexture(){
	return numbers.loadFromFile("./font/Numbers7x10.png");
}
