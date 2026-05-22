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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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

void Renderer::drawRect(float x, float y, float w, float h)
{
    SDL_FRect rect;

    rect.x = x;
    rect.y = y;
    rect.w = (float)w;
    rect.h = (float)h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderFillRect(renderer, &rect);
}