#include "app.h"
#include <SDL3/SDL.h>

SDL_Window* window = nullptr;

bool App::init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return false;
    }

    window = SDL_CreateWindow(
        "RetroTouch",
        800,
        600,
        0
    );

    if (!window)
    {
        return false;
    }

    if (!renderer.init(window))
    {
        return false;
    }

    return true;
}

void App::run()
{
    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        renderer.clear();

        renderer.present();

        SDL_Delay(16);
    }

    shutdown();
}

void App::shutdown()
{
    renderer.shutdown();

    SDL_DestroyWindow(window);

    SDL_Quit();
}