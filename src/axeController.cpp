#include "axeController.h"
#include <iostream>
#define speed 50

AxeController::AxeController(int x, int y, float teta){
    this->axeModel = std::shared_ptr<AxeModel>(AxeModel(x, y, teta, speed));
    this->axeView = std::shared_ptr<AxeView>(AxeView(50, 50, teta, "../assets/axe.png"));
}

void AxeController::updateModelPosition(float tempo_pass, float tempo_atual){
    axeModel.updatate_xy(tempo_pass, tempo_atual);
}

void updateViewPosition(int x, int y){
    axeView.update(int x, int y, teta);
}