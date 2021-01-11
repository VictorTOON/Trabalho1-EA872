#include <thread>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <memory>

#include "serverController.hpp"

void sender(std::string ip, int port, std::shared_ptr<ServerController> serverController);
