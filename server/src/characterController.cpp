#include "characterController.hpp"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta){
	this->model = std::shared_ptr<PersonagemModel>(new PersonagemModel(x, y, h, w, teta));
	this->playerInput = Default;
	std::cout<<"Novo personagem criado"<<std::endl;
	std::queue<int> fila_acoes;
}

void PersonagemController::updateModel(){
    while ((fila_acoes.size()) > 0){
	    RetornoHandle ret = this->model->handle_keyboard(fila_acoes.front());
        if (this->model->get_health() <= 0) {
	
        }
        if (ret == CriaMachado){
            AxeController axeController(this->model->get_x(), this->model->get_y(), this->model->get_teta());
            this->axeControllers.insert(std::make_pair(axeController.get_id(), axeController));
        }
        fila_acoes.pop();
    }
    std::vector<std::string> destroyKeys;
    for (auto axeController = this->axeControllers.begin(); axeController != this->axeControllers.end(); ++axeController){
            retornoUpdateAxeController retornoUpdate = axeController->second.updateModel(0, .5);
            if (retornoUpdate == Destruir){
                destroyKeys.push_back(axeController->first);
	    }
    }
    for (auto destroyKey : destroyKeys){
    	this->axeControllers.erase(destroyKey);
    }
}

std::shared_ptr<PersonagemModel> PersonagemController::getModel(){
	return this->model;
}


void PersonagemController::iterate(){
	this->updateModel();
}

std::unordered_map<std::string, AxeController> PersonagemController::get_axeControllers(){
    return this->axeControllers;
}

nlohmann::json PersonagemController::getStateJson(){
	nlohmann::json stateJson;
	stateJson["model"] = this->model->getStateJson();
	nlohmann::json axesJson;
	for (auto &axeController : this->axeControllers){
		axesJson[axeController.first] = axeController.second.getStateJson();
	}
	stateJson["machados"] = axesJson;
	return stateJson;

}

std::string PersonagemController::get_id(){
	return this->id;
}

void PersonagemController::set_id(std::string id){
	this->id = id;
}

void PersonagemController::addTo_fila_acoes(int acao){
	this->fila_acoes.push(acao);
}
