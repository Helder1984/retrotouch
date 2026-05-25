#pragma once

#include "overlay.h"
#include "../input/input.h"
#include "../virtual_input/virtual_input.h"

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
    // Define posição do botão.
    //
    void setPosition(
        float newX,
        float newY
    );

private:

    //
    // ==================================================
    // Posição na tela
    // ==================================================
    //
    // IMPORTANTE:
    //
    // Coordenadas da TELA.
    //
    float x;
    float y;

    //
    // Tamanho do botão.
    //
    int width;
    int height;

    //
    // Cor do botão.
    //
    Uint8 r;
    Uint8 g;
    Uint8 b;

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
};