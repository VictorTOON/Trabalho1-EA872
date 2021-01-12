#include "receiver.hpp"

void receiver(std::shared_ptr<ServerController> serverController, int port) {
	char clean[MAX_BUFFER_SIZE];
	int i;
	for (i = 0; i < MAX_BUFFER_SIZE; i++){
		clean[i] = '\0';
	}
	char v[MAX_BUFFER_SIZE];
	while (!(serverController->get_gameController()->stop)){
		memcpy(v, clean, MAX_BUFFER_SIZE);

		boost::asio::ip::udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

		std::cout << "Esperando mensagem!" << std::endl;

		serverController->get_socket()->receive_from(boost::asio::buffer(v,MAX_BUFFER_SIZE), // Local do buffer
			      remote_endpoint); // Confs. do Cliente

		std::cout << v << std::endl;

		nlohmann::json clientJson = nlohmann::json::parse(v);

		serverController->pushToQueue(clientJson, remote_endpoint);
		
	}

} 



