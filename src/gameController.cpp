#include "gameController.hpp"

#include <iostream>

GameController::GameController(){
	this->gameModel = std::unique_ptr<GameModel> (new GameModel());
	this->keyboardHandler = SDL_Keyboard_Handler();

	this->gameView = std::unique_ptr<GameView>(new GameView());
	this->stop = false;
}

nlohmann::json GameController::getStateJson(){
	nlohmann::json stateJson;	
	/*nlohmann::json zombieJsons;
	for (auto &z = zumbis.begin(); z != zumbis.end(); ++z){
		zombieJsons[z->get_id()] = z->getStateJson();
	}
	stateJson[MAP_KEY_ZOMBIES] = zombieJsons;
	stateJson[MAP_KEY_PLAYERS] = this->personagem->getStateJson();
	std::cout<<stateJson<<std::endl;
*/
	return stateJson;

}

void GameController::saveStateJson(){
	/*
	this->stateWriteFile.open(FILENAME_STATE_JSON);
	stateWriteFile << this->getStateJson();
	stateWriteFile.close();
	*/
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
			this->zumbis.find(zumbi.first)->second.readStateJson(stateJson[MAP_KEY_ZOMBIES][zumbi.first]);	
		} else {
			this->zumbis.erase(zumbi.first);
			continue;
		}
		stateJson[MAP_KEY_ZOMBIES].erase(zumbi.first);
	}
	std::unordered_map<std::string, nlohmann::json> zumbisJson = stateJson[MAP_KEY_ZOMBIES];
	for (auto &zumbiJson : zumbisJson){
		ZumbiController z(zumbiJson.second["x"], zumbiJson.second["y"], zumbiJson.second["h"], zumbiJson.second["w"], zumbiJson.second["teta"]);
		z.readStateJson(zumbiJson.second);
		this->gameView->addZumbi(z.getView());
		this->zumbis.insert(std::make_pair(zumbiJson.first, z));
	}
	std::unordered_map<std::string, nlohmann::json> personagensJson = stateJson[MAP_KEY_PLAYERS];
	for (auto &personagemJson : personagensJson){
		PersonagemController p(personagemJson.second["x"], personagemJson.second["y"], personagemJson.second["h"], personagemJson.second["w"], personagemJson.second["teta"]);
		p.readStateJson(personagemJson.second);
		this->gameView->addPersonagem(p.getView());
		this->personagens.insert(std::make_pair(personagemJson.first, p));
	}
}
void GameController::readStateJson(){
	/*
	nlohmann::json stateJson;
	this->stateReadFile.open(FILENAME_STATE_JSON);
	std::stringstream s;
	stateReadFile >> stateJson;		
	std::cout<<stateJson[MAP_KEY_PLAYERS]<<std::endl;
	this->personagem->readStateJson(stateJson[MAP_KEY_PLAYERS]);
	this->zumbis.clear();
	for (int i_json=0; i_json < stateJson[MAP_KEY_ZOMBIES].size(); i_json++){
		ZumbiController z(150, 150, 100, 100, 0);
		z.readStateJson(stateJson[MAP_KEY_ZOMBIES][i_json]);
		this->gameView->addZumbi(z.getView());
		this->zumbis.push_back(z);
	}
	this->stateReadFile.close();*/
}


void GameController::start(){
	while (!(this->iterate()));
	this->stop = true;
}

int GameController::iterate(){
	/*if (ret & (1 << KEYBOARD_ZERO)){
		return -1;
	}*/
	int returnDraw = this->gameView->draw();

	this->gameView->finishDraw();
	return returnDraw;
}

void GameController::spawnZombie(){
/*	for (int a = 0; a < rand() % 3 + 1; a++){
		if(this->zumbis.size() < 20){
			int randomX = rand() % 1600 + 0;
			int randomY = rand() % 900 + 0;
			if ((abs(randomX - this->personagem->getModel()->get_x()) > 150) && (abs(randomY - this->personagem->getModel()->get_y()) > 150)){
				ZumbiController zumbi_novo(randomX, randomY,100,100, 0);
				this->gameView->addZumbi(zumbi_novo.getView());
				this->zumbis.push_back(zumbi_novo);
			}
			else{
				a--;
			}
		}
	}
*/
}

GameController::~GameController(){}
