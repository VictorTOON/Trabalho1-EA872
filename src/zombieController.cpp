#include "zombieController.h"

ZumbiController::ZumbiController(int x, int y, int h, int w, float teta): model(x,y,h,w,teta) {
	this->view = std::shared_ptr<ZumbiView>(new ZumbiView(h, w, teta, "../assets/zombie.png"));
}

void ZumbiController::updateView(){
	this->view->update(this->model.get_x(), this->model.get_y(), this->model.get_teta());
	this->view->draw();
}

void ZumbiController::updateModel(PersonagemModel p){
	this->model.follow(p);
}

std::shared_ptr<ZumbiView> ZumbiController::getView(){
	return this->view;
}

ZumbiModel ZumbiController::getModel(){
	return this->model;
}


void ZumbiController::iterate(PersonagemModel p){
	this->updateModel(p);
	this->updateView();
}
