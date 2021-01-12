#pragma once

#include "constants.hpp"
#include "characterController.hpp"
#include "zombieController.hpp"
#include "sdl_keyboard_handler.hpp"
#include "gameModel.hpp"
#include "json.hpp"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <map>
#include <string>
#include <queue>

class GameController {
	private:
		std::unique_ptr<GameModel> gameModel;
		std::map<std::string, PersonagemController> personagens;
		std::map <std::string, ZumbiController> zumbis;
		std::ofstream stateWriteFile;
		std::stringstream stateReadFile;
	public:
		GameController(std::string filename);
		~GameController();
		void addZumbi(ZumbiModel zumbi);
		void updateMovement(std::string id, int acao);
		std::string addPersonagem(std::string id);
		int removePersonagem(std::string id);
		void start();
		int iterate();
		void spawnZombie(PersonagemController p);
		nlohmann::json getStateJson();
		void readInitFile(std::string filename);
		void saveStateJson();
		void readServerStateJson(nlohmann::json stateJson);
		void stopGame();
		bool stop;
};
