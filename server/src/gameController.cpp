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

	nlohmann::json personagensJson;
	for (auto& personagem : this->personagens){
		personagensJson[personagem.first] = personagem.second.getStateJson();
	}
	stateJson[MAP_KEY_ZOMBIES] = zombieJsons;
	stateJson[MAP_KEY_PLAYERS] = personagensJson;
	return stateJson;

}

void GameController::stopGame(){
	this->stop = true;
}

void GameController::saveStateJson(){
	this->stateWriteFile.open(FILENAME_STATE_JSON);
	stateWriteFile << this->getStateJson();
	stateWriteFile.close();
}

void GameController::readServerStateJson(nlohmann::json stateJson){
	
}

std::string GameController::addPersonagem(std::string id){
	PersonagemController p(
		INT_CHARACTER_X, 
		INT_CHARACTER_Y,
		INT_CHARACTER_H,
		INT_CHARACTER_W,
		FLOAT_CHARACTER_THETA);
	p.set_id(id);
	this->personagens.insert(std::make_pair(p.get_id(), p));
	return p.get_id();
}

int GameController::removePersonagem(std::string id){
	this->personagens.erase(id);		
	return this->personagens.size();
}

void GameController::AllToOne(std::string player_id){
	for (auto &z : this->zumbis){
		z.second.set_player_id(player_id);
	}
}

void GameController::readInitFile(std::string filename){
	int h, w, x, y;
	std::fstream stateReadFile(filename, std::ios_base::in);
	std::string line;
	if (stateReadFile.is_open()){
		stateReadFile >> h >> w;
		while (stateReadFile >> x >> y){
			ZumbiController z(x, y, h, w, FLOAT_ZOMBIE_THETA, CHARACTER_INITIAL_ID);
			this->zumbis.insert(std::make_pair(z.get_id(), z));
		}

		stateReadFile.close();
	} else {
		std::cout << ERR_FILE_NOT_FOUND << std::endl;
		return;
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

void GameController::updateMovement(std::string id, int acao){ 
	this->personagens.find(id)->second.addTo_fila_acoes(acao);
}

int GameController::iterate(){
	for (auto& personagem_atual: personagens){
		personagem_atual.second.iterate();
	}
	if (this->personagens.empty()){
		return 0;
	}
	for (auto& zumbi_atual: zumbis){
		zumbi_atual.second.iterate(this->personagens.find(zumbi_atual.second.get_player_id())->second.getModel());
		for (auto& jogador_atual: personagens){
			for (auto &pair_machado : jogador_atual.second.get_axeControllers()){
				AxeController machado = pair_machado.second;
				if (gameModel->checkIntersection(*machado.get_axeModel(), zumbi_atual.second.getModel()) == Mata){
					this->zumbis.erase(zumbi_atual.first);
					spawnZombie(jogador_atual.second);
					break;
				}
			}
		}
	}
	return this->stop;
}

void GameController::spawnZombie(PersonagemController p){
	for (int a = 0; a < rand() % 3 + 1; a++){
		if(this->zumbis.size() < 20){
			int randomX = rand() % 1600 + 0;
			int randomY = rand() % 900 + 0;
			if ((abs(randomX - p.getModel()->get_x()) > 150) && (abs(randomY - p.getModel()->get_y()) > 150)){
				ZumbiController zumbi_novo(randomX, randomY,100,100, 0, p.get_id());
				this->zumbis.insert(std::make_pair(zumbi_novo.get_id(), zumbi_novo));
			}
			else{
				a--;
			}
		}
	}
}
GameController::~GameController(){}
