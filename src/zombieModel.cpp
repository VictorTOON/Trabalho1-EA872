#include "zombieModel.h"

ZumbiModel::ZumbiModel(int x, int y, float teta):CorpoModel(x, y, teta){
}


#define GRAD_TO_RAD (3.14159265/180)
#define CONST_SPIN 0.1
void ZumbiModel::follow(PersonagemModel p){
	if (this->get_x() < p.get_x()){
		this->set_x(this->get_x() + PASSO * CONST_SPIN);
	} else if (this->get_x() > p.get_x()){
		this->set_x(this->get_x() - PASSO * CONST_SPIN);
	}
	if (this->get_y() < p.get_y()){
		this->set_y(this->get_y() + PASSO * CONST_SPIN);
	} else if (this->get_y() > p.get_y()){
		this->set_y(this->get_y() - PASSO * CONST_SPIN);
	}
}

