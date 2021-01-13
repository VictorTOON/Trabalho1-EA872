#include "receiver.hpp"

void receiver(std::shared_ptr<ClientController> clientController) {
	char clean[MAX_BUFFER_SIZE];
	int i;
	for (i = 0; i < MAX_BUFFER_SIZE; i++){
		clean[i] = '\0';
	}
	char v[MAX_BUFFER_SIZE];
	while (!(clientController->get_gameController()->stop)){
		memcpy(v, clean, MAX_BUFFER_SIZE);

		std::cout << "Esperando mensagem!" << std::endl;

		if (!(clientController->get_gameController()->stop)){
			clientController->get_socket()->receive_from(boost::asio::buffer(v,MAX_BUFFER_SIZE), // Local do buffer
				      *clientController->get_serverEndpoint()); // Confs. do Server
			
			std::cout << "Fim de mensagem!" << std::endl;
			clientController->get_gameController()->readServerStateJson(nlohmann::json::parse(v));
		}
		memcpy(v, clean, MAX_BUFFER_SIZE);
        
	}

} 



