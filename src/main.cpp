#include "gameView.h"
#include "characterModel.h"
#include "sdl_keyboard_handler.h"
#include "gameController.h"
#include "zombieModel.h"
#include <vector>
int main(){
	Personagem p(300,300, 0);
	std::vector<Zumbi> zs; 
	for (int i = 4; i < 7; i++){
		zs.push_back(Zumbi(i*100, i*100, 0));
	}

	GameController gameController(p,zs);
	gameController.start();
	return 0;
}
