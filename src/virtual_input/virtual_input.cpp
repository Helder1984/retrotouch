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
// Atualiza estado do botão virtual.
//
void VirtualInput::setButton(
    VirtualButton button,
    bool pressed
)
{
    switch (button)
    {
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

        case VirtualButton::A:
            a = pressed;
            break;

        case VirtualButton::B:
            b = pressed;
            break;

        case VirtualButton::START:
            start = pressed;
            break;

        case VirtualButton::SELECT:
            select = pressed;
            break;

        default:
            break;
    }
}

//
// ======================================================
// VirtualInput::isPressed()
// ======================================================
//
// Retorna estado do botão.
//
bool VirtualInput::isPressed(VirtualButton button)
{
    switch (button)
    {
        case VirtualButton::UP:
            return up;

        case VirtualButton::DOWN:
            return down;

        case VirtualButton::LEFT:
            return left;

        case VirtualButton::RIGHT:
            return right;

        case VirtualButton::A:
            return a;

        case VirtualButton::B:
            return b;

        case VirtualButton::START:
            return start;

        case VirtualButton::SELECT:
            return select;

        default:
            return false;
    }
}