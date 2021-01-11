#include "serverController.hpp"

ServerController::ServerController(std::shared_ptr<GameController> gameController, int port){
	this->gameController = gameController;
	boost::asio::io_service io_service;
	boost::asio::ip::udp::endpoint local_endpoint(
			boost::asio::ip::udp::v4(),
			port
			);
	this->socket = std::make_shared<boost::asio::ip::udp::socket>(io_service, local_endpoint);

	}

void ServerController::pushToQueue(nlohmann::json requisition, boost::asio::ip::udp::endpoint client_endpoint){
	this->clientCommandStack.push(std::make_pair(requisition, client_endpoint));
}

std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> ServerController::removeFromQueue(){
	std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> front = this->clientCommandStack.front();
	this->clientCommandStack.pop();
	return front;
}

bool ServerController::isQueueEmpty(){
	return this->clientCommandStack.empty();
}

bool ServerController::isEndpointVectorEmpty(){
	return this->endpointVector.empty();
}

std::vector<std::string> ServerController::get_endpointVector(){
	return this->endpointVector;
}

void ServerController::addEndpoint(std::string new_endpoint){//std::shared_ptr<boost::asio::ip::udp::endpoint> new_endpoint){
	std::cout<<"Adicionando endpoint"<<std::endl;
	this->endpointVector.push_back(new_endpoint);
}

std::shared_ptr<GameController> ServerController::get_gameController(){
	return this->gameController;
}

std::shared_ptr<boost::asio::ip::udp::socket> ServerController::get_socket(){
	return this->socket;
}

void ServerController::send_to(std::string message, boost::asio::ip::udp::endpoint remote_endpoint){
	this->socket->send_to(
			boost::asio::buffer(message),
			remote_endpoint
			);
}

void ServerController::receive_from(char message[], int size, boost::asio::ip::udp::endpoint remote_endpoint){
	this->socket->receive_from(boost::asio::buffer(message, size), remote_endpoint);
}
