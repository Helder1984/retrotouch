#include "input.h"
#include <SDL3/SDL.h>

Input::Input()
{
    up = false;
    down = false;
    left = false;
    right = false;
}

void Input::update()
{
    const bool* keyboard = SDL_GetKeyboardState(NULL);

    up = keyboard[SDL_SCANCODE_W];
    down = keyboard[SDL_SCANCODE_S];
    left = keyboard[SDL_SCANCODE_A];
    right = keyboard[SDL_SCANCODE_D];
}