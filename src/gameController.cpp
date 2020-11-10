#include "gameController.h"

#include <iostream>

GameController::GameController(PersonagemController personagem, std::vector<ZumbiController> zumbis){
	this->personagem = std::unique_ptr<PersonagemController>(new PersonagemController(personagem));
	this->zumbis = zumbis;
	this->gameView = std::unique_ptr<GameView>(new GameView());
	this->gameView->addPersonagem(this->personagem->getView());
	for (auto z = zumbis.begin(); z != zumbis.end(); ++z){
		this->gameView->addZumbi(z->getView());
	}
}

void GameController::addZumbi(ZumbiModel zumbi){
}

void GameController::start(){
	while (!(this->iterate()));
}

int GameController::iterate(){
	int returnDraw = this->gameView->draw();
	this->personagem->iterate();
	for (auto z = this->zumbis.begin(); z != this->zumbis.end(); ++z){
		z->iterate(this->personagem->getModel());
	}
	this->gameView->finishDraw();
	return returnDraw;
}
