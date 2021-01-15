#include "zombieController.hpp"

ZumbiController::ZumbiController(int x, int y, int h, int w, float teta): model(x,y,h,w,teta) {
	this->view = std::shared_ptr<ZumbiView>(new ZumbiView(h, w, teta, "../assets/zombie.png"));
}

void ZumbiController::set_player_id(std::string player_id){
	this->player_id = player_id;
}

std::string ZumbiController::get_player_id(){
	return this->player_id;
}

void ZumbiController::set_id(std::string id){
	this->id = id;
}

std::string ZumbiController::get_id(){
	return this->id;
}

void ZumbiController::updateView(std::shared_ptr<PersonagemModel> p){
	float arc = 0;
	float angle = 0;
	if (this->model.get_x() != p->get_x()){
		arc = (this->model.get_y() - p->get_y())/(this->model.get_x() - p->get_x());
		angle = (atan (arc) * (180/3.14159265));
		if (this->model.get_x() > p->get_x()){
			angle = angle + 180;
		}
	}else{
		angle = 0;	
	}
	this->view->update(this->model.get_x(), this->model.get_y(), angle);
	this->view->draw();
}

void ZumbiController::updateModel(std::shared_ptr<PersonagemModel> p){
	this->model.follow(p);
}

std::shared_ptr<ZumbiView> ZumbiController::getView(){
	return this->view;
}

ZumbiModel ZumbiController::getModel(){
	return this->model;
}


void ZumbiController::iterate(std::shared_ptr<PersonagemModel> p){
	this->updateView(p);
}

ZumbiModel ZumbiController::get_model(){
    return model;
}
nlohmann::json ZumbiController::getStateJson(){
	nlohmann::json stateJson;
	stateJson["id"] = this->id;
	stateJson["model"] = this->model.getStateJson();
	return stateJson;

}
void ZumbiController::readStateJson(nlohmann::json state){
	this->model.readStateJson(state[this->id]["model"]);

}
