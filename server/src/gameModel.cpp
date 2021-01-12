#include "gameModel.hpp"

statusZumbi GameModel::checkIntersection(AxeModel machado, ZumbiModel zumbi){
    if (SDL_HasIntersection(machado.get_rect(), zumbi.get_rect())){
        return Mata;
    }
    return Mantem;
}

