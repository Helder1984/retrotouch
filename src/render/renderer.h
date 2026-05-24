#pragma once

//
// ======================================================
// Biblioteca SDL
// ======================================================
//
// Utilizada para:
//
// - janela
// - renderização
// - eventos
// - input
// - tempo
//
#include <SDL3/SDL.h>

//
// Sistema de câmera.
//
#include "../camera/camera.h"

//
// ======================================================
// Classe Renderer
// ======================================================
//
// Responsável pelo sistema de renderização da engine.
//
// O Renderer controla:
//
// - limpeza da tela
// - desenho de formas
// - apresentação do frame
// - gerenciamento do SDL_Renderer
//
// Futuramente poderá incluir:
//
// - texturas
// - sprites
// - animações
// - câmera
// - shaders
// - layers
// - tilemaps
//
class Renderer
{
public:

    //
    // ==================================================
    // init()
    // ==================================================
    //
    // Inicializa o sistema de renderização.
    //
    // Cria o SDL_Renderer associado à janela.
    //
    bool init(SDL_Window* window);

    //
    // ==================================================
    // clear()
    // ==================================================
    //
    // Limpa a tela antes da renderização.
    //
    void clear();

    //
    // ==================================================
    // present()
    // ==================================================
    //
    // Apresenta o frame final na tela.
    //
    // Tudo desenhado só aparece após esse método.
    //
    void present();

    //
    // ==================================================
    // drawRect()
    // ==================================================
    //
    // Desenha um retângulo usando:
    //
    // - posição do mundo
    // - offset da câmera
    //
    // Isso permite:
    //
    // world space
    // ↓
    // screen space
    //
    void drawRect(
        float worldX,
        float worldY,
        int w,
        int h,
        Uint8 r,
        Uint8 g,
        Uint8 b,
        Camera& camera
    );

    //
    // ==================================================
    // shutdown()
    // ==================================================
    //
    // Finaliza corretamente o renderer.
    //
    void shutdown();

private:

    //
    // ==================================================
    // SDL_Renderer
    // ==================================================
    //
    // Objeto principal de renderização da SDL.
    //
    // Responsável por:
    //
    // - desenhar
    // - limpar tela
    // - renderizar formas
    // - renderizar texturas
    //
    SDL_Renderer* renderer = nullptr;
};