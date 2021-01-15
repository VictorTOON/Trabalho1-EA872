#include "sender.hpp"

void sender(std::shared_ptr<ClientController> clientController){
	static auto t_start = std::chrono::high_resolution_clock::now();
	static auto t_end = std::chrono::high_resolution_clock::now();
	while(!clientController->get_gameController()->stop){
		int action = clientController->get_gameController()->get_action();
		nlohmann::json request;
		request[JSON_KEY_TYPE] = JSON_TYPE_COMMAND;
		request[JSON_KEY_BODY][JSON_KEY_BODY_COMMAND] = action;
		clientController->get_socket()->send_to(boost::asio::buffer(request.dump()), *clientController->get_serverEndpoint());
		std::cout<<"Mandando..."<<std::endl;
		t_end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();

		if (elapsed < INT_DELAY_MS){
			std::this_thread::sleep_for(std::chrono::milliseconds(INT_DELAY_MS-elapsed));
		}
		t_start = t_end;
	}
	std::cout<<"Acabou ei"<<std::endl;
}


