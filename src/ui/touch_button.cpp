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
// Atualiza:
//
// - clique
// - multitouch
// - virtual input
//
void TouchButton::update(float deltaTime)
{
    //
    // Segurança.
    //
    if (!virtualInput)
    {
        return;
    }

    //
    // ==================================================
    // Mouse fallback
    // ==================================================
    //
    // Permite testar touch
    // no desktop.
    //
    float mouseX;
    float mouseY;

    //
    // Obtém estado do mouse.
    //
    Uint32 mouseState =
        SDL_GetMouseState(
            &mouseX,
            &mouseY
        );

    //
    // Botão esquerdo pressionado.
    //
    bool mousePressed =
        mouseState & SDL_BUTTON_LMASK;

    //
    // Mouse dentro do botão.
    //
    bool mouseInside =
        mouseX >= x &&
        mouseX <= x + width &&
        mouseY >= y &&
        mouseY <= y + height;

    //
    // ==================================================
    // Touch real
    // ==================================================
    //
    bool touchPressed = false;

    //
    // Verifica multitouch.
    //
    if (touchManager)
    {
        touchPressed =
            touchManager->isTouching(
                x,
                y,
                width,
                height
            );
    }

    //
    // ==================================================
    // Resultado final
    // ==================================================
    //
    bool pressed =
        touchPressed ||
        (mousePressed && mouseInside);

    //
    // Atualiza estado visual.
    //
    isPressed = pressed;

    //
    // Atualiza VirtualInput.
    //
    virtualInput->setButton(
        virtualButton,
        pressed
    );
}

//
// ======================================================
// TouchButton::render()
// ======================================================
//
// Renderiza botão virtual.
//
void TouchButton::render(
    Renderer& renderer
)
{
    //
    // ==================================================
    // Cor final
    // ==================================================
    //
    Uint8 finalR = r;

    Uint8 finalG = g;

    Uint8 finalB = b;

    //
    // Feedback visual.
    //
    if (isPressed)
    {
        finalR = 255;

        finalG = 255;

        finalB = 255;
    }

    //
    // Renderiza botão na tela.
    //
    renderer.drawScreenRect(
        x,
        y,
        width,
        height,
        finalR,
        finalG,
        finalB
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

//
// ======================================================
// TouchButton::setTouchManager()
// ======================================================
//
// Define sistema multitouch.
//
void TouchButton::setTouchManager(
    TouchManager* newTouchManager
)
{
    touchManager = newTouchManager;
}

//
// ======================================================
// TouchButton::setColor()
// ======================================================
//
// Define cor do botão.
//
void TouchButton::setColor(
    Uint8 newR,
    Uint8 newG,
    Uint8 newB
)
{
    r = newR;

    g = newG;

    b = newB;
}

//
// ======================================================
// TouchButton::setSize()
// ======================================================
//
// Define tamanho do botão.
//
void TouchButton::setSize(
    int newWidth,
    int newHeight
)
{
    width = newWidth;

    height = newHeight;
}