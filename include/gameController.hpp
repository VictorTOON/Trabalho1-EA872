#pragma once

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

class GameController {
	private:
		std::unique_ptr<GameModel> gameModel;
		std::unique_ptr<PersonagemController> personagem;
		std::vector<ZumbiController> zumbis;
		std::ofstream stateWriteFile;
		std::ifstream stateReadFile;
		std::stringstream stateReadFile_s;
	public:
		GameController(PersonagemController personagem, std::vector<ZumbiController> zumbis);
		~GameController();
		void addZumbi(ZumbiModel zumbi);
		void start();
		int iterate();
		void spawnZombie();
		nlohmann::json getStateJson();
		void readStateJson();
		void saveStateJson();
		void readServerStateJson(nlohmann::json stateJson);
		bool stop;
};
