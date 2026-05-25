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
    VirtualInput& virtualInput,
    float deltaTime
)
{
    //
    // Movimento vertical.
    //
    if (virtualInput.isPressed(VirtualButton::UP))
    {
        entity.moveUp(deltaTime);
    }

    if (virtualInput.isPressed(VirtualButton::DOWN))
    {
        entity.moveDown(deltaTime);
    }

    //
    // Movimento horizontal.
    //
    if (virtualInput.isPressed(VirtualButton::LEFT))
    {
        entity.moveLeft(deltaTime);
    }

    if (virtualInput.isPressed(VirtualButton::RIGHT))
    {
        entity.moveRight(deltaTime);
    }
}