#include "characterModel.hpp"

PersonagemModel::PersonagemModel(int x, int y, int h, int w, float teta): CorpoModel(x, y, h, w, teta){
	this->tempo = 0;
	this->tempoComparado = SDL_GetTicks();
}

bool PersonagemModel::isDead(){
	return (this->get_health() <= 0);
}

#define GRAD_TO_RAD (3.14159265/180)
RetornoHandle PersonagemModel::handle_keyboard(int entry){
	if (this->get_health() <= 0){
		return Default;
	}
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
	if (entry & (1 << KEYBOARD_SPACE)){
		this->tempoComparado = SDL_GetTicks();
		if (tempoComparado - tempo > 400){
			this->tempo = SDL_GetTicks();
			return CriaMachado;
		}
	}
	return Default;
}

nlohmann::json PersonagemModel::getStateJson(){
	nlohmann::json stateJson;
	stateJson["base"] = this->baseJson();
	return stateJson;

}
