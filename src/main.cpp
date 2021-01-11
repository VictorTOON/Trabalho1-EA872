#include "characterController.hpp"
#include "gameController.hpp"
#include "zombieController.hpp"
#include "serverController.hpp"
#include "sender.hpp"
#include "receiver.hpp"
#include "iterateQueue.hpp"
#include <vector>
#include <string>
#include <boost/asio.hpp>

int main(int argc, char *argv[]){


	std::shared_ptr<GameController> gameController = std::make_shared<GameController>(FILENAME_STATE_INIT);

	std::shared_ptr<ServerController> serverController = std::make_shared<ServerController>(gameController);

	std::thread thread_iterate = std::thread(iterateQueue, serverController);
	std::thread thread_sender = std::thread(sender, serverController, UDP_PORT);
	std::thread thread_receiver = std::thread(receiver, serverController, UDP_PORT);

	gameController->start();

	thread_iterate.join();
	thread_sender.join();
	thread_receiver.join();
	return 0;
}
