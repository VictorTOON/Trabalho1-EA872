#pragma once

#include "gameView.h"
#include "characterView.h"
#include "characterModel.h"
#include "sdl_keyboard_handler.h"

#include <iomanip>
#include <iostream>

class GameController {
	private:
		unique_ptr<Personagem> personagem;
		unique_ptr<GameView> gameView;
		unique_ptr<PersonagemView> personagemView;
		void updatePersonagemView();
	public:
		GameController();
		start();
};
