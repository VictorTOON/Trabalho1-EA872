#include "characterController.hpp"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta){
	this->view = std::shared_ptr<PersonagemView>(new PersonagemView(h, w, teta, "../assets/tree-character.png"));
	this->model = std::shared_ptr<PersonagemModel>(new PersonagemModel(x, y, h, w, teta));
}

void PersonagemController::updateView(){
	this->view->update(this->model->get_x(), this->model->get_y(), this->model->get_teta());
	this->view->draw();
/*	for (auto axeController = this->axeControllers.begin(); axeController != this->axeControllers.end(); ++axeController){
		axeController->updateView();
	}*/
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

void PersonagemController::readStateJson(nlohmann::json state) {
	this->model->readStateJson(state["model"]);
	this->axeControllers.clear();
	for (int i_json = 0; i_json < state["machados"].size(); i_json++){
		AxeController axeController(0, 0, 0);		
		axeController.getView()->set_render(this->getView()->get_render());
		axeController.readStateJson(state["machados"][i_json]);
		this->axeControllers.push_back(axeController);
	}
}

