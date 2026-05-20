#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    // Inicializa SDL
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL could not initialize!\n";
        return 1;
    }

    // Cria janela
    SDL_Window* window = SDL_CreateWindow(
        "RetroTouch Prototype",
        800,
        600,
        0
    );

    if (!window)
    {
        std::cout << "Window could not be created!\n";
        return 1;
    }

    bool running = true;
    SDL_Event event;

    // Loop principal
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            // Fechar janela
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }

            // Clique do mouse
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                std::cout << "Mouse clicked!" << std::endl;
            }
        }

        SDL_Delay(16);
    }

    // Limpeza
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}