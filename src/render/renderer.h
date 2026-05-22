#pragma once

#include <SDL3/SDL.h>

class Renderer
{
public:
    bool init(SDL_Window* window);

    void clear();
    void present();

    void drawRect(float x, float y, float w, float h);

    void shutdown();
    
private:
    SDL_Renderer* renderer = nullptr;
};