#pragma once

#include "../render/renderer.h"
#include "../input/input.h"
#include "../game/entity.h"
#include <SDL3/SDL.h>

class App
{
public:
    bool init();
    void run();
    void shutdown();
    void drawRect(float x, float y, int w, int h);

private:
    bool running = true;

    SDL_Window* window = nullptr;

    Renderer renderer;
    Input input;
    float deltaTime;
    Uint64 lastTime;
    Entity player;
};