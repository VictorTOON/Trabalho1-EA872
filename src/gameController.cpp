#include "gameController.hpp"

#include <iostream>

GameController::GameController(PersonagemController personagem, std::vector<ZumbiController> zumbis){
	this->personagem = std::unique_ptr<PersonagemController>(new PersonagemController(personagem));
	this->gameModel = std::unique_ptr<GameModel> (new GameModel());
	this->keyboardHandler = SDL_Keyboard_Handler();
	this->zumbis = zumbis;
	this->gameView = std::unique_ptr<GameView>(new GameView());
	this->gameView->addPersonagem(this->personagem->getView());
	for (auto z = zumbis.begin(); z != zumbis.end(); ++z){
		this->gameView->addZumbi(z->getView());
	}
	this->stop = false;
}

nlohmann::json GameController::getStateJson(){
	nlohmann::json stateJson;	
	nlohmann::json zombieJsons;
	for (auto z = zumbis.begin(); z != zumbis.end(); ++z){
		zombieJsons[z->get_id()] = z->getStateJson();
	}
	stateJson["zumbis"] = zombieJsons;
	stateJson["jogador"] = this->personagem->getStateJson();
	std::cout<<stateJson<<std::endl;

	return stateJson;

}

void GameController::saveStateJson(){
	this->stateWriteFile.open("state.json");
	stateWriteFile << this->getStateJson();
	stateWriteFile.close();
}


void GameController::readServerStateJson(nlohmann::json stateJson){
	this->personagem->readStateJson(stateJson["jogador"]);
	for (int i = 0; i < this->zumbis.size(); i++){
		this->zumbis[i].readStateJson(stateJson["zumbis"]);
	}
}
void GameController::readStateJson(){
	nlohmann::json stateJson;
	this->stateReadFile.open("state.json");
	std::stringstream s;
	stateReadFile >> stateJson;		
	std::cout<<stateJson["jogador"]<<std::endl;
	this->personagem->readStateJson(stateJson["jogador"]);
	this->zumbis.clear();
	for (int i_json=0; i_json < stateJson["zumbis"].size(); i_json++){
		ZumbiController z(150, 150, 100, 100, 0);
		z.readStateJson(stateJson["zumbis"][i_json]);
		this->gameView->addZumbi(z.getView());
		this->zumbis.push_back(z);
	}
	this->stateReadFile.close();
}


void GameController::start(){
	while (!(this->iterate()));
	this->stop = true;
}

int GameController::iterate(){
	int ret = this->keyboardHandler.getInput();
	if (ret & (1 << KEYBOARD_ZERO)){
		return -1;
	}
	if (ret & (1 << KEYBOARD_P)){
		this->saveStateJson();
	}
	if (ret & (1 << KEYBOARD_O)){
		this->readStateJson();
	}
	int returnDraw = this->gameView->draw();
	this->personagem->iterate();
	//for (auto z = this->zumbis.begin(); z != this->zumbis.end(); ++z){
	for (int k = 0; k < this->zumbis.size(); k++){
		zumbis[k].iterate(this->personagem->getModel());
		for (int i=0; i < this->personagem->get_axeControllers().size(); i++){
			if (gameModel->checkIntersection(*this->personagem->get_axeControllers()[i].get_axeModel(), zumbis[k].get_model()) == Mata){
				this->zumbis.erase(zumbis.begin() + k);
				k--;
				spawnZombie();
				break;
			}
		}
	}
	this->gameView->finishDraw();
	return returnDraw;
}

void GameController::spawnZombie(){
	for (int a = 0; a < rand() % 3 + 1; a++){
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
}
GameController::~GameController(){}
