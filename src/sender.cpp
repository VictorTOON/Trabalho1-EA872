#include "sender.hpp"

void sender(std::shared_ptr<ServerController> serverController, int port){

	while(!(serverController->isEndpointMapEmpty())); // Enquanto nao temos nenhum cliente
	std::cout<<"Nao esta vazio"<<std::endl;
	serverController->get_gameController()->getStateJson();
	
	while(!(serverController->get_gameController()->stop)){
		std::unordered_map<std::string, boost::asio::ip::udp::endpoint> endpointMap = serverController->get_endpointMap();
		for (auto &pair_endpoint : endpointMap){

			std::string message = serverController->get_gameController()->getStateJson().dump();
			serverController->get_socket()->send_to(boost::asio::buffer(message), pair_endpoint.second);
		}
	}
}
