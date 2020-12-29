#include "gameController.hpp"
#include <thread>
#include <string>
#include <boost/asio.hpp>

class Sender {
	public:
		static void send(std::string ip, int port, GameController &gameController);
};



