#include "virtual_input.h"

//
// ======================================================
// VirtualInput::VirtualInput()
// ======================================================
//
// Inicializa estados.
//
VirtualInput::VirtualInput()
{
    up = false;

    down = false;

    left = false;

    right = false;

    a = false;

    b = false;

    start = false;

    select = false;
}

//
// ======================================================
// VirtualInput::setButton()
// ======================================================
//
// Atualiza estado de um botão virtual.
//
void VirtualInput::setButton(
    VirtualButton button,
    bool pressed
)
{
    switch (button)
    {
        //
        // Movimento.
        //
        case VirtualButton::UP:
            up = pressed;
            break;

        case VirtualButton::DOWN:
            down = pressed;
            break;

        case VirtualButton::LEFT:
            left = pressed;
            break;

        case VirtualButton::RIGHT:
            right = pressed;
            break;

        //
        // Ação.
        //
        case VirtualButton::A:
            a = pressed;
            break;

        case VirtualButton::B:
            b = pressed;
            break;

        //
        // Sistema.
        //
        case VirtualButton::START:
            start = pressed;
            break;

        case VirtualButton::SELECT:
            select = pressed;
            break;
    }
}

//
// ======================================================
// VirtualInput::isPressed()
// ======================================================
//
// Verifica estado de botão virtual.
//
bool VirtualInput::isPressed(
    VirtualButton button
)
{
    switch (button)
    {
        //
        // Movimento.
        //
        case VirtualButton::UP:
            return up;

        case VirtualButton::DOWN:
            return down;

        case VirtualButton::LEFT:
            return left;

        case VirtualButton::RIGHT:
            return right;

        //
        // Ação.
        //
        case VirtualButton::A:
            return a;

        case VirtualButton::B:
            return b;

        //
        // Sistema.
        //
        case VirtualButton::START:
            return start;

        case VirtualButton::SELECT:
            return select;
    }

    return false;
}