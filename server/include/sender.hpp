#include <thread>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <memory>

#include "serverController.hpp"

void sender( std::shared_ptr<ServerController> serverController, int port);
