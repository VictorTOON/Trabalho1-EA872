#include "sender.hpp"

void sender(std::shared_ptr<ServerController> serverController, int port){

	while(!(serverController->isEndpointVectorEmpty())); // Enquanto nao temos nenhum cliente
	std::cout<<"Nao esta vazio"<<std::endl;
	serverController->get_gameController()->getStateJson();
	
	while(!(serverController->get_gameController()->stop)){
		int size = serverController->get_endpointVector().size();
		std::vector<boost::asio::ip::udp::endpoint> endpointVector = serverController->get_endpointVector();
		for (int i = 0; i < size; i++){
			/*
			boost::asio::io_service my_io_service; // Conecta com o SO
			boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port); // endpoint: contem
								// conf. da conexao (ip/port)
			boost::asio::ip::udp::socket my_socket(my_io_service, // io service
					local_endpoint); // endpoint
*/
			std::string message = serverController->get_gameController()->getStateJson().dump();
			std::cout<<"Mandando..."<<std::endl;
			serverController->get_socket()->send_to(boost::asio::buffer(message), endpointVector[i]);
		}
	}
}
