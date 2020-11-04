#include "gameController.h"

#include <iostream>

GameController::GameController(Personagem personagem){
	this->personagem = std::unique_ptr<Personagem>(new Personagem(personagem));
	this->personagemView = std::shared_ptr<PersonagemView>(new PersonagemView(CHARACTER_SIZE, CHARACTER_SIZE, this->personagem->get_teta()));
	this->gameView = std::unique_ptr<GameView>(new GameView(this->personagemView));
}

void GameController::start(){
	while (!(this->iterate()));
}

void GameController::personagem_updateViewByModel(){
	this->personagemView->update(this->personagem->get_x(), this->personagem->get_y(), this->personagem->get_teta());
}

int GameController::iterate(){
	this->personagem->handle_keyboard((this->keyboardHandler.getInput()));
	std::cout<<this->personagem->get_x()<<std::endl;
	std::cout<<this->personagem->get_y()<<std::endl;
	personagem_updateViewByModel();
	return this->gameView->draw();
}
