#include "gameController.h"
#include <iostream>

GameController::GameController(Personagem personagem, std::vector<Zumbi> zumbis){
	this->personagem = std::unique_ptr<Personagem>(new Personagem(personagem));
	this->zumbis = zumbis;
	this->zumbiViews = std::vector<ZumbiView>();
    this->>axeViews = std::vector<AxeView>();
	for (auto z = this->zumbis.begin(); z != this->zumbis.end(); ++z) {
		this->zumbiViews.push_back(ZumbiView(CHARACTER_SIZE, CHARACTER_SIZE, z->get_teta(), "../assets/zombie.png"));
	} 
	this->personagemView = std::shared_ptr<PersonagemView>(new PersonagemView(CHARACTER_SIZE, CHARACTER_SIZE, this->personagem->get_teta(), "../assets/tree-character.png"));
	this->gameView = std::unique_ptr<GameView>(new GameView(this->personagemView, this->zumbiViews));
}

void GameController::addZumbi(Zumbi zumbi){
	this->zumbis.push_back(zumbi);
}

void GameController::start(){
	while (!(this->iterate()));
}

void GameController::zumbi_updateViewByModel(){
	for (int i = 0; i < this->zumbiViews.size(); ++i){
		std::cout << this->zumbis.at(i).get_x() << "  " << this->zumbis.at(i).get_y() << std::endl;
		this->gameView->changeZumbi(i, this->zumbis.at(i).get_x(), this->zumbis.at(i).get_y(), this->zumbis.at(i).get_teta());
	} 
}

void GameController::axe_updateViewByModel(){
    for(int i = 0; i < this->axesVie.size(); ++i){

    }
}

void GameController::personagem_updateViewByModel(){
	this->personagemView->update(this->personagem->get_x(), this->personagem->get_y(), this->personagem->get_teta());
}

int GameController::iterate(){
    tempo = SDL_GetTicks();
	this->personagem->handle_keyboard((this->keyboardHandler.getInput()));
	for (auto z = this->zumbis.begin(); z != this->zumbis.end(); ++z){
		z->followPersonagem(*(this->personagem));
	}
	personagem_updateViewByModel();
	zumbi_updateViewByModel();
	return this->gameView->draw();
    tempo_passado = time;
}
