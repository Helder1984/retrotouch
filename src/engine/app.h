#pragma once

#include "../render/renderer.h"
#include "../input/input.h"

class App
{
public:
    bool init();
    void run();
    void shutdown();

private:
    bool running = true;

    SDL_Window* window = nullptr;

    Renderer renderer;
    Input input;
};