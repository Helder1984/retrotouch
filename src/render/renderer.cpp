#include "renderer.h"

//
// ======================================================
// Renderer::init()
// ======================================================
//
// Inicializa o sistema de renderização.
//
// Cria o SDL_Renderer responsável por:
//
// - desenhar formas
// - desenhar texturas
// - limpar a tela
// - apresentar frames
//
bool Renderer::init(SDL_Window* window)
{
    //
    // Cria renderer associado à janela.
    //
    renderer = SDL_CreateRenderer(window, nullptr);

    //
    // Verifica se renderer foi criado corretamente.
    //
    if (!renderer)
    {
        return false;
    }

    return true;
}

//
// ======================================================
// Renderer::clear()
// ======================================================
//
// Limpa a tela antes da renderização.
//
// SDL_SetRenderDrawColor():
// define a cor usada pelo renderer.
//
// RGB:
// 0,0,0 = preto
//
void Renderer::clear()
{
    //
    // Define cor de limpeza da tela.
    //
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //
    // Limpa o frame atual.
    //
    SDL_RenderClear(renderer);
}

//
// ======================================================
// Renderer::present()
// ======================================================
//
// Apresenta o frame final na tela.
//
// Tudo desenhado pelo renderer só aparece
// após SDL_RenderPresent().
//
void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

//
// ======================================================
// Renderer::shutdown()
// ======================================================
//
// Finaliza corretamente o renderer.
//
void Renderer::shutdown()
{
    SDL_DestroyRenderer(renderer);
}

//
// ======================================================
// Renderer::drawRect()
// ======================================================
//
// Desenha retângulo no mundo.
//
// A câmera converte:
//
// world coordinates
// ↓
// screen coordinates
//
void Renderer::drawRect(
    float worldX,
    float worldY,
    int w,
    int h,
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Camera& camera
    )
{
    //
    // Estrutura de retângulo da SDL.
    //
    SDL_FRect rect;

    //
    // ==================================================
    // Conversão world → screen
    // ==================================================
    //
    // Remove offset da câmera.
    //
    // Isso cria:
    //
    // scrolling
    // viewport
    // world rendering
    //
    rect.x = worldX - camera.getX();

    rect.y = worldY - camera.getY();

    //
    // Define tamanho do retângulo.
    //
    rect.w = (float)w;
    rect.h = (float)h;

    //
    // Define cor de desenho.
    //
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    //
    // Desenha retângulo preenchido.
    //
    SDL_RenderFillRect(renderer, &rect);
}
 
//
    // ======================================================
    // Renderer::drawScreenRect()
    // ======================================================
    //
    // Desenha diretamente na tela.
    //
    // IMPORTANTE:
    //
    // NÃO usa câmera.
    //
    // Isso é:
    //
    // SCREEN SPACE
    //
void Renderer::drawScreenRect(
    float x,
    float y,
    int w,
    int h,
    Uint8 r,
    Uint8 g,
    Uint8 b
)
{
    //
    // Retângulo SDL.
    //
    SDL_FRect rect;

    //
    // Posição na tela.
    //
    rect.x = x;
    rect.y = y;

    //
    // Tamanho.
    //
    rect.w = (float)w;
    rect.h = (float)h;

    //
    // Cor do overlay.
    //
    SDL_SetRenderDrawColor(
        renderer,
        r,
        g,
        b,
        255
    );

    //
    // Renderiza na tela.
    //
    SDL_RenderFillRect(renderer, &rect);
}
    