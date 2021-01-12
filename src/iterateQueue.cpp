#include "iterateQueue.hpp"

void iterateQueue(std::shared_ptr<ServerController> serverController){
	std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> currentPair;
	nlohmann::json clientJson;
	boost::asio::ip::udp::endpoint remote_endpoint;
	nlohmann::json response;
	while (!(serverController->get_gameController()->stop)){
		if (!(serverController->isQueueEmpty())){
			currentPair = serverController->removeFromQueue();
			
			clientJson = currentPair.first;
			remote_endpoint = currentPair.second;

			std::string request_type = clientJson[JSON_KEY_TYPE];
			
			if (request_type.compare(JSON_TYPE_HANDSHAKE) == 0) {
				std::string new_player_id = serverController->get_gameController()->addPersonagem(remote_endpoint.address().to_string());	
				response[JSON_KEY_TYPE] = JSON_TYPE_HANDSHAKE;
				response[JSON_KEY_BODY][JSON_KEY_BODY_ID] = new_player_id;
				serverController->addEndpoint(remote_endpoint);
				std::cout<<"Temos um handshake"<<std::endl;
			} else if (request_type.compare(JSON_TYPE_COMMAND) == 0){
				
				std::string id = remote_endpoint.address().to_string();
				int action = clientJson[JSON_KEY_BODY][JSON_KEY_BODY_COMMAND];

				serverController->get_gameController()->updateMovement(id, action);

			} else if (request_type.compare(JSON_TYPE_GOODBYE) == 0){
				std::string id = remote_endpoint.address().to_string();
				int retRemove = serverController->get_gameController()->removePersonagem(id);
				if (retRemove <= 0){
					serverController->get_gameController()->stopGame();
				}
			} else {
				std::cout<<ERR_INVALID_TYPE<<std::endl;
			}
		}
	}

}
