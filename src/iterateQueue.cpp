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
				std::string new_player_id = serverController->get_gameController()->addPersonagem();	
				response[JSON_KEY_TYPE] = JSON_TYPE_HANDSHAKE;
				response[JSON_KEY_BODY][JSON_KEY_BODY_ID] = new_player_id;
				serverController->addEndpoint(remote_endpoint);
			} else if (request_type.compare(JSON_TYPE_COMMAND) == 0){
					
			} else if (request_type.compare(JSON_TYPE_GOODBYE) == 0){
				
			} else {
				std::cout<<ERR_INVALID_TYPE<<std::endl;
			}
		}
	}

}
