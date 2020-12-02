#pragma once

#define KEYBOARD_FORCE 10

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

typedef enum {
	KEYBOARD_UP=1,
	KEYBOARD_DOWN,
	KEYBOARD_LEFT,
	KEYBOARD_RIGHT,
	KEYBOARD_SPACE,
	KEYBOARD_ZERO,
    KEYBORAD_P
} KeyBoardReturns;

/*! \brief Classe para lidar com as entradas do teclado
 *
 *	Classe que lida com as entradas do teclado, possui uma variavel interna, state,
 *	que tera o valor retornado pela funcao do SDL que obtem o valor das teclas a 
 *	serem pressionadas (SDL_Get_Keyboard_State)
 * */
class SDL_Keyboard_Handler{
	private:
	       	const Uint8* state;
	public:
		/*! \brief Construtor
		 *
		 * Coloca state para receber o endereço da variavel que mapeia as entradas de teclado
		 * */
		SDL_Keyboard_Handler();
		/* \brief Funcao que trata o inpu
		 *
		 * Interpreta os valores de state
		 *
		 * \return Retorna um numero feito por operacoes bitwise, para 
		 * assim podermos ter informacoes de mais de uma entrada de uma vez
		 * */
		int getInput();
};
