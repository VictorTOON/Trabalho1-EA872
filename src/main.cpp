#include "gameView.h"
#include "characterModel.h"
#include "sdl_keyboard_handler.h"
#include "gameController.h"

int main(){
	Personagem p(300,300, 0);
	GameController gameController(p);
	gameController.start();
	return 0;
}
