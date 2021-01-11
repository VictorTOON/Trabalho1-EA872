#include "serverController.hpp"

ServerController::ServerController(std::shared_ptr<GameController> gameController){
	this->gameController = gameController;
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

std::vector<boost::asio::ip::udp::endpoint> ServerController::get_endpointVector(){
	return this->endpointVector;
}

void ServerController::addEndpoint(boost::asio::ip::udp::endpoint new_endpoint){
	this->endpointVector.push_back(new_endpoint);
}

std::shared_ptr<GameController> ServerController::get_gameController(){
	return this->gameController;
}


