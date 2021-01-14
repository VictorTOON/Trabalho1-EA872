#include "characterController.hpp"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta){
	this->view = std::shared_ptr<PersonagemView>(new PersonagemView(h, w, teta, "../assets/tree-character.png"));
	this->model = std::shared_ptr<PersonagemModel>(new PersonagemModel(x, y, h, w, teta));
}

void PersonagemController::updateView(){
	this->view->update(this->model->get_x(), this->model->get_y(), this->model->get_teta());
	this->view->draw();
	for (auto axeController = this->axeControllers.begin(); axeController != this->axeControllers.end(); ++axeController){
		axeController->updateView();
	}
    // if (this->axeControllers.size() > 0){
    //     this->axeControllers[0].updateView();
    // }
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

std::vector<AxeController> PersonagemController::get_axeControllers(){
    return axeControllers;
}

nlohmann::json PersonagemController::getStateJson(){
	nlohmann::json stateJson;
	stateJson["model"] = this->model->getStateJson();
	std::vector<nlohmann::json> axesJsons;
	for (auto a = this->axeControllers.begin(); a != this->axeControllers.end(); ++a){
		axesJsons.push_back(a->getStateJson());
	}
	stateJson["machados"] = axesJsons;
	return stateJson;

}

void PersonagemController::readStateJson(nlohmann::json stateJson) {
	this->model->readStateJson(stateJson["model"]);
	for (auto& machado: this->axeControllers){
		if (stateJson[MAP_KEY_AXES].count(machado.first) > 0){
			this->axeControllers.find(machado.first)->second.readStateJson(stateJson[MAP_KEY_AXES]);	
		} else {
			this->axeControllers.erase(machado.first);
			continue;
		}
		stateJson[MAP_KEY_AXES].erase(machado.first);
	}
}

