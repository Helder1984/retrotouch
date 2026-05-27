#pragma once

#include "overlay.h"
#include "../input/input.h"
#include "../virtual_input/virtual_input.h"
#include "../touch/touch_manager.h"

//
// ======================================================
// Classe TouchButton
// ======================================================
//
// Representa:
//
// - botão virtual
// - botão touch
// - overlay interativo
//
// Usa:
//
// SCREEN SPACE
//
// ======================================================

class TouchButton : public Overlay
{
public:

    //
    // Constructor.
    //
    TouchButton();

    //
    // Atualiza botão.
    //
    void update(float deltaTime) override;

    //
    // Renderiza botão.
    //
    void render(Renderer& renderer) override;

    //
    // Define input do botão.
    //
    void setInput(Input* newInput);

    //
    // Define virtual input.
    //
    void setVirtualInput(
        VirtualInput* newVirtualInput
    );

    //
    // Define botão virtual.
    //
    void setVirtualButton(
        VirtualButton newButton
    );

    //
    // Define TouchManager.
    //
    void setTouchManager(
        TouchManager* newTouchManager
    );

    //
    // ==================================================
    // Configuração visual
    // ==================================================
    //
    // Define posição.
    //
    void setPosition(
        float newX,
        float newY
    );

    //
    // Define tamanho.
    //
    void setSize(
        int newWidth,
        int newHeight
    );

    //
    // Define cor.
    //
    void setColor(
        Uint8 newR,
        Uint8 newG,
        Uint8 newB
    );

    //
    // ==================================================
    // Drag update
    // ==================================================
    //
    // Atualiza movimentação
    // do botão.
    //
    void updateDrag();

    //
    // Retorna posição X.
    //
    float getX();

    //
    // Retorna posição Y.
    //
    float getY();

private:

    //
    // ==================================================
    // Transform
    // ==================================================
    //
    // Posição.
    //
    float x = 0.0f;

    float y = 0.0f;

    //
    // Tamanho.
    //
    int width = 100;

    int height = 100;

    //
    // ==================================================
    // Cor
    // ==================================================
    //
    Uint8 r = 255;

    Uint8 g = 255;

    Uint8 b = 255;
    //
    // Sistema de input.
    //
    Input* input = nullptr;

    //
    // Estado do botão.
    //
    bool isPressed;

    //
    // Sistema de virtual input.
    //
    VirtualInput* virtualInput = nullptr;

    //
    // Botão virtual associado.
    //
    VirtualButton virtualButton =
        VirtualButton::NONE;

    //
    // Sistema multitouch.
    //
    TouchManager* touchManager = nullptr;

    //
    // ==================================================
    // Drag state
    // ==================================================
    //
    // Botão sendo arrastado.
    //
    bool dragging = false;

    //
    // Offset do clique.
    //
    float dragOffsetX = 0.0f;

    float dragOffsetY = 0.0f;

};