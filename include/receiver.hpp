#include "gameController.hpp"
#include "serverController.hpp"

#include <thread>
#include <string>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

void receiver(int port, ServerController *serverController);
