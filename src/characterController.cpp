#include "characterController.h"

PersonagemController::PersonagemController(int x, int y, int h, int w, float teta): model(x,y,teta) {
	this->view = std::shared_ptr<PersonagemView>(new PersonagemView(h, w, teta, "../assets/tree-character.png"));
}

void PersonagemController::updateView(){
	this->view->update(this->model.get_x(), this->model.get_y(), this->model.get_teta());
	this->view->draw();
	for (auto axeController = this->axeControllers.begin(); axeController != this->axeControllers.end(); ++axeController){
		axeController->updateView();
	}
}

void PersonagemController::updateModel(){
	RetornoHandle ret = this->model.handle_keyboard(this->keyboardHandler.getInput());
	if (ret == CriaMachado){
		AxeController axe(50, 50, this->model.get_teta());
		axe.getView()->set_render(this->getView()->get_render());
		this->axeControllers.push_back(axe);		
		
	}

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
