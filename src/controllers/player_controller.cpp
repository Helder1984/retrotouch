#include "player_controller.h"

//
// ======================================================
// PlayerController::update()
// ======================================================
//
// Responsável por:
//
// - ler input
// - converter input em movimento
// - mover a entidade do jogador
//
// Agora o teclado NÃO pertence mais à Entity.
//
// Isso desacopla:
//
// input
// da
// lógica da entidade
//
void PlayerController::update(
    Entity& player,
    Input& input,
    float deltaTime
)
{
    //
    // Velocidade de movimentação.
    //
    float speed = 300.0f;

    //
    // ==================================================
    // Movimento para cima
    // ==================================================
    //
    if (input.up)
    {
        player.move(
            0,
            -speed * deltaTime
        );
    }

    //
    // ==================================================
    // Movimento para baixo
    // ==================================================
    //
    if (input.down)
    {
        player.move(
            0,
            speed * deltaTime
        );
    }

    //
    // ==================================================
    // Movimento para esquerda
    // ==================================================
    //
    if (input.left)
    {
        player.move(
            -speed * deltaTime,
            0
        );
    }

    //
    // ==================================================
    // Movimento para direita
    // ==================================================
    //
    if (input.right)
    {
        player.move(
            speed * deltaTime,
            0
        );
    }
}