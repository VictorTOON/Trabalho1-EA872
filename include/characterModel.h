#include "sdl_renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Personagem{
    private:
        int x, y, health;
        float teta;
    public:
        Personagem();
        int get_x();
        void set_x(int);
        int get_y();
        void set_y(int);
        float get_teta();
        void set_teta(float);
        int get_health();
        void set_health(int);
};