#pragma once

//
// ======================================================
// Inclusões necessárias
// ======================================================
//
// Input:
// contém estados do teclado.
//
// Entity:
// objeto que será controlado.
//
#include "../input/input.h"
#include "../game/entity.h"

//
// ======================================================
// Classe PlayerController
// ======================================================
//
// Responsável por:
//
// - ler input
// - interpretar comandos
// - controlar o player
//
// IMPORTANTE:
//
// O controller NÃO desenha.
//
// O controller NÃO pertence ao renderer.
//
// Ele apenas transforma input em ações.
//
// Arquitetura:
//
// Input
//   ↓
// PlayerController
//   ↓
// Entity
//
class PlayerController
{
public:

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza controle do jogador.
    //
    // Parâmetros:
    //
    // player
    // → entidade controlada
    //
    // input
    // → estado atual do teclado
    //
    // deltaTime
    // → tempo entre frames
    //
    void update(Entity& player, Input& input, float deltaTime);
};