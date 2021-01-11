#pragma once

#include <queue>
#include "json.hpp"
#include <memory>
#include <utility>
#include "gameController.hpp"
#include <boost/asio.hpp>
#include <map>
#include <vector>

class ServerController{
	private:
		std::queue<
			std::pair<nlohmann::json, boost::asio::ip::udp::endpoint>
		> clientCommandStack;
		std::shared_ptr<GameController> gameController;
		std::vector<std::string> endpointVector;

		std::shared_ptr<boost::asio::ip::udp::socket> socket;

	public:
		ServerController(std::shared_ptr<GameController> gameController, int port);
		std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> removeFromQueue();
		void pushToQueue(nlohmann::json requisition, boost::asio::ip::udp::endpoint client_endpoint);
		bool isQueueEmpty();
		bool isEndpointVectorEmpty();
		void addEndpoint(std::string new_endpoint);
		std::vector<std::string> get_endpointVector();
		std::shared_ptr<GameController> get_gameController();
		void send_to(std::string message, boost::asio::ip::udp::endpoint remote_endpoint);
		void receive_from(char message[], int size, boost::asio::ip::udp::endpoint remote_endpoint);
		std::shared_ptr<boost::asio::ip::udp::socket> get_socket();
			
}; 
