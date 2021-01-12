#include "sender.hpp"

void sender(std::string ip, int port, GameController *gameController){
	while(!gameController->stop){
		boost::asio::io_service my_io_service; // Conecta com o SO
		boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port); 
							// conf. da conexao (ip/port)
		boost::asio::ip::udp::socket my_socket(my_io_service, // io service
				local_endpoint); // endpoint
		// Encontrando IP remoto
		boost::asio::ip::address ip_remoto = boost::asio::ip::address::from_string(ip);

		boost::asio::ip::udp::endpoint remote_endpoint(ip_remoto, port);

		std::string message = gameController->getStateJson().dump();
		my_socket.send_to(boost::asio::buffer( message), remote_endpoint);
		std::cout<<"Mandando..."<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}


