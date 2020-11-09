#include "gameController.h"

#include <iostream>

GameController::GameController(Personagem personagem, Zumbi zumbi, Axe axe){
	this->personagem = std::unique_ptr<Personagem>(new Personagem(personagem));
	this->zumbi = std::unique_ptr<Zumbi>(new Zumbi(zumbi));
    this->axe = std::unique_ptr<Axe> (new Axe(axe);
    this->axeView = std::shared_ptr<AxeView>(new AxeView(CHARACTER_SIZE/2, CHARACTER_SIZE/2, this->axe->get_teta(), "../assets/axe.png"));
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
void GameController::axe_updateViewByModel(){
    this->axeView->update(this->axe->get_x(), this->axe->get_y())
}
void GameController::personagem_updateViewByModel(){
	this->personagemView->update(this->personagem->get_x(), this->personagem->get_y(), this->personagem->get_teta());
}

int GameController::iterate(){
    tempo = SDL_GetTicks()
	this->personagem->handle_keyboard((this->keyboardHandler.getInput()));
	this->zumbi->followPersonagem(*(this->personagem));
    this->axe->update_xy(float tempo_passado, float tempo
	std::cout<<this->personagem->get_x()<<std::endl;
	std::cout<<this->personagem->get_y()<<std::endl;
	personagem_updateViewByModel();
	zumbi_updateViewByModel();
    axe_updateViewByModel()
	return this->gameView->draw();
    tempo_passado = time
}
