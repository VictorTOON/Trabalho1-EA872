#include <iostream>
#include <string>
#include <boost/asio.hpp>


using boost::asio::ip::udp;

int main() {
  std::string v("Ola, mundo, mundo, vasto mundo!");

  boost::asio::io_service io_service;

  udp::endpoint local_endpoint(udp::v4(), 0);
  udp::socket meu_socket(io_service, local_endpoint);


  // Encontrando IP remoto
  boost::asio::ip::address ip_remoto =
    boost::asio::ip::address::from_string("25.6.123.125");

  udp::endpoint remote_endpoint(ip_remoto, 9001);

  meu_socket.send_to(boost::asio::buffer(v), remote_endpoint);

  // Recebendo mensagem de retorno
  char recv[122];
  meu_socket.receive_from(boost::asio::buffer(recv, 122), remote_endpoint);

  return 0;
}
