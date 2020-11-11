#include "axeController.h"
#include <iostream>
#define speed 50

AxeController::AxeController(int x, int y, float teta){
    this->axeModel = std::shared_ptr<AxeModel>(new AxeModel(x, y, teta, speed));
    this->axeView = std::shared_ptr<AxeView>(new AxeView(50, 50, teta, (const char*) "../assets/axe.png"));
}

void AxeController::updateModel(float tempo_pass, float tempo_atual){
    this->axeModel->update_xy(tempo_pass, tempo_atual);
}

std::shared_ptr<AxeView> AxeController::getView(){
	return this->axeView;
}

void AxeController::updateView(){
    this->axeView->update(this->axeModel->get_x(), this->axeModel->get_y(), this->axeModel->get_teta());
    this->axeView->draw();
}
