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
#include "../virtual_input/virtual_input.h"
#include "../world/tilemap.h"

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
    
        void update(
            Entity& entity,
            Input* keyboardInput,
            VirtualInput& virtualInput,
            TileMap& tileMap,
            float deltaTime
        );

};