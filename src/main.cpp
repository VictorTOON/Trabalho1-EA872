#include "gameView.hpp"
#include "characterController.hpp"
#include "gameController.hpp"
#include "zombieController.hpp"
#include "sender.hpp"
#include "receiver.hpp"
#include <vector>
#include <string>
#include <boost/asio.hpp>

int main(int argc, char *argv[]){
	PersonagemController p(300,300,130, 130, 0);
	AxeController n(10,12,0.5);
	std::vector<ZumbiController> zs; 
	for (int i = 6; i < 9; i++){
		zs.push_back(ZumbiController(i*100, i*100,100,100, 0));
	}
	
	GameController gameController(p,zs);
	std::thread t;
	std::cout << argv[0] << std::endl;
	if (argv[1][0] == 'r'){ 
		t = std::thread(receiver, 9001, &gameController);
	}
	else{
		t = std::thread(sender, "25.86.17.137", 9001, &gameController);
	}
	gameController.start();
	t.join();
	return 0;
}
