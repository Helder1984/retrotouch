#include "input.h"
#include <SDL3/SDL.h>

//
// ======================================================
// Input::Input()
// ======================================================
//
// Construtor do sistema de input.
//
// Inicializa todos os estados do teclado como:
//
// false = tecla não pressionada
//
Input::Input()
{
    //
    // Movimento para cima.
    //
    up = false;

    //
    // Movimento para baixo.
    //
    down = false;

    //
    // Movimento para esquerda.
    //
    left = false;

    //
    // Movimento para direita.
    //
    right = false;

    //
    // Mouse.
    //
    mouseLeft = false;

    mouseX = 0;
    mouseY = 0;
}

//
// ======================================================
// Input::update()
// ======================================================
//
// Atualiza o estado atual do teclado.
//
// SDL_GetKeyboardState():
// retorna um array contendo o estado de todas as teclas.
//
// true  = tecla pressionada
// false = tecla solta
//
void Input::update()
{
    //
    // Obtém estado atual do teclado.
    //
    const bool* keyboard = SDL_GetKeyboardState(NULL);

    //
    // Atualiza tecla W.
    // Movimento para cima.
    //
    up = keyboard[SDL_SCANCODE_W];

    //
    // Atualiza tecla S.
    // Movimento para baixo.
    //
    down = keyboard[SDL_SCANCODE_S];

    //
    // Atualiza tecla A.
    // Movimento para esquerda.
    //
    left = keyboard[SDL_SCANCODE_A];

    //
    // Atualiza tecla D.
    // Movimento para direita.
    //
    right = keyboard[SDL_SCANCODE_D];

    //
    // ==================================================
    // Mouse state
    // ==================================================
    //
    // Captura estado do mouse.
    //
    SDL_MouseButtonFlags mouseState =
        SDL_GetMouseState(
            &mouseX,
            &mouseY
        );

    //
    // Clique esquerdo.
    //
    mouseLeft =
        mouseState & SDL_BUTTON_LMASK;
    }