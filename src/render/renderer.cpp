#include "renderer.h"

bool Renderer::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, nullptr);

    if (!renderer)
    {
        return false;
    }

    return true;
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 120, 255, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

void Renderer::shutdown()
{
    SDL_DestroyRenderer(renderer);
}