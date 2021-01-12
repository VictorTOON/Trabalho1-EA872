#include "characterController.hpp"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta){
	this->model = std::shared_ptr<PersonagemModel>(new PersonagemModel(x, y, h, w, teta));
	this->playerInput = Default;
	std::cout<<"Novo personagem criado"<<std::endl;
}

void PersonagemController::updateModel(){
			
	if (this->model->get_health() <= 0) {
		//return;
	}
	if (this->playerInput == CriaMachado){
		AxeController axeController(this->model->get_x(), this->model->get_y(), this->model->get_teta());
		this->axeControllers.push_back(axeController);
	}
	for (int i=0; i < axeControllers.size(); i++){
		retornoUpdateAxeController retornoUpdate = axeControllers[i].updateModel(0, .5);
		if (retornoUpdate == Destruir){
		    this->axeControllers.erase(axeControllers.begin() + i);
		    i--;
		}
	}
}


std::shared_ptr<PersonagemModel> PersonagemController::getModel(){
	return this->model;
}


void PersonagemController::iterate(){
	this->updateModel();
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
		axeController.readStateJson(state["machados"][i_json]);
		this->axeControllers.push_back(axeController);
	}
}

std::string PersonagemController::get_id(){
	return this->id;
}

void PersonagemController::set_id(std::string id){
	this->id = id;
}
