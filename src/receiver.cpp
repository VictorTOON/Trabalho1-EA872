#include "receiver.hpp"

void receiver(std::shared_ptr<ServerController> serverController, int port) {
	char clean[10000];
	int i;
	for (i = 0; i < 10000; i++){
		clean[i] = '\0';
	}
	char v[10000];
	while (!(serverController->get_gameController()->stop)){
		std::cout<<"Estou recebendo coisas ainda"<<std::endl;
		memcpy(v, clean, 10000);

		boost::asio::ip::udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

		std::cout << "Esperando mensagem!" << std::endl;

		serverController->get_socket()->receive_from(boost::asio::buffer(v,10000), // Local do buffer
			      remote_endpoint); // Confs. do Cliente

		std::cout << v << std::endl;

		nlohmann::json clientJson = nlohmann::json::parse(v);

		serverController->pushToQueue(clientJson, remote_endpoint);
		
		std::cout << "Fim de mensagem!" << std::endl;

	
	}

} 



