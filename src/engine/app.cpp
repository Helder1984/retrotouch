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
    // Criação do Player
    // ==================================================
    //
    // Cria a entidade do jogador.
    // O player usa valores padrão definidos na Entity.
    //
    Entity player;
    //
    // Define tipo do player.
    //
    player.setType(EntityType::PLAYER);

    //
    // Adiciona o player ao vetor de entidades.
    //
    entities.push_back(player);

    //
    // ==================================================
    // Criação do NPC
    // ==================================================
    //
    Entity npc;

    //
    // Define tipo do player.
    //
    npc.setType(EntityType::NPC);

    //
    // Define posição do NPC na tela.
    //
    npc.setPosition(400, 200);

    //
    // Define a cor do NPC.
    // RGB:
    // 255,0,0 = vermelho
    //
    npc.setColor(255, 0, 0);

    //
    // Adiciona NPC ao vetor de entidades.
    //
    entities.push_back(npc);

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
// Finaliza corretamente todos os sistemas.
//
void App::shutdown()
{
    //
    // Finaliza renderer.
    //
    renderer.shutdown();

    //
    // Destrói janela SDL.
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
// Atualiza:
//
// - controllers
// - entidades
// - câmera
// - lógica do jogo
//
void App::update(float deltaTime)
{
    //
    // ==================================================
    // Atualiza controller do player
    // ==================================================
    //
    // entities[0]
    // → player principal
    //
    playerController.update(
        entities[0],
        input,
        deltaTime
    );

    //
    // ==================================================
    // Atualiza entidade do player
    // ==================================================
    //
    entities[0].update(deltaTime);

    //
    // ==================================================
    // Atualiza câmera
    // ==================================================
    //
    // Faz câmera seguir player.
    //
    camera.follow(
        entities[0].getX(),
        entities[0].getY()
    );


    //
    // ==================================================
    // Atualiza lógica interna da entidade
    // ==================================================
    //
    // Aqui futuramente entrarão:
    //
    // - animações
    // - física
    // - timers
    // - estados
    // - IA
    //
    entities[0].update(deltaTime);
}

//
// ======================================================
// App::render()
// ======================================================
// Responsável pela renderização do frame.
//
void App::render()
{
    //
    // Limpa tela.
    //
    renderer.clear();

//
// ==================================================
// Renderiza entidades ativas
// ==================================================
//
// Apenas entidades ativas:
//
// - atualizam
// - renderizam
//
for (auto& entity : entities)
{
    if (entity.isActive())
    {
        //
        // Renderiza entidade usando câmera.
        //
        entity.draw(
            renderer,
            camera
);
    }
}

    //
    // Apresenta frame final na tela.
    //
    renderer.present();
}