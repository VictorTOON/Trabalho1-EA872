#include "gameView.hpp"
#include "characterController.hpp"
#include "gameController.hpp"
#include "zombieController.hpp"
#include <vector>
int main(){
	PersonagemController p(300,300,130, 130, 0);
	AxeController n(10,12,0.5);
	std::vector<ZumbiController> zs; 
	for (int i = 6; i < 9; i++){
		zs.push_back(ZumbiController(i*100, i*100,150,150, 0));
	}

	GameController gameController(p,zs);
	gameController.start();
	return 0;
}
