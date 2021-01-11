#include "gameController.hpp"

#include <iostream>

GameController::GameController(std::string filename){
	this->readInitFile(filename);
	this->gameModel = std::unique_ptr<GameModel> (new GameModel());
	this->stop = false;
}

nlohmann::json GameController::getStateJson(){
	nlohmann::json stateJson;	
	nlohmann::json zombieJsons;
	for (auto& zumbi :  this->zumbis){
		zombieJsons[zumbi.first] = zumbi.second.getStateJson();
	}
	std::cout<<zombieJsons<<std::endl;

	nlohmann::json personagensJson;
	for (auto& personagem : this->personagens){
		personagensJson[personagem.first] = personagem.second.getStateJson();
	}
	std::cout<<zombieJsons<<std::endl;
	stateJson[MAP_KEY_ZOMBIES] = zombieJsons;
	stateJson[MAP_KEY_PLAYERS] = personagensJson;
	std::cout<<stateJson<<std::endl;
	return stateJson;

}

void GameController::saveStateJson(){
	this->stateWriteFile.open(FILENAME_STATE_JSON);
	stateWriteFile << this->getStateJson();
	stateWriteFile.close();
}

void GameController::readServerStateJson(nlohmann::json stateJson){
	
	//this->personagem->readStateJson(stateJson[MAP_KEY_PLAYERS]);
	/*this->zumbis.clear();
	for (int i_json = 0; i_json < stateJson[MAP_KEY_ZOMBIES].size(); i_json++){
		ZumbiController z(150, 150, 100, 100, 0);
		z.readStateJson(stateJson[MAP_KEY_ZOMBIES][i_json]);
		this->zumbis.push_back(z);
	}*/
}
void GameController::readInitFile(std::string filename){
	int h, w, x, y;
	std::fstream stateReadFile(filename, std::ios_base::in);
	std::string line;
	if (stateReadFile.is_open()){
		stateReadFile >> h >> w;
		while (stateReadFile >> x >> y){
			ZumbiController z(h, w, x, y, INT_THETA_ZOMBIE);
			this->zumbis.insert(std::make_pair(z.get_id(), z));

		}

	
		std::cout<<"hmmm"<<std::endl;
		stateReadFile.close();
	} else {
		std::cout<<"eita"<<std::endl;
		return;
	}
}


void GameController::start(){
	while (!(this->iterate())){
		std::this_thread::sleep_for(std::chrono::milliseconds(80));	
	}
	this->stop = true;
}

int GameController::iterate(){
	for (auto personagem = this->personagens.begin(); personagem != this->personagens.end(); ++personagem){
	//	this->personagens[personagem->first].iterate();
	}
	//for (auto z = this->zumbis.begin(); z != this->zumbis.end(); ++z){
/*	for (int k = 0; k < this->zumbis.size(); k++){
		zumbis[k].iterate(this->personagem->getModel());
		for (int i=0; i < this->personagem->get_axeControllers().size(); i++){
			if (gameModel->checkIntersection(*this->personagem->get_axeControllers()[i].get_axeModel(), zumbis[k].get_model()) == Mata){
				this->zumbis.erase(zumbis.begin() + k);
				k--;
				spawnZombie();
				break;
			}
		}
	}*/
	int returnDraw = 0;
	return returnDraw;
}

void GameController::spawnZombie(){
	/*for (int a = 0; a < rand() % 3 + 1; a++){
		if(this->zumbis.size() < 20){
			int randomX = rand() % 1600 + 0;
			int randomY = rand() % 900 + 0;
			if ((abs(randomX - this->personagem->getModel()->get_x()) > 150) && (abs(randomY - this->personagem->getModel()->get_y()) > 150)){
				ZumbiController zumbi_novo(randomX, randomY,100,100, 0);
				this->zumbis.push_back(zumbi_novo);
			}
			else{
				a--;
			}
		}
	}*/
}
GameController::~GameController(){}
