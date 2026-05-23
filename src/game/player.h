#pragma once

//
// ======================================================
// Classe Player
// ======================================================
//
// Representa o jogador principal.
//
// Atualmente o Player possui:
//
// - posição
// - velocidade
// - movimentação
//
// Futuramente poderá incluir:
//
// - animação
// - colisão
// - vida
// - inventário
// - estados
// - ataque
// - interação
//
class Player
{
public:

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza lógica do jogador.
    //
    // Parâmetros:
    //
    // deltaTime
    // → tempo entre frames
    //
    // up/down/left/right
    // → estados do teclado
    //
    void update(
        float deltaTime,
        bool up,
        bool down,
        bool left,
        bool right
    );

    //
    // ==================================================
    // getX()
    // ==================================================
    //
    // Retorna posição horizontal do player.
    //
    float getX();

    //
    // ==================================================
    // getY()
    // ==================================================
    //
    // Retorna posição vertical do player.
    //
    float getY();

private:

    //
    // ==================================================
    // Posição do player
    // ==================================================
    //

    //
    // Coordenada horizontal.
    //
    float x = 100.0f;

    //
    // Coordenada vertical.
    //
    float y = 100.0f;

    //
    // ==================================================
    // Velocidade
    // ==================================================
    //
    // Velocidade de movimentação do jogador.
    //
    float speed = 300.0f;
};