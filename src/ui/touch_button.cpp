#include "touch_button.h"

//
// ======================================================
// TouchButton::TouchButton()
// ======================================================
//
// Inicializa botão virtual.
//
TouchButton::TouchButton()
{
    //
    // ==================================================
    // Posição na tela
    // ==================================================
    //
    // Canto inferior esquerdo.
    //
    x = 50;

    y = 500;

    //
    // Tamanho.
    //
    width = 100;

    height = 100;

    //
    // Cor azul.
    //
    r = 0;
    g = 120;
    b = 255;

    //
    // Estado inicial.
    //
    isPressed = false;
}

//
// ======================================================
// TouchButton::update()
// ======================================================
//
// Detecta:
//
// - hover
// - clique
// - toque
//
void TouchButton::update(float deltaTime)
{
    //
    // Segurança.
    //
    if (!input)
    {
        return;
    }

    //
    // ==================================================
    // Mouse collision
    // ==================================================
    //
    bool insideX =
        input->mouseX >= x &&
        input->mouseX <= x + width;

    bool insideY =
        input->mouseY >= y &&
        input->mouseY <= y + height;

    //
    // Mouse dentro do botão.
    //
    bool hovering =
        insideX &&
        insideY;

    //
    // ==================================================
    // Clique
    // ==================================================
    //
    isPressed =
        hovering &&
        input->mouseLeft;

    //
    // ==================================================
    // Atualiza virtual input
    // ==================================================
    //
    // Envia estado do botão.
    //
    if (virtualInput)
    {
        virtualInput->setButton(
            virtualButton,
            isPressed
        );
    }

    //
    // ==================================================
    // Feedback visual
    // ==================================================
    //
    if (isPressed)
    {
        //
        // Azul claro.
        //
        r = 100;
        g = 180;
        b = 255;
    }
    else
    {
        //
        // Azul normal.
        //
        r = 0;
        g = 120;
        b = 255;
    }
}

//
// ======================================================
// TouchButton::render()
// ======================================================
//
// Renderiza botão na tela.
//
// IMPORTANTE:
//
// NÃO usa câmera.
//
// Isso é:
//
// SCREEN SPACE UI
//
void TouchButton::render(Renderer& renderer)
{
    //
    // Desenha botão diretamente na tela.
    //
    renderer.drawScreenRect(
        x,
        y,
        width,
        height,
        r,
        g,
        b
    );
}

//
// ======================================================
// TouchButton::setInput()
// ======================================================
//
// Define input.
//
void TouchButton::setInput(Input* newInput)
{
    input = newInput;
}

//
// ======================================================
// TouchButton::setVirtualInput()
// ======================================================
//
// Define virtual input.
//
void TouchButton::setVirtualInput(
    VirtualInput* newVirtualInput
)
{
    virtualInput = newVirtualInput;
}

//
// ======================================================
// TouchButton::setVirtualButton()
// ======================================================
//
// Define botão virtual.
//
void TouchButton::setVirtualButton(
    VirtualButton newButton
)
{
    virtualButton = newButton;
}

//
// ======================================================
// TouchButton::setPosition()
// ======================================================
//
// Define posição na tela.
//
void TouchButton::setPosition(
    float newX,
    float newY
)
{
    x = newX;

    y = newY;
}