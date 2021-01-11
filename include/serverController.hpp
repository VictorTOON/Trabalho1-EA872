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
		std::vector<boost::asio::ip::udp::endpoint> endpointVector;

	public:
		ServerController(std::shared_ptr<GameController> gameController);
		std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> removeFromQueue();
		void pushToQueue(nlohmann::json requisition, boost::asio::ip::udp::endpoint client_endpoint);
		bool isQueueEmpty();
		bool isEndpointVectorEmpty();
		void addEndpoint(boost::asio::ip::udp::endpoint new_endpoint);
		std::vector<boost::asio::ip::udp::endpoint> get_endpointVector();
		std::shared_ptr<GameController> get_gameController();
			
}; 
