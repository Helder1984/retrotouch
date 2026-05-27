#include "player_controller.h"

//
// ======================================================
// PlayerController::update()
// ======================================================
//
// Controla movimentação do player
// usando VirtualInput.
//
void PlayerController::update(
    Entity& entity,
    Input* keyboardInput,
    VirtualInput& virtualInput,
    float deltaTime
)
{
    //
    // ==================================================
    // UP
    // ==================================================
    bool up =
        virtualInput.getButton(
            VirtualButton::UP
        );

    if (keyboardInput)
    {
        up =
            up ||
            keyboardInput->up;
    }

    if (up)
    {
        entity.move(
            0,
            -200 * deltaTime
        );
    }

    //
    // ==================================================
    // DOWN
    // ==================================================
    bool down =
        virtualInput.getButton(
            VirtualButton::DOWN
        );

    if (keyboardInput)
    {
        down =
            down ||
            keyboardInput->down;
    }

    if (down)
    {
        entity.move(
            0,
            200 * deltaTime
        );
    }

    //
    // ==================================================
    // LEFT
    // ==================================================
    bool left =
        virtualInput.getButton(
            VirtualButton::LEFT
        );

    if (keyboardInput)
    {
        left =
            left ||
            keyboardInput->left;
    }

    if (left)
    {
        entity.move(
            -200 * deltaTime,
            0
        );
    }

    //
    // ==================================================
    // RIGHT
    // ==================================================
    bool right =
        virtualInput.getButton(
            VirtualButton::RIGHT
        );

    if (keyboardInput)
    {
        right =
            right ||
            keyboardInput->right;
    }

    if (right)
    {
        entity.move(
            200 * deltaTime,
            0
        );
    }

    //
    // ==================================================
    // Button A
    // ==================================================
    //
    // Muda cor do player.
    //
    bool aPressed =
        virtualInput.getButton(
            VirtualButton::A
        );

    if (aPressed)
    {
        entity.setColor(
            0,
            255,
            0
        );
    }
    else
    {
        //
        // Cor padrão.
        //
        entity.setColor(
            255,
            255,
            255
        );
    }
}