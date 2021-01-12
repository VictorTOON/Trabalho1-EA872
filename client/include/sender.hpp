#include "gameController.hpp"
#include <thread>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>

/*class Sender {
	public:
		static void send(std::string ip, int port, nlohmann::json gameJson);
};*/

void sender(std::string ip, int port, GameController *gameController);



