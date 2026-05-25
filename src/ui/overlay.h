#pragma once

#include "../render/renderer.h"

//
// ======================================================
// Classe Overlay
// ======================================================
//
// Classe base para:
//
// - HUD
// - touch controls
// - menus
// - overlays contextuais
//
// IMPORTANTE:
//
// Overlay usa:
//
// SCREEN SPACE
//
// E NÃO:
//
// WORLD SPACE
//
// Portanto:
//
// - NÃO usa câmera
// - NÃO move com scrolling
//
// ======================================================

class Overlay
{
public:

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza lógica do overlay.
    //
    virtual void update(float deltaTime) = 0;

    //
    // ==================================================
    // render()
    // ==================================================
    //
    // Renderiza overlay na tela.
    //
    virtual void render(Renderer& renderer) = 0;

    //
    // Destructor virtual.
    //
    virtual ~Overlay() {}
};