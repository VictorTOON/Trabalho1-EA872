#include "characterController.hpp"
#include "gameController.hpp"
#include "zombieController.hpp"
#include "sender.hpp"
#include "receiver.hpp"
#include <vector>
#include <string>
#include <boost/asio.hpp>

int main(int argc, char *argv[]){

	GameController gameController("./state.ini");
	/*
	std::thread t;
	std::cout << argv[0] << std::endl;
	if (argv[1][0] == 'r'){ 
		t = std::thread(receiver, 9001, &gameController);
	}
	else{
		t = std::thread(sender, "25.6.123.125", 9001, &gameController);
	}
	gameController.start();
	t.join();
	*/return 0;
}
