#include "clientController.hpp"

ClientController::ClientController(std::string filename){
	std::fstream stateReadFile(filename, std::ios_base::in);

	std::string ip;
	
	std::getline(stateReadFile, ip);

	int port;

	stateReadFile >> port;

	std::cout<<ip<<std::endl;
	std::cout<<port<<std::endl;
	boost::asio::io_service io_service;
	boost::asio::ip::udp::endpoint local_endpoint(
			boost::asio::ip::udp::v4(),
			port
			);
	this->socket = std::make_shared<boost::asio::ip::udp::socket>(io_service, local_endpoint);
	this->serverEndpoint = std::make_shared<boost::asio::ip::udp::endpoint>(
		    boost::asio::ip::address::from_string(ip),
		    port
	);
}

void ClientController::makeHandshake(){
	nlohmann::json request;
	request[JSON_KEY_TYPE] = JSON_TYPE_HANDSHAKE;
	this->socket->send_to(boost::asio::buffer(request.dump()), *this->serverEndpoint);
}
