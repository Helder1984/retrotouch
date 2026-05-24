#pragma once

//
// ======================================================
// Bibliotecas utilizadas
// ======================================================
//

//
// std::vector
// Usado para armazenar múltiplas entidades.
//
#include <vector>

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
// Classe Entity.
// Representa objetos do jogo.
//
#include "../game/entity.h"

//
// Biblioteca principal SDL.
//
#include <SDL3/SDL.h>

//
// Controller responsável pelo jogador.
//
#include "../controllers/player_controller.h"

//
// Sistema de câmera.
//
#include "../camera/camera.h"

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
    // ==================================================
    // Sistema de tempo
    // ==================================================
    //

    //
    // ======================================================
    // Controllers
    // ======================================================
    //
    // Responsável por controlar o player.
    //
    // Arquitetura:
    //
    // Input
    //   ↓
    // PlayerController
    //   ↓
    // Entity
    //
    PlayerController playerController;

    //
    // ==================================================
    // Sistema de câmera
    // ==================================================
    //
    // Responsável por:
    //
    // - viewport
    // - scrolling
    // - world visualization
    //
    Camera camera;

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
    // Lista de entidades
    // ==================================================
    //
    // Armazena:
    // - player
    // - NPCs
    // - objetos
    // - futuras entidades do jogo
    //
    std::vector<Entity> entities;

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
};