#include "sender.hpp"

void sender(std::shared_ptr<ServerController> serverController, int port){

	while(!(serverController->isEndpointVectorEmpty())); // Enquanto nao temos nenhum cliente

	while(!(serverController->get_gameController()->stop)){
		for (auto remote_endpoint : serverController->get_endpointVector()){
			boost::asio::io_service my_io_service; // Conecta com o SO
			boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port); // endpoint: contem
								// conf. da conexao (ip/port)
			boost::asio::ip::udp::socket my_socket(my_io_service, // io service
					local_endpoint); // endpoint

			std::string message = serverController->get_gameController()->getStateJson().dump();
			std::cout<<"Mandando..."<<std::endl;
			my_socket.send_to(boost::asio::buffer( message), remote_endpoint);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
}
