#include "app.h"
#include <SDL3/SDL.h>

//
// Ponteiro global da janela principal da aplicação.
// A SDL usa SDL_Window como representação da janela.
//
SDL_Window* window = nullptr;

//
// ======================================================
// App::init()
// ======================================================
// Responsável por inicializar toda a aplicação.
//
// Aqui fazemos:
// - Inicialização da SDL
// - Criação da janela
// - Inicialização do renderer
// - Criação das entidades iniciais
// - Inicialização do sistema de tempo
//
bool App::init()
{
    //
    // Inicializa o subsistema de vídeo da SDL.
    // Sem isso nada gráfico funciona.
    //
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return false;
    }

    //
    // Cria a janela principal da aplicação.
    //
    window = SDL_CreateWindow(
        "RetroTouch", // título da janela
        800,          // largura
        600,          // altura
        0             // flags
    );

    //
    // Verifica se a janela foi criada corretamente.
    //
    if (!window)
    {
        return false;
    }

    //
    // Inicializa o sistema de renderização.
    //
    if (!renderer.init(window))
    {
        return false;
    }

    //
    // ==================================================
    // Configura gameplay principal
    // ==================================================
    //
    // Injeta:
    //
    // - renderer
    // - input
    //
    gameScene.setRenderer(&renderer);

    gameScene.setInput(&input);

    //
    // Define sistema multitouch.
    //
    gameScene.setTouchManager(
        &touchManager
    );

    //
    // Scene atual.
    //
    currentScene = &gameScene;

    //
    // Inicializa scene.
    //
    currentScene->init();

    //
    // Inicializa o sistema de tempo.
    // Salva o tick atual para cálculo de deltaTime.
    //
    lastTime = SDL_GetTicks();

    //
    // Define a aplicação como rodando.
    //
    running = true;

    return true;
}

//
// ======================================================
// App::run()
// ======================================================
// Loop principal da aplicação.
//
// Responsável por:
// - calcular deltaTime
// - processar eventos
// - atualizar lógica
// - renderizar
//
void App::run()
{
    //
    // Loop principal da engine.
    //
    while (running)
    {
        //
        // Obtém tempo atual.
        //
        Uint64 currentTime = SDL_GetTicks();

        //
        // Calcula deltaTime em segundos.
        //
        deltaTime = (currentTime - lastTime) / 1000.0f;

        //
        // Atualiza último frame.
        //
        lastTime = currentTime;

        //
        // Processa eventos da SDL.
        //
        processEvents();

        //
        // Atualiza lógica do jogo.
        //
        update(deltaTime);

        //
        // Renderiza o frame.
        //
        render();
    }
}

//
// ======================================================
// App::shutdown()
// ======================================================
//
// Finaliza:
//
// - scene
// - renderer
// - SDL
//
void App::shutdown()
{
    //
    // Finaliza scene atual.
    //
    currentScene->shutdown();

    //
    // Finaliza renderer.
    //
    renderer.shutdown();

    //
    // Destrói janela.
    //
    SDL_DestroyWindow(window);

    //
    // Finaliza SDL.
    //
    SDL_Quit();
}

//
// ======================================================
// App::processEvents()
// ======================================================
// Processa:
// - teclado
// - mouse
// - fechamento da janela
// - eventos do sistema
//
void App::processEvents()
{
    //
    // Atualiza estado do input.
    //
    input.update();

    SDL_Event event;

    //
    // Processa fila de eventos da SDL.
    //
    while (SDL_PollEvent(&event))
    {
        //
        // ==================================================
        // Processa touch
        // ==================================================
        touchManager.processEvent(event);
        //
        // Evento de fechamento da janela.
        //
        if (event.type == SDL_EVENT_QUIT)
        {
            running = false;
        }
    }

}

//
// ======================================================
// App::update()
// ======================================================
//
// Atualiza scene atual.
//
void App::update(float deltaTime)
{
    //
    // Atualiza scene ativa.
    //
    currentScene->update(deltaTime);
}

//
// ======================================================
// App::render()
// ======================================================
//
// Renderiza:
//
// - limpa tela
// - scene atual
// - apresenta frame
//
void App::render()
{
    //
    // Limpa frame atual.
    //
    renderer.clear();

    //
    // Renderiza scene ativa.
    //
    currentScene->render();

    //
    // Apresenta frame.
    //
    renderer.present();
}
