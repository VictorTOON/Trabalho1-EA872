#include "characterController.hpp"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta){
	this->view = std::shared_ptr<PersonagemView>(new PersonagemView(h, w, teta, "../assets/tree-character.png"));
	this->model = std::shared_ptr<PersonagemModel>(new PersonagemModel(x, y, h, w, teta));
}

void PersonagemController::updateView(){
	this->view->update(this->model->get_x(), this->model->get_y(), this->model->get_teta());
	this->view->draw();
	for (auto &axeController : this->axeControllers){
		axeController.second.updateView();
	}
}

std::shared_ptr<PersonagemView> PersonagemController::getView(){
	return this->view;
}

std::shared_ptr<PersonagemModel> PersonagemController::getModel(){
	return this->model;
}


void PersonagemController::iterate(){
	this->updateView();
}

std::unordered_map<std::string, AxeController> PersonagemController::get_axeControllers(){
    return axeControllers;
}

nlohmann::json PersonagemController::getStateJson(){
	nlohmann::json stateJson;
	return stateJson;

}

void PersonagemController::readStateJson(nlohmann::json stateJson) {
	this->model->readStateJson(stateJson["model"]);
	for (auto& machado: this->axeControllers){
        if (!stateJson[MAP_KEY_AXES].is_null()){
            if (stateJson[MAP_KEY_AXES].count(machado.first) > 0){
			    this->axeControllers.find(machado.first)->second.readStateJson(stateJson[MAP_KEY_AXES][machado.first]);	
		    } else {
			    this->axeControllers.erase(machado.first);
			    continue;
		        }
		    stateJson[MAP_KEY_AXES].erase(machado.first);
            }
	}
    if (!stateJson[MAP_KEY_AXES].is_null()){
        std::unordered_map<std::string, nlohmann::json> axesJson = stateJson[MAP_KEY_AXES];
        for (auto& pair_machadoJson: axesJson){
            nlohmann::json machadoJson = (nlohmann::json) pair_machadoJson.second;
            std::string machadoId = pair_machadoJson.first;
            AxeController axeController(machadoJson["model"]["base"]["x"], machadoJson["model"]["base"]["y"], machadoJson["model"]["base"]["teta"]);
            axeController.getView()->set_render(this->view->get_render());
            this->axeControllers.insert(std::make_pair(machadoId, axeController));
	    }
    }
}

