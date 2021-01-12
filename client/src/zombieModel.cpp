#include "zombieModel.hpp"

ZumbiModel::ZumbiModel(int x, int y, int h, int w, float teta):CorpoModel(x, y, h, w, teta){
}


#define GRAD_TO_RAD (3.14159265/180)
#define CONST_SPIN 0.1
ZumbiFollowReturn ZumbiModel::follow(std::shared_ptr<PersonagemModel> p){
	if (this->get_x() < p->get_x()){
		this->set_x(this->get_x() + PASSO * CONST_SPIN);
	} else if (this->get_x() > p->get_x()){
		this->set_x(this->get_x() - PASSO * CONST_SPIN);
	}
	if (this->get_y() < p->get_y()){
		this->set_y(this->get_y() + PASSO * CONST_SPIN);
	} else if (this->get_y() > p->get_y()){
		this->set_y(this->get_y() - PASSO * CONST_SPIN);
	}
	if (SDL_HasIntersection(this->get_rect(), p->get_rect()) == SDL_TRUE){
		p->set_health(p->get_health()-1);
		return CollisionPersonagem;
	}
	return DefaultFollow;

}

nlohmann::json ZumbiModel::getStateJson(){
	nlohmann::json stateJson;
	stateJson["base"] = this->baseJson();
	return stateJson;

}

void ZumbiModel::readStateJson(nlohmann::json state){
	this->readBaseJson(state["base"]);
}

