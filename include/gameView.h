#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
class GameView{
	private:
		PersonagemView personagemView;
	public:
		GameView();
		~GameView();
		drawGame();

}
