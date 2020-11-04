#include "gameView.h"
#include "characterModel.h"
#include "sdl_keyboard_handler.h"
#include "gameController.h"
#include "zombieModel.h"

int main(){
	Personagem p(300,300, 0);
	Zumbi z(600,600, 0);
	GameController gameController(p,z);
	gameController.start();
	return 0;
}
