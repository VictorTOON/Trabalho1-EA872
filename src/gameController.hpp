#pragma once

#include "gameView.hpp"
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

class GameController {
	private:
		std::unique_ptr<GameModel> gameModel;
		std::unique_ptr<PersonagemController> personagem;
		std::vector<ZumbiController> zumbis;
		std::unique_ptr<GameView> gameView;
		SDL_Keyboard_Handler keyboardHandler;
		std::vector<ZumbiView> zumbiViews;
		std::ofstream stateFile;
		void updatePersonagemView();
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
};
