#include "gameController.hpp"

#include <iostream>

GameController::GameController(){
	this->gameModel = std::unique_ptr<GameModel> (new GameModel());
	this->keyboardHandler = SDL_Keyboard_Handler();

	this->gameView = std::unique_ptr<GameView>(new GameView());
	this->stop = false;
}


void GameController::readServerStateJson(nlohmann::json stateJson){

	for (auto &personagem : this->personagens){
		if (stateJson[MAP_KEY_PLAYERS].count(personagem.first) > 0){
			this->personagens.find(personagem.first)->second.readStateJson(stateJson[MAP_KEY_PLAYERS][personagem.first]);	
		} else {
			this->personagens.erase(personagem.first);
			continue;
		}
		stateJson[MAP_KEY_PLAYERS].erase(personagem.first);
	}
	for (auto &zumbi : this->zumbis){
		if (stateJson[MAP_KEY_ZOMBIES].count(zumbi.first) > 0){
			this->zumbis.find(zumbi.first)->second.readStateJson(stateJson[MAP_KEY_ZOMBIES]);	
		} else {
			this->zumbis.erase(zumbi.first);
			continue;
		}
		stateJson[MAP_KEY_ZOMBIES].erase(zumbi.first);
	}
	std::unordered_map<std::string, nlohmann::json> zumbisJson = stateJson[MAP_KEY_ZOMBIES];
	for (auto &zumbiJson : zumbisJson){
		ZumbiController z(zumbiJson.second["model"]["base"]["x"], zumbiJson.second["model"]["base"]["y"], zumbiJson.second["model"]["base"]["h"], zumbiJson.second["model"]["base"]["w"], zumbiJson.second["model"]["base"]["teta"]);

		z.set_id(zumbiJson.first);
		z.readStateJson(zumbisJson);
		z.set_player_id(zumbiJson.second["player_id"]);

		this->gameView->addZumbi(z.getView());
		this->zumbis.insert(std::make_pair(zumbiJson.first, z));
	}
	std::unordered_map<std::string, nlohmann::json> personagensJson = stateJson[MAP_KEY_PLAYERS];
	for (auto &personagemJson : personagensJson){
		PersonagemController p(personagemJson.second["model"]["base"]["x"], personagemJson.second["model"]["base"]["y"], personagemJson.second["model"]["base"]["h"], personagemJson.second["model"]["base"]["w"], personagemJson.second["model"]["base"]["teta"]);
		p.readStateJson(personagemJson.second);
		this->gameView->addPersonagem(p.getView());
		this->personagens.insert(std::make_pair(personagemJson.first, p));
	}
}

void GameController::start(){
	static auto t_start = std::chrono::high_resolution_clock::now();
	static auto t_end = std::chrono::high_resolution_clock::now();

	while (!(this->iterate())){

		t_end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();

		if (elapsed < INT_DELAY_MS){
			std::this_thread::sleep_for(std::chrono::milliseconds(INT_DELAY_MS-elapsed));
		}
		t_start = t_end;

	}
	this->stop = true;
}

int GameController::iterate(){
	int returnDraw = this->gameView->draw();
	
	for (auto &personagem: this->personagens){
		personagem.second.updateView();
	}
	
	for (auto &zumbi: this->zumbis){
		if (this->personagens.find(zumbi.second.get_player_id()) == this->personagens.end()){

		}else{
			zumbi.second.updateView(this->personagens.at(zumbi.second.get_player_id()).getModel());
		}
	}



	this->gameView->finishDraw();
	this->action = this->keyboardHandler.getInput();
	if (this->action & (1 << KEYBOARD_ZERO) ){
		return -1;		
	}
	return returnDraw;
}

int GameController::get_action(){
    return this->action;
}

GameController::~GameController(){}
