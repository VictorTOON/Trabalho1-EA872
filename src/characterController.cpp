#include "characterController.h"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta): model(x,y,teta) {
	this->view = std::shared_ptr<PersonagemView>(new PersonagemView(h, w, teta, "../assets/tree-character.png"));
}

void PersonagemController::updateView(){
	this->view->update(this->model.get_x(), this->model.get_y(), this->model.get_teta());
	this->view->draw();
}

void PersonagemController::updateModel(){
	this->model.handle_keyboard(this->keyboardHandler.getInput());
}

std::shared_ptr<PersonagemView> PersonagemController::getView(){
	return this->view;
}

PersonagemModel PersonagemController::getModel(){
	return this->model;
}


void PersonagemController::iterate(){
	this->updateModel();
	this->updateView();
}
