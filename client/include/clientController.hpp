#pragma once

#include "gameController.hpp"
#include "json.hpp"
#include <memory>
#include <boost/asio.hpp>
#include "constants.hpp"

class ClientController {
	private:
		std::shared_ptr<boost::asio::ip::udp::socket> socket;
		std::shared_ptr<boost::asio::ip::udp::endpoint> serverEndpoint;
	public: 
		ClientController(std::string filename);
		void makeHandshake();
};
