#include "axeController.hpp"
#include <iostream>
#define speed 30
#define vida 20


AxeController::AxeController(int x, int y, float teta){
    this->axeModel = std::shared_ptr<AxeModel>(new AxeModel(x, y, teta, 50, 50, speed));
    this->axeView = std::shared_ptr<AxeView>(new AxeView(50, 50, teta, (const char*) "../assets/axe.png"));
    this->tempoVida = 0;
}

retornoUpdateAxeController AxeController::updateModel(float tempo_pass, float tempo_atual){
    if (tempoVida > vida){
        return Destruir;
    }
    this->axeModel->update_xy(tempo_pass, tempo_atual);
    this->tempoVida = this->tempoVida + (tempo_atual - tempo_pass);
    return Manter;
}

std::shared_ptr<AxeView> AxeController::getView(){
	return this->axeView;
}

void AxeController::updateView(){
    this->axeView->update(this->axeModel->get_x(), this->axeModel->get_y(), this->axeView->get_angle());
    this->axeView->updateAngle(12);
    this->axeView->draw();
}

std::shared_ptr<AxeModel> AxeController::get_axeModel(){
    return axeModel;
}
nlohmann::json AxeController::getStateJson() {
	nlohmann::json stateJson;
	stateJson["model"] = this->axeModel->getStateJson();
	stateJson["angleView"] = this->axeView->get_angle();
	return stateJson;
}
