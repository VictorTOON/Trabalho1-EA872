#include "characterModel.h"

Personagem::Personagem(int x, int y, float teta): Corpo(x, y, teta){
}


#define GRAD_TO_RAD (3.14159265/180)
void Personagem::handle_keyboard(int entry){
	
	if (entry & (1 << KEYBOARD_UP)){
			this->set_x(this->get_x()+PASSO * cos(this->get_teta() * (GRAD_TO_RAD)));
			this->set_y(this->get_y()+PASSO * sin(this->get_teta() * (GRAD_TO_RAD))); 
			if (this->get_x() < 0) this->set_x(0);
			if (this->get_y() < 0) this->set_y(0);
	}
	if (entry & (1 << KEYBOARD_DOWN)){
			this->set_x(this->get_x()-PASSO * cos(this->get_teta() * (GRAD_TO_RAD)));
			this->set_y(this->get_y()-PASSO * sin(this->get_teta() * (GRAD_TO_RAD))); 
			if (this->get_x() < 0) this->set_x(0);
			if (this->get_y() < 0) this->set_y(0);
	}
	if (entry & (1 << KEYBOARD_LEFT)){
			this->update_teta(-PASSO_TETA); 
	}
	if (entry & (1 << KEYBOARD_RIGHT)){
			this->update_teta(PASSO_TETA); 
	}
}

