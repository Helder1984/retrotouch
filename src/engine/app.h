#pragma once

//
// ======================================================
// Bibliotecas utilizadas
// ======================================================
//

//
// Renderer da engine.
// Responsável pela renderização.
//
#include "../render/renderer.h"

//
// Sistema de input.
// Responsável por teclado/mouse futuramente.
//
#include "../input/input.h"

//
// Sistema de scenes.
//
#include "../scenes/scene.h"

//
// Scene principal.
//
#include "../scenes/game_scene.h"

//
// Biblioteca principal SDL.
//
#include <SDL3/SDL.h>


//
// ======================================================
// Classe principal da aplicação
// ======================================================
//
// Responsável por:
//
// - inicialização da engine
// - loop principal
// - gerenciamento de entidades
// - update
// - render
// - shutdown
//
class App
{
public:

    //
    // ==================================================
    // init()
    // ==================================================
    // Inicializa todos os sistemas.
    //
    bool init();

    //
    // ==================================================
    // run()
    // ==================================================
    // Executa o loop principal.
    //
    void run();

    //
    // ==================================================
    // shutdown()
    // ==================================================
    // Finaliza corretamente a aplicação.
    //
    void shutdown();

    //
    // ==================================================
    // drawRect()
    // ==================================================
    // Método auxiliar para desenho.
    //
    // OBS:
    // Atualmente o renderer já possui drawRect().
    // Esse método provavelmente será removido futuramente.
    //
    void drawRect(float x, float y, int w, int h);

private:

    //
    // ==================================================
    // Estado da aplicação
    // ==================================================
    //

    //
    // Define se a aplicação continua rodando.
    //
    bool running = true;

    //
    // Ponteiro da janela SDL.
    //
    SDL_Window* window = nullptr;

    //
    // ==================================================
    // Sistemas principais da engine
    // ==================================================
    //

    //
    // Sistema de renderização.
    //
    Renderer renderer;

    //
    // Sistema de input.
    //
    Input input;

    //
    // Delta time do frame atual.
    //
    float deltaTime;

    //
    // Último tempo registrado.
    //
    Uint64 lastTime;

    //
    // ==================================================
    // Métodos internos da engine
    // ==================================================
    //

    //
    // Processa eventos SDL.
    //
    void processEvents();

    //
    // Atualiza lógica da aplicação.
    //
    void update(float deltaTime);

    //
    // Renderiza frame atual.
    //
    void render();

    //
    // ==================================================
    // Scene atual
    // ==================================================
    //
    // Scene ativa da engine.
    //
    Scene* currentScene = nullptr;

    //
    // ==================================================
    // GameScene principal
    // ==================================================
    //
    // Gameplay principal.
    //
    GameScene gameScene;
};