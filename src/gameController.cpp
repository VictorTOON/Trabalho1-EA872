#include "gameController.h"

#include <iostream>

GameController::GameController(Personagem personagem, Zumbi zumbi){
	this->personagem = std::unique_ptr<Personagem>(new Personagem(personagem));
	this->zumbi = std::unique_ptr<Zumbi>(new Zumbi(zumbi));
	this->zumbiView = std::shared_ptr<ZumbiView>(new ZumbiView(CHARACTER_SIZE, CHARACTER_SIZE, this->zumbi->get_teta(), "../assets/zombie.png"));
	this->personagemView = std::shared_ptr<PersonagemView>(new PersonagemView(CHARACTER_SIZE, CHARACTER_SIZE, this->personagem->get_teta(), "../assets/tree-character.png"));
	this->gameView = std::unique_ptr<GameView>(new GameView(this->personagemView, this->zumbiView));
}

void GameController::start(){
	while (!(this->iterate()));
}

void GameController::zumbi_updateViewByModel(){
	this->zumbiView->update(this->zumbi->get_x(), this->zumbi->get_y(), this->zumbi->get_teta());
}
void GameController::personagem_updateViewByModel(){
	this->personagemView->update(this->personagem->get_x(), this->personagem->get_y(), this->personagem->get_teta());
}

int GameController::iterate(){
	this->personagem->handle_keyboard((this->keyboardHandler.getInput()));
	this->zumbi->followPersonagem(*(this->personagem));
	std::cout<<this->personagem->get_x()<<std::endl;
	std::cout<<this->personagem->get_y()<<std::endl;
	personagem_updateViewByModel();
	zumbi_updateViewByModel();
	return this->gameView->draw();
}
