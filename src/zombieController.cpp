#include "zombieController.hpp"

ZumbiController::ZumbiController(int x, int y, int h, int w, float teta, std::string player_id): model(x,y,h,w,teta) {
	this->id = ID_CONTROLLER++;
    this->player_id = player_id;
}

std::string ZumbiController::get_id(){
	return std::to_string(this->id);
}

std::string ZumbiController::get_player_id(){
    return this->player_id;
}

void ZumbiController::updateModel(std::shared_ptr<PersonagemModel> p){
	this->model.follow(p);
}

ZumbiModel ZumbiController::getModel(){
	return this->model;
}


void ZumbiController::iterate(std::shared_ptr<PersonagemModel> p){
	this->updateModel(p);
}

nlohmann::json ZumbiController::getStateJson(){
	nlohmann::json stateJson;
	stateJson["id"] = this->id;
	stateJson["model"] = this->model.getStateJson();
	return stateJson;

}
void ZumbiController::readStateJson(nlohmann::json state){
	std::cout<<state<<std::endl;
	this->id = state["id"];
	this->model.readStateJson(state["model"]);
}


