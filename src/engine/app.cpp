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

    lastTime = SDL_GetTicks();

    running = true;

    return true;
}

void App::run()
{
    SDL_Event event;

    while (running)
    {
        Uint64 currentTime = SDL_GetTicks();

        deltaTime = (currentTime - lastTime) / 1000.0f;

        lastTime = currentTime;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        input.update();

        player.update(
            deltaTime,
            input.up,
            input.down,
            input.left,
            input.right
        );

        renderer.clear();

        renderer.drawRect(player.x, player.y, 50, 50);

        renderer.present();
    }
}

void App::shutdown()
{
    renderer.shutdown();

    SDL_DestroyWindow(window);

    SDL_Quit();
}