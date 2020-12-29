#include "sender.hpp"

void Sender::send(std::string ip, int port, GameController &gameController){
    nlohmann::json j = gameController.getStateJson();
    boost::asio::io_service my_io_service; // Conecta com o SO
    boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port); // endpoint: contem
                                                // conf. da conexao (ip/port)
    boost::asio::ip::udp::socket my_socket(my_io_service, // io service
                        local_endpoint); // endpoint
      // Encontrando IP remoto
    boost::asio::ip::address ip_remoto = boost::asio::ip::address::from_string(ip);

    boost::asio::ip::udp::endpoint remote_endpoint(ip_remoto, port);
    
    std::string msg("Recebido! Obrigado, cambio e desligo!");
    my_socket.send_to(boost::asio::buffer(j.dump()), remote_endpoint);
}
