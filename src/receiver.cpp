#include "receiver.hpp"

void receiver(int port, GameController *gameController) {
	char clean[10000];
	int i;
	for (i = 0; i < 10000; i++){
		clean[i] = '\0';
	}
	char v[10000];
	while (1){
		strcpy(v, clean);

		boost::asio::io_service my_io_service; // Conecta com o SO

		boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port); // endpoint: contem
							// conf. da conexao (ip/port)

		boost::asio::ip::udp::socket my_socket(my_io_service, // io service
				local_endpoint); // endpoint

		boost::asio::ip::udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

		std::cout << "Esperando mensagem!" << std::endl;

		my_socket.receive_from(boost::asio::buffer(v,10000), // Local do buffer
			      remote_endpoint); // Confs. do Cliente

		gameController->readServerStateJson(nlohmann::json::parse(v));
		std::cout << v << std::endl;
		std::cout << "Fim de mensagem!" << std::endl;

		// Respondendo a mensagem
		std::string msg("Recebido! Obrigado, cambio e desligo!");
		my_socket.send_to(boost::asio::buffer(msg), remote_endpoint);

		std::cout << "Mensagem de retorno enviada" << std::endl;
	}

} 



