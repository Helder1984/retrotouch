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
    TileMap& tileMap,
    float deltaTime
)
{
    //
    // Velocidade do player.
    //
    float moveSpeed =
        200 * deltaTime;

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
        float nextX =
            entity.getX();

        float nextY =
            entity.getY() - moveSpeed;

        //
        // Move apenas se não houver colisão.
        //
        if (
            !tileMap.isColliding(
                nextX,
                nextY,
                entity.getWidth(),
                entity.getHeight()
            )
        )
        {
            entity.move(
                0,
                -moveSpeed
            );
        }
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
        float nextX =
            entity.getX();

        float nextY =
            entity.getY() + moveSpeed;

        if (
            !tileMap.isColliding(
                nextX,
                nextY,
                entity.getWidth(),
                entity.getHeight()
            )
        )
        {
            entity.move(
                0,
                moveSpeed
            );
        }
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
        float nextX =
            entity.getX() - moveSpeed;

        float nextY =
            entity.getY();

        if (
            !tileMap.isColliding(
                nextX,
                nextY,
                entity.getWidth(),
                entity.getHeight()
            )
        )
        {
            entity.move(
                -moveSpeed,
                0
            );
        }
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
        float nextX =
            entity.getX() + moveSpeed;

        float nextY =
            entity.getY();

        if (
            !tileMap.isColliding(
                nextX,
                nextY,
                entity.getWidth(),
                entity.getHeight()
            )
        )
        {
            entity.move(
                moveSpeed,
                0
            );
        }
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