#include "receiver.hpp"

void receiver(std::shared_ptr<ServerController> serverController, int port) {
	char clean[MAX_BUFFER_SIZE];
	int i;
	for (i = 0; i < MAX_BUFFER_SIZE; i++){
		clean[i] = '\0';
	}
	char v[MAX_BUFFER_SIZE];
	bool firstPlayer = true;
	while (!(serverController->get_gameController()->stop)){
		memcpy(v, clean, MAX_BUFFER_SIZE);

		boost::asio::ip::udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

		serverController->get_socket()->receive_from(boost::asio::buffer(v,MAX_BUFFER_SIZE), // Local do buffer
			      remote_endpoint); // Confs. do Cliente

		nlohmann::json clientJson = nlohmann::json::parse(v);

		std::string request_type = clientJson[JSON_KEY_TYPE];
		
		if (request_type.compare(JSON_TYPE_HANDSHAKE) == 0) {
			std::string new_player_id = serverController->get_gameController()->addPersonagem(remote_endpoint.address().to_string());	
			serverController->addEndpoint(remote_endpoint);
			std::cout<<"Temos um handshake"<<std::endl;
			if (firstPlayer){
				firstPlayer = false;
				serverController->get_gameController()->AllToOne(new_player_id);
			}
		} else if (request_type.compare(JSON_TYPE_COMMAND) == 0){
			
			std::string id = remote_endpoint.address().to_string();
			int action = clientJson[JSON_KEY_BODY][JSON_KEY_BODY_COMMAND];
			std::cout<<"Inicio de comando"<<std::endl;
			serverController->get_gameController()->updateMovement(id, action);
			std::cout<<"Fim do comando"<<std::endl;

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



