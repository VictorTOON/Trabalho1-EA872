#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "axeModel.h"
#include "axeView.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

class AxeController{
    private:
        std::shared_ptr<axeModel> axeModel;
        std::shared_ptr<axeView> axeView;
		std::unique_ptr<PersonagemView>
    public:
        void updateModelPosition(float tempo_pass, float tempo_atual);
        void updateViewPosition();
};