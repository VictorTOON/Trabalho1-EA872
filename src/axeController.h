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

typedef enum{
    Destruir,
    Manter,
}retornoUpdateAxeController;

class AxeController{
    private:
        std::shared_ptr<AxeModel> axeModel;
        std::shared_ptr<AxeView> axeView;
        float tempoVida;
    public:
        AxeController(int x, int y, float teta);
        retornoUpdateAxeController updateModel(float tempo_pass, float tempo_atual);
        void updateView();
	std::shared_ptr<AxeView> getView();
};
