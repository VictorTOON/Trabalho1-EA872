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

		serverController->receive_from(v,10000, // Local do buffer
			      remote_endpoint); // Confs. do Cliente

		std::cout << v << std::endl;
		std::cout << "ARROMBADO "<<remote_endpoint.address().to_string()<<std::endl;
		nlohmann::json clientJson = nlohmann::json::parse(v);

		serverController->pushToQueue(clientJson, remote_endpoint);

		
		std::cout << "Fim de mensagem!" << std::endl;

		// Respondendo a mensagem
		std::string msg("Recebido! Obrigado, cambio e desligo!");
		serverController->get_socket()->send_to(boost::asio::buffer(msg), remote_endpoint);

		std::cout << "Mensagem de retorno enviada" << std::endl;
	
	}

} 



